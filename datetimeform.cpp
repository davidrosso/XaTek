#include "datetimeform.h"

extern QString SystemDate;
extern QString SystemTime;

DateTimeForm::DateTimeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTimeForm)
{
    ui->setupUi(this);

    // insert tumbler widget into the form with transparent background settings
    ui->quickWidget->setSource(QUrl("qrc:/Resources/dateTimeModule.qml"));
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop, true);
    ui->quickWidget->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->quickWidget->setClearColor(Qt::transparent);

    QObject *tumblerItem = ui->quickWidget->rootObject();

    time_t currentTime = time(0);
    tm *ltm = localtime(&currentTime);

    QMetaObject::invokeMethod(tumblerItem, "setMonth", Q_ARG(QVariant, ltm->tm_mon));
    QMetaObject::invokeMethod(tumblerItem, "setDay", Q_ARG(QVariant, ltm->tm_mday));
    QMetaObject::invokeMethod(tumblerItem, "setHour", Q_ARG(QVariant, ltm->tm_hour));
    QMetaObject::invokeMethod(tumblerItem, "setMinute", Q_ARG(QVariant, ltm->tm_min));

    QObject::connect(tumblerItem,SIGNAL(updateMonth(QString)),this,SLOT(updateMonth(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateDay(QString)),this,SLOT(updateDay(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateHour(QString)),this,SLOT(updateHour(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateMinute(QString)),this,SLOT(updateMinute(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateTimezone(QString)),this,SLOT(updateTimezone(QString)));

    month = QString::number(ltm->tm_mon);
    day = QString::number(ltm->tm_mday);
    hour = QString::number(ltm->tm_hour);
    minute = QString::number(ltm->tm_min);
    timezone = "";

    updateMonth(month);
    updateDay(day);
    updateHour(hour);
    updateMinute(minute);
    updateTimezone(timezone);
}

DateTimeForm::~DateTimeForm()
{
    delete ui;
}

void DateTimeForm::updateMonth(QString in)
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

void DateTimeForm::updateDay(QString in)
{
    day = in.toUtf8();
}

void DateTimeForm::updateHour(QString in)
{
    hour = in.toUtf8();
}

void DateTimeForm::updateMinute(QString in)
{
    minute = in.toUtf8();
}

void DateTimeForm::updateTimezone(QString in)
{
    timezone = in.toUtf8();
}

void DateTimeForm::on_buttonBack_clicked()
{
    // return to the Setting Screen
    emit SettingsOptionsClicked();
}

void DateTimeForm::on_buttonEnter_clicked()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // GUI will permit user to set time, date, and time-zone.
    QProcess myProcess;

    //Saving date to system
    if(month != "" && day != "" && hour!= "" && minute != "")
    {
        if(month.toInt() < 10)
        {
            month = "0" + month;
        }
        if(day.toInt() < 10)
        {
            day = "0" + day;
        }

        //TODO Replace hard coded year when updating wireframes for dateTime.
        QString processString = "date --set=\"2019" + month + day + " " + hour + ":" + minute;
        myProcess.start(processString);
        myProcess.waitForFinished(-1);
        myProcess.close();

        emit SettingsOptionsClicked();
    }
}
