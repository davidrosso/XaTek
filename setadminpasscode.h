#ifndef SETADMINPASSCODE_H
#define SETADMINPASSCODE_H

#include <QWidget>
#include <QMessageBox>
#include <QtXml>
#include <QFile>
#include <QDebug>
#include <QCryptographicHash>
#include "ui_setadminpasscode.h"

namespace Ui {
class SetAdminPasscode;
}

class SetAdminPasscode : public QWidget
{
    Q_OBJECT

public:
    explicit SetAdminPasscode(QWidget *parent = nullptr);
    ~SetAdminPasscode();

private:
    Ui::SetAdminPasscode *ui;
    QString passcodeFirstEntry = "";
    QString passcodeSecondEntry = "";

private slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_button0_clicked();
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();
    void UpdateAdminPasscode();

signals:
    void SettingsOptionsClicked();
};

#endif // SETADMINPASSCODE_H
