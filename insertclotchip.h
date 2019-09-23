#ifndef INSERTCLOTCHIP_H
#define INSERTCLOTCHIP_H

#include <QWidget>
#include <QDialog>
#include <QMovie>
#include <QDebug>
#include "setuserid.h"
#include "ui_insertclotchip.h"

namespace Ui {
class InsertClotChip;
}

class InsertClotChip : public QWidget
{
    Q_OBJECT

public:
    explicit InsertClotChip(QWidget *parent = 0);
    ~InsertClotChip();

private:
    Ui::InsertClotChip *ui;   
    SetUserID _setUserID;

private slots:    
    void on_buttonNext_clicked();
    void on_buttonBack_clicked();    
    void InsertClotChip_click();
    void goingToPasscode();

signals:
    void SettingsOptionsClicked();
    void OpenScanClotChip();
    void goToPasscode();

};

#endif // INSERTCLOTCHIP_H
