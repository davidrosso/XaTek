#include "passcodeunlock.h"
#include "ui_passcodeunlock.h"
#include <qmessagebox.h>

PasscodeUnlock::PasscodeUnlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasscodeUnlock)
{
    ui->setupUi(this);

    //TODO: get the admin passcode value from firmware, for now just set to "0000"
    //GetAdminPasscode();
    adminPasscode = 0000;

    //TODO: get the user passcode value from firmware, for now just set to "1111"
    //GetUserPasscode();
    userPasscode = 1111;

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_homeScreen);
    ui->stackedWidget->insertWidget(2, &_settingOptionsForm);
}

PasscodeUnlock::~PasscodeUnlock()
{
    delete ui;
}

void PasscodeUnlock::on_button1_clicked()
{
    checkPasscode("1");
}

void PasscodeUnlock::on_button2_clicked()
{
    checkPasscode("2");
}

void PasscodeUnlock::on_button3_clicked()
{
    checkPasscode("3");
}

void PasscodeUnlock::on_button4_clicked()
{
    checkPasscode("4");
}

void PasscodeUnlock::on_button5_clicked()
{
    checkPasscode("5");
}

void PasscodeUnlock::on_button6_clicked()
{
    checkPasscode("6");
}

void PasscodeUnlock::on_button7_clicked()
{
    checkPasscode("7");
}

void PasscodeUnlock::on_button8_clicked()
{
    checkPasscode("8");
}

void PasscodeUnlock::on_button9_clicked()
{
    checkPasscode("9");
}

void PasscodeUnlock::on_button0_clicked()
{
    checkPasscode("0");
}

void PasscodeUnlock::checkPasscode(QString valueEntered)
{
      QString enteredPasscodeStr = QString::number(enteredPasscode);
      int len = enteredPasscodeStr.length();

      if(len == 8)
      {
          // remove the first value
          enteredPasscodeStr.remove(0,1);
      }

      enteredPasscodeStr.append(valueEntered);
      enteredPasscode = enteredPasscodeStr.toInt();

//      if(enteredPasscode == adminPasscode || enteredPasscode == userPasscode)
//      {
//          QMessageBox::information( this, tr("Matched"), "Success");

//          moveHomeScreen();
//      }
//      else
//      {
//          //QString mm = QString("sss: %d"), enteredPasscode;
//          //QMessageBox::information( this, tr("No Match"), mm);
//      }
}

void PasscodeUnlock::moveHomeScreen()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void PasscodeUnlock::on_buttonBack_clicked()
{    
    //TODO: return to previous screen
}

void PasscodeUnlock::on_buttonUnlock_clicked()
{
    moveHomeScreen();

//    if(enteredPasscode == adminPasscode || enteredPasscode == userPasscode)
//    {
//        moveHomeScreen();
//    }
//    else
//    {
//        QMessageBox::information( this, tr("Invalid Pascode"), "Cannot Unlock");
//    }
}
