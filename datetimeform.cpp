#include "datetimeform.h"
#include "ui_datetimeform.h"
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
    QObject::connect(tumblerItem,SIGNAL(updateMonth(QString)),this,SLOT(updateMonth(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateDay(QString)),this,SLOT(updateDay(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateHour(QString)),this,SLOT(updateHour(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateMinute(QString)),this,SLOT(updateMinute(QString)));
    QObject::connect(tumblerItem,SIGNAL(updateTimezone(QString)),this,SLOT(updateTimezone(QString)));

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
    qDebug() << "Month: " << in.toUtf8();    
    //TODO Save the data here
}

void DateTimeForm::updateDay(QString in)
{
    qDebug() << "Day: " << in.toUtf8();
    //TODO Save the data here
}

void DateTimeForm::updateHour(QString in)
{
    qDebug() << "Hour: " << in.toUtf8();
    //TODO Save the data here
}

void DateTimeForm::updateMinute(QString in)
{
    qDebug() << "Minute: " << in.toUtf8();
    //TODO Save the data here
}

void DateTimeForm::updateTimezone(QString in)
{
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
    // return to the Setting Screen for now
    emit SettingsOptionsClicked();
}

























