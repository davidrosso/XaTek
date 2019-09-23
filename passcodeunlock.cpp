#include "passcodeunlock.h"

extern QString AdminPasscode;
extern QString UserPasscode;

PasscodeUnlock::PasscodeUnlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasscodeUnlock)
{
    ui->setupUi(this);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_homeScreen);
    //ui->stackedWidget->insertWidget(2, &_settingOptionsForm);
}

PasscodeUnlock::~PasscodeUnlock()
{
    delete ui;
}

void PasscodeUnlock::on_button1_clicked()
{
    updateEnteredPasscode("1");
}

void PasscodeUnlock::on_button2_clicked()
{
    updateEnteredPasscode("2");
}

void PasscodeUnlock::on_button3_clicked()
{
    updateEnteredPasscode("3");
}

void PasscodeUnlock::on_button4_clicked()
{
    updateEnteredPasscode("4");
}

void PasscodeUnlock::on_button5_clicked()
{
    updateEnteredPasscode("5");
}

void PasscodeUnlock::on_button6_clicked()
{
    updateEnteredPasscode("6");
}

void PasscodeUnlock::on_button7_clicked()
{
    updateEnteredPasscode("7");
}

void PasscodeUnlock::on_button8_clicked()
{
    updateEnteredPasscode("8");
}

void PasscodeUnlock::on_button9_clicked()
{
    updateEnteredPasscode("9");
}

void PasscodeUnlock::on_button0_clicked()
{
    updateEnteredPasscode("0");
}

void PasscodeUnlock::updateEnteredPasscode(QString valueEntered)
{
    // passcode cannot be greater that 8 digits,
    int len = enteredPasscode.length();
    if(len == 8)
    {
        // remove the first digit
        enteredPasscode.remove(0,1);
    }

    // append entered value to the end of the string
    enteredPasscode.append(valueEntered);
}

void PasscodeUnlock::moveHomeScreen()
{
    qDebug() << "Moving to Home Screen";
    ui->stackedWidget->setCurrentIndex(1);
}

void PasscodeUnlock::on_buttonUnlock_clicked()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // Software will require users to enter a passcode to unlock the home screen.

    //qDebug() << "Admin_Passcode: " + AdminPasscode;
    //qDebug() << "User_Passcode: " + UserPasscode;

    // check that the entered passcode is either the admin passcode or the user passcode
    if(enteredPasscode == AdminPasscode || enteredPasscode == UserPasscode)
    {
        moveHomeScreen();
    }
    else
    {
        QMessageBox::information( this, tr("Invalid Pascode"), "The passcode that was entered is not valid.\n\nPlease enter passcode to unlock the device or contact administrator.");

        // reset the entered passcode
        enteredPasscode = "";
    }
}
