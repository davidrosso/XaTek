#include "setuserpasscode.h"
#include "ui_setuserpasscode.h"
#include <QMessageBox>

SetUserPasscode::SetUserPasscode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUserPasscode)
{
    ui->setupUi(this);

    // TODO: get the current admin passcode from the firmware
    // return the user passcode
    //string GetUserPasscode();

    passcodeFirstAttempt = "";
    passcodeConfirmation = "";
    ui->lineEditPasscode->setText("");
    ui->labelTitle->setText("Enter Admin Passcode");
}

SetUserPasscode::~SetUserPasscode()
{
    delete ui;
}

void SetUserPasscode::on_button1_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "1");
}

void SetUserPasscode::on_button2_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "2");
}

void SetUserPasscode::on_button3_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "3");
}

void SetUserPasscode::on_button4_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "4");
}

void SetUserPasscode::on_button5_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "5");
}

void SetUserPasscode::on_button6_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "6");
}

void SetUserPasscode::on_button7_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "7");
}

void SetUserPasscode::on_button8_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "8");
}

void SetUserPasscode::on_button9_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "9");
}

void SetUserPasscode::on_button0_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "0");
}

void SetUserPasscode::on_buttonBack_clicked()
{
    passcodeFirstAttempt = "";
    passcodeConfirmation = "";
    ui->lineEditPasscode->setText("");
    ui->labelTitle->setText("Enter Admin Passcode");

    // return to the Setting Screen
    emit SettingsOptionsClicked();
}

void SetUserPasscode::on_buttonEnter_clicked()
{
    if(ui->lineEditPasscode->text().length() < 4)
    {
        QMessageBox::information(
          this,
          tr("Invalid Admin Passcode"),
          tr("Passcodes must be a minumum or 4 digits.") );
    }
    else
    {
        if (passcodeFirstAttempt == "")
        {
            passcodeFirstAttempt = ui->lineEditPasscode->text();
            ui->lineEditPasscode->setText("");
            ui->labelTitle->setText("Reenter Admin Passcode");
        }
        else
        {
            passcodeConfirmation = ui->lineEditPasscode->text();
            ui->lineEditPasscode->setText("");

            if(passcodeFirstAttempt == passcodeConfirmation)
            {
                QMessageBox::information(
                  this,
                  tr("Admin Passcode Created"),
                  tr("The Admin passcode was successfully created.") );

                // TODO: same this new admin passcode to the firmware                
                // set the new user passcode
                //SetUserPasscode (passcodeConfirmation);

                // return to the Setting Screen
                emit SettingsOptionsClicked();
            }
            else
            {
                QMessageBox::information(
                  this,
                  tr("Passcodes do not match"),
                  tr("The passcodes entered do not match. Please start again.") );

                passcodeFirstAttempt = "";
                passcodeConfirmation = "";
                ui->lineEditPasscode->setText("");
                ui->labelTitle->setText("Enter Admin Passcode");

            }
        }
    }
}

