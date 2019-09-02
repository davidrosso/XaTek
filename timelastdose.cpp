#include "timelastdose.h"
#include "ui_timelastdose.h"
#include "mainwindow.h"
#include <QAbstractItemView>
#include <QDateTime>
#include <QPushButton>
#include <QVBoxLayout>
#include <QQmlApplicationEngine>
#include <QScopedPointer>
#include <qabstractitemview.h>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QMessageBox>
#include <QDate>
#include <QDebug>

extern QString PreviousScreen;
extern QString TestData_DateTimeLastDose;
extern QString TestData_HoursSinceLastDose;

TimeLastDose::TimeLastDose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeLastDose)
{
    ui->setupUi(this);

    // insert tumbler widget into the form with transparent background settings
    ui->quickWidget->setSource(QUrl("qrc:/Resources/doseDateTime.qml"));
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop, true);
    ui->quickWidget->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->quickWidget->setClearColor(Qt::transparent);

    time_t currentTime = time(0);
    tm *ltm = localtime(&currentTime);

    QObject *tumblerItem = ui->quickWidget->rootObject();

    QMetaObject::invokeMethod(tumblerItem, "setMonth", Q_ARG(QVariant, ltm->tm_mon));
    QMetaObject::invokeMethod(tumblerItem, "setDay", Q_ARG(QVariant, ltm->tm_mday));
    QMetaObject::invokeMethod(tumblerItem, "setHour", Q_ARG(QVariant, ltm->tm_hour));
    QMetaObject::invokeMethod(tumblerItem, "setMinute", Q_ARG(QVariant, ltm->tm_min));
    QMetaObject::invokeMethod(tumblerItem, "setTimezone", Q_ARG(QVariant, ltm->tm_mon));

    QObject::connect(tumblerItem,SIGNAL(updateMonth(QString)),this,SLOT(updateMonth(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateDay(QString)),this,SLOT(updateDay(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateHour(QString)),this,SLOT(updateHour(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateMinute(QString)),this,SLOT(updateMinute(QString)));

    //TODO: set month, day, hour, minute variable
    //TODO: month =
    //TODO: day =
    //TODO: hour =`
    //TODO: minute =

    month = ltm->tm_mon;
    day = ltm->tm_mday;
    hour = ltm->tm_hour;
    minute = ltm->tm_min;


    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_preparePatient);

    connect(&_preparePatient, SIGNAL(TimeLastDose()), this, SLOT(TimeLastDose_click()));
}

TimeLastDose::~TimeLastDose()
{
    delete ui;
}

void TimeLastDose::updateMonth(QString in)
{
    //qDebug() << "Month: " << in.toUtf8();
    //TODO Save the data here
    month = in.toUtf8();

    if(month == "January")
        monthInt = 1;
    else if(month == "February")
        monthInt = 2;
    else if(month == "March")
        monthInt = 3;
    else if(month == "April")
        monthInt = 4;
    else if(month == "May")
        monthInt = 5;
    else if(month == "June")
        monthInt = 6;
    else if(month == "July")
        monthInt = 7;
    else if(month == "August")
        monthInt = 8;
    else if(month == "September")
        monthInt = 9;
    else if(month == "October")
        monthInt = 10;
    else if(month == "November")
        monthInt = 11;
    else if(month == "December")
        monthInt = 12;

}

void TimeLastDose::updateDay(QString in)
{
    //qDebug() << "Day: " << in.toUtf8();
    //TODO Save the data here
    day = in;
}

void TimeLastDose::updateHour(QString in)
{
    //qDebug() << "Hour: " << in.toUtf8();
    //TODO Save the data here
    hour = in;
}

void TimeLastDose::updateMinute(QString in)
{
    //qDebug() << "Minute: " << in.toUtf8();
    //TODO Save the data here
    minute = in;
}

void TimeLastDose::on_buttonBack_clicked()
{
    // return to the previous screen (SetPatientID)
    emit SetPatientID();
}

void TimeLastDose::TimeLastDose_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void TimeLastDose::on_buttonEnter_clicked()
{
    // set PreviousScreen variable
    PreviousScreen = "TimeLastDose";
    qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will permit users to enter the time of last dose.

    // check that date and time are set on the tumblers
    if(month != "" && day != "" && hour!= "" && minute != "")
    {
        // set the DateTimeOfLastDose variable to the entered values on the tumblers
        QDate d1(2019, monthInt, day.toInt());
        DateTimeOfLastDose.setDate(d1);

        QTime t1(hour.toInt(), minute.toInt(), 0);
        DateTimeOfLastDose.setTime(t1);

        // check that the last dose date/time is not after the current date/time
        if(DateTimeOfLastDose > QDateTime::currentDateTime())
        {
            // invalid last dose date/time
            QMessageBox::information(this, "Last Dose Invalid",
                QString("Last Dose cannot be greater than the current Date/Time.\nPlease re-enter the Last Dose Date/Time"));
        }
        else
        {
            QString format = "yyyy-MM-dd HH:mm:ss";
            QDateTime lastDose = QDateTime::fromString(DateTimeOfLastDose.toString(format), format);
            QDateTime current = QDateTime::fromString(QDateTime::currentDateTime().toString(format), format);

            TestData_DateTimeLastDose = lastDose.toString(format);
            TestData_HoursSinceLastDose = secondsToString(lastDose.secsTo(current));;

            //qDebug() << "last dose: " + lastDose.toString(format);
            //qDebug() << "current: " + current.toString(format);
            //qDebug() << "diff: " + secondsToString(lastDose.secsTo(current));
            //qDebug() << "TestData_HoursSinceLastDose: " + TestData_HoursSinceLastDose;

            ui->stackedWidget->setCurrentIndex(1);
        }
    }
}

QString TimeLastDose::secondsToString(qint64 seconds)
{
    const qint64 DAY = 86400;
    qint64 days = seconds / DAY;
    QTime t = QTime(0,0).addSecs(seconds % DAY);

    // calculate and return total hours
    qint64 TotalHours = (days * 24) + t.hour();

    return QString("%1").arg(TotalHours);
    //return QString("%1 days, %2 hours, %3 minutes, %4 seconds").arg(days).arg(t.hour()).arg(t.minute()).arg(t.second());
}

