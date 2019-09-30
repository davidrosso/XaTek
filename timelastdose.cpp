#include "timelastdose.h"

extern QString PreviousScreen;
extern QString DateTimeFormat;
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

    QObject::connect(tumblerItem,SIGNAL(updateMonth(QString)),this,SLOT(updateMonth(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateDay(QString)),this,SLOT(updateDay(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateHour(QString)),this,SLOT(updateHour(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateMinute(QString)),this,SLOT(updateMinute(QString)));

    month = QString::number(ltm->tm_mon +1);
    day = QString::number(ltm->tm_mday);
    hour = QString::number(ltm->tm_hour);
    minute = QString::number(ltm->tm_min);

    updateMonth(month);
    updateDay(day);
    updateHour(hour);
    updateMinute(minute);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_preparePatient);

    connect(&_preparePatient, SIGNAL(TimeLastDose()), this, SLOT(TimeLastDose_click()));
    connect(&_preparePatient, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
}

TimeLastDose::~TimeLastDose()
{
    delete ui;
}

void TimeLastDose::updateMonth(QString in)
{
    if(in == "January")
        month = "1";
    else if(in == "February")
        month = "2";
    else if(in == "March")
        month = "3";
    else if(in == "April")
        month = "4";
    else if(in == "May")
        month = "5";
    else if(in == "June")
        month = "6";
    else if(in == "July")
        month = "7";
    else if(in == "August")
        month = "8";
    else if(in == "September")
        month = "9";
    else if(in == "October")
        month = "10";
    else if(in == "November")
        month = "11";
    else if(in == "December")
        month = "12";

}

void TimeLastDose::updateDay(QString in)
{
    day = in;
}

void TimeLastDose::updateHour(QString in)
{
    hour = in;
}

void TimeLastDose::updateMinute(QString in)
{
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
        QDate d1(2019, month.toInt(), day.toInt());
        DateTimeOfLastDose.setDate(d1);

        QTime t1(hour.toInt(), minute.toInt(), 0);
        DateTimeOfLastDose.setTime(t1);
        qDebug() << "DateTimeOfLastDose: " + DateTimeOfLastDose.toString(DateTimeFormat);

        // check that the last dose date/time is not after the current date/time
        if(DateTimeOfLastDose > QDateTime::currentDateTime())
        {
            // invalid last dose date/time
            QMessageBox::information(this, "Last Dose Invalid",
                QString("Last Dose cannot be greater than the current Date/Time.\nPlease re-enter the Last Dose Date/Time"));
        }
        else
        {
            QDateTime lastDose = QDateTime::fromString(DateTimeOfLastDose.toString(DateTimeFormat), DateTimeFormat);
            QDateTime current = QDateTime::fromString(QDateTime::currentDateTime().toString(DateTimeFormat), DateTimeFormat);

            TestData_DateTimeLastDose = lastDose.toString(DateTimeFormat);
            TestData_HoursSinceLastDose = secondsToString(lastDose.secsTo(current));;

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
}

void TimeLastDose::goingToPasscode()
{
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}

