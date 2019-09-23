#ifndef SETPATIENTID_H
#define SETPATIENTID_H

#include <QWidget>
#include <QDebug>
#include "keyboard.h"
#include "timelastdose.h"
#include "ui_setpatientid.h"

namespace Ui {
class SetPatientID;
}

class SetPatientID : public QWidget
{
    Q_OBJECT

public:
    explicit SetPatientID(QWidget *parent = 0);
    ~SetPatientID();

private:
    Ui::SetPatientID *ui;
    TimeLastDose _timeLastDose;
    Keyboard _keyboard;

private slots:
    void on_buttonScan_clicked();
    void on_buttonManual_clicked();
    void on_buttonBack_clicked();
    void SetPatientID_click();
    void goingToPasscode();

signals:
    void SettingsOptionsClicked();
    void SetUserID();
    void goToPasscode();

};

#endif // SETPATIENTID_H
