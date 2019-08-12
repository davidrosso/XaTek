#ifndef SETUSERID_H
#define SETUSERID_H

#include <QWidget>
#include <setpatientid.h>
#include <keyboard.h>

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

signals:    
    void SettingsOptionsClicked();
    void InsertClotChip();

};

#endif // SETUSERID_H
