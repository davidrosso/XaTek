#include "datetimeform.h"

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
    QMetaObject::invokeMethod(tumblerItem, "setTimezone", Q_ARG(QVariant, ltm->tm_mon));

    QObject::connect(tumblerItem,SIGNAL(updateMonth(QString)),this,SLOT(updateMonth(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateDay(QString)),this,SLOT(updateDay(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateHour(QString)),this,SLOT(updateHour(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateMinute(QString)),this,SLOT(updateMinute(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateTimezone(QString)),this,SLOT(updateTimezone(QString)));

    month = ltm->tm_mon;
    day = ltm->tm_mday;
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    timezone = "";
}

DateTimeForm::~DateTimeForm()
{
    delete ui;
}

void DateTimeForm::updateSettings()
{
    //on_buttonReturnToSettings_clicked();
    //TODO: Not sure if we need this method.
}

void DateTimeForm::updateMonth(QString in)
{
    month = in.toUtf8();
    qDebug() << "Month: " << in.toUtf8();
    //TODO Save the data here
}

void DateTimeForm::updateDay(QString in)
{
    day = in.toUtf8();
    qDebug() << "Day: " << in.toUtf8();
    //TODO Save the data here
}

void DateTimeForm::updateHour(QString in)
{
    hour = in.toUtf8();
    qDebug() << "Hour: " << in.toUtf8();
    //TODO Save the data here
}

void DateTimeForm::updateMinute(QString in)
{
    minute = in.toUtf8();
    qDebug() << "Minute: " << in.toUtf8();
    //TODO Save the data here
}

void DateTimeForm::updateTimezone(QString in)
{
    timezone = in.toUtf8();
    qDebug() << "Timezone: " << in.toUtf8();
    //TODO Save the data here
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

    //TODO: set date/time on device using the tumbler settings
}

























