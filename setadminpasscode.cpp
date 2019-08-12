#include "setadminpasscode.h"
#include "ui_setadminpasscode.h"
#include <QMessageBox>

SetAdminPasscode::SetAdminPasscode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetAdminPasscode)
{
    ui->setupUi(this);

    // TODO: get the admin passcode from the firmware
    //string GetAdminPasscode();

    // TODO: get the current admin passcode from the firmware
    passcodeFirstAttempt = "";
    passcodeConfirmation = "";
    ui->lineEditPasscode->setText("");
    ui->labelAdminPasscode->setText("Enter Admin Passcode");

}

SetAdminPasscode::~SetAdminPasscode()
{
    delete ui;
}

void SetAdminPasscode::on_button1_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "1");
}

void SetAdminPasscode::on_button2_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "2");
}

void SetAdminPasscode::on_button3_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "3");
}

void SetAdminPasscode::on_button4_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "4");
}

void SetAdminPasscode::on_button5_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "5");
}

void SetAdminPasscode::on_button6_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "6");
}

void SetAdminPasscode::on_button7_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "7");
}

void SetAdminPasscode::on_button8_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "8");
}

void SetAdminPasscode::on_button9_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "9");
}

void SetAdminPasscode::on_button0_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "0");
}

void SetAdminPasscode::on_buttonBack_clicked()
{
    passcodeFirstAttempt = "";
    passcodeConfirmation = "";
    ui->lineEditPasscode->setText("");
    ui->labelAdminPasscode->setText("Enter Admin Passcode");

    //emit HomeClicked();
    emit SettingsOptionsClicked();
}

void SetAdminPasscode::on_buttonEnter_clicked()
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
            ui->labelAdminPasscode->setText("Reenter Admin Passcode");
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
                // set the new admin passcode
                //SetAdminPasscode (string);

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
                ui->labelAdminPasscode->setText("Enter Admin Passcode");

            }
        }
    }
}
