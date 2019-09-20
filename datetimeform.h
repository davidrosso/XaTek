#ifndef DATETIMEFORM_H
#define DATETIMEFORM_H

#include <QWidget>
#include <QModelIndexList>
#include <ctime>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QtQuick>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QDateTime>
#include <QPushButton>
#include <QVBoxLayout>
#include <QQmlApplicationEngine>
#include <QScopedPointer>
#include <qabstractitemview.h>

#include "ui_datetimeform.h"
//#include "mainwindow.h"

namespace Ui {
class DateTimeForm;
}

class DateTimeForm : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString saveMonth MEMBER month)
    Q_PROPERTY(QString saveDay MEMBER day)

public:
    explicit DateTimeForm(QWidget *parent = 0);
    ~DateTimeForm();
    QString month, day, hour, minute;
    QString timezone;

private:
    Ui::DateTimeForm *ui;
    QModelIndexList *indexes;
    //std::string timezone;

private slots:
    void updateSettings();
    void updateMonth(QString in);
    void updateDay(QString in);
    void updateHour(QString in);
    void updateMinute(QString in);
    void updateTimezone(QString in);
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();

signals:
    void SettingsOptionsClicked();    
    void timeDateUpdated();
};

#endif // DATETIMEFORM_H
