#ifndef SETUSERPASSCODE_H
#define SETUSERPASSCODE_H

#include <QWidget>
#include <QMessageBox>
#include "ui_setuserpasscode.h"
#include <QtXml>
#include <QFile>
#include <QDebug>

namespace Ui {
class SetUserPasscode;
}

class SetUserPasscode : public QWidget
{
    Q_OBJECT

public:
    explicit SetUserPasscode(QWidget *parent = 0);
    ~SetUserPasscode();

private:
    Ui::SetUserPasscode *ui;
    QString passcodeFirstEntry = "";
    QString passcodeSecondEntry = "";
    QXmlStreamReader xmlReader;

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
    void UpdateUserPasscode();

signals:
    void SettingsOptionsClicked();

};

#endif // SETUSERPASSCODE_H
