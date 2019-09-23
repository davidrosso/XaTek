#ifndef TIMELASTDOSE_H
#define TIMELASTDOSE_H

#include <QWidget>
#include <QModelIndexList>
#include <QDateTime>
#include <ctime>
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
#include <QDateEdit>
#include <QDebug>
#include "preparepatient.h"
#include "ui_timelastdose.h"

namespace Ui {
class TimeLastDose;
}

class TimeLastDose : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString saveMonth MEMBER month)
    Q_PROPERTY(QString saveDay MEMBER day)

public:
    explicit TimeLastDose(QWidget *parent = 0);
    ~TimeLastDose();
    QString month, day, hour, minute;
    QDateTime DateTimeOfLastDose;
    QDate dt1;
    int monthInt = 0;

private:
    Ui::TimeLastDose *ui;
    QModelIndexList *indexes;
    PreparePatient _preparePatient;

private slots:   
    void updateMonth(QString in);
    void updateDay(QString in);
    void updateHour(QString in);
    void updateMinute(QString in);    
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();
    void TimeLastDose_click();
    QString secondsToString(qint64);
    void goingToPasscode();

signals:
    void SettingsOptionsClicked();    
    void SetPatientID();
    void goToPasscode();

};

#endif // DATETIMEFORM_H
