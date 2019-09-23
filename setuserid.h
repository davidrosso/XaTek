#ifndef SETUSERID_H
#define SETUSERID_H

#include <QWidget>
#include <QDebug>
#include "setpatientid.h"
#include "keyboard.h"
#include "ui_setuserid.h"

namespace Ui {
class SetUserID;
}

class SetUserID : public QWidget
{
    Q_OBJECT

public:
    explicit SetUserID(QWidget *parent = 0);
    ~SetUserID();

private:
    Ui::SetUserID *ui;
    SetPatientID _setPatientID;    
    Keyboard _keyboard;

private slots:
    void on_buttonScan_clicked();
    void on_buttonManual_clicked();
    void on_buttonBack_clicked();
    void SetUserID_click();
    void goingToPasscode();

signals:    
    void SettingsOptionsClicked();
    void InsertClotChip();
    void goToPasscode();

};

#endif // SETUSERID_H
