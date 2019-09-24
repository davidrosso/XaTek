#include "keyboard.h"

extern QString PreviousScreen;
extern QString TestData_User_ID_Source;
extern QString TestData_User_ID;
extern QString TestData_Patient_ID_Source;
extern QString TestData_Patient_ID;

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    //ui->stackedWidget->insertWidget(4, &_timeLastDose);
}


Keyboard::~Keyboard()
{
    delete ui;
}

/*************************************/
/********** Numeric buttons **********/
/*************************************/
void Keyboard::on_button0_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "0");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "0");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "0");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "0");
}

void Keyboard::on_button1_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "1");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "1");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "1");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "1");
}

void Keyboard::on_button2_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "2");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "2");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "2");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "2");
}

void Keyboard::on_button3_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "3");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "3");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "3");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "3");
}

void Keyboard::on_button4_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "4");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "4");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "4");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "4");
}

void Keyboard::on_button5_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "5");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "5");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "5");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "5");
}

void Keyboard::on_button6_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "6");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "6");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "6");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "6");
}

void Keyboard::on_button7_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "7");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "7");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "7");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "7");
}

void Keyboard::on_button8_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "8");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "8");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "8");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "8");
}

void Keyboard::on_button9_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "9");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "9");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "9");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "9");
}

/*************************************/
/*** Alphabetic UPPER CASE buttons ***/
/*************************************/
void Keyboard::on_buttonUpperA_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "A");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "A");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "A");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "A");
}

void Keyboard::on_buttonUpperB_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "B");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "B");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "B");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "B");
}

void Keyboard::on_buttonUpperC_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "C");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "C");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "C");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "C");
}

void Keyboard::on_buttonUpperD_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "D");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "D");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "D");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "D");
}

void Keyboard::on_buttonUpperE_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "E");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "E");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "E");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "E");
}

void Keyboard::on_buttonUpperF_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "F");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "F");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "F");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "F");
}

void Keyboard::on_buttonUpperG_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "G");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "G");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "G");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "G");
}

void Keyboard::on_buttonUpperH_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "H");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "H");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "H");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "H");
}

void Keyboard::on_buttonUpperI_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "I");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "I");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "I");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "I");
}

void Keyboard::on_buttonUpperJ_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "J");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "J");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "J");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "J");
}

void Keyboard::on_buttonUpperK_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "K");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "K");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "K");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "K");
}

void Keyboard::on_buttonUpperL_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "L");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "L");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "L");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "L");
}

void Keyboard::on_buttonUpperM_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "M");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "M");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "M");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "M");
}

void Keyboard::on_buttonUpperN_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "N");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "N");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "N");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "N");
}

void Keyboard::on_buttonUpperO_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "O");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "O");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "O");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "O");
}

void Keyboard::on_buttonUpperP_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "P");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "P");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "P");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "P");
}

void Keyboard::on_buttonUpperQ_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "Q");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "Q");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "Q");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "Q");
}

void Keyboard::on_buttonUpperR_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "R");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "R");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "R");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "R");
}

void Keyboard::on_buttonUpperS_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "S");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "S");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "S");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "S");
}

void Keyboard::on_buttonUpperT_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "T");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "5T");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "T");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "T");
}

void Keyboard::on_buttonUpperU_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "U");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "5U");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "U");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "U");
}

void Keyboard::on_buttonUpperV_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "V");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "V");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "V");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "V");
}

void Keyboard::on_buttonUpperW_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "W");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "W");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "W");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "W");
}

void Keyboard::on_buttonUpperX_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "X");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "X");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "X");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "X");
}

void Keyboard::on_buttonUpperY_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "Y");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "Y");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "Y");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "Y");
}

void Keyboard::on_buttonUpperZ_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "Z");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "Z");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "Z");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "Z");
}


/*************************************/
/*** Alphabetic lower case buttons ***/
/*************************************/
void Keyboard::on_buttonLowerA_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "a");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "a");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "a");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "a");
}

void Keyboard::on_buttonLowerB_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "b");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "b");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "b");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "b");
}

void Keyboard::on_buttonLowerC_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "c");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "c");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "c");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "c");
}

void Keyboard::on_buttonLowerD_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "d");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "d");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "d");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "d");
}

void Keyboard::on_buttonLowerE_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "e");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "e");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "e");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "e");
}

void Keyboard::on_buttonLowerF_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "f");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "f");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "f");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "f");
}

void Keyboard::on_buttonLowerG_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "g");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "g");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "g");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "g");
}

void Keyboard::on_buttonLowerH_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "h");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "h");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "h");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "h");
}

void Keyboard::on_buttonLowerI_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "i");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "i");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "i");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "i");
}

void Keyboard::on_buttonLowerJ_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "j");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "j");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "j");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "j");
}

void Keyboard::on_buttonLowerK_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "k");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "k");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "k");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "k");
}

void Keyboard::on_buttonLowerL_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "l");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "l");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "l");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "l");
}

void Keyboard::on_buttonLowerM_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "m");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "m");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "m");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "m");
}

void Keyboard::on_buttonLowerN_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "n");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "n");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "n");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "n");
}

void Keyboard::on_buttonLowerO_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "o");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "o");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "o");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "o");
}

void Keyboard::on_buttonLowerP_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "p");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "p");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "p");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "p");
}

void Keyboard::on_buttonLowerQ_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "q");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "q");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "q");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "q");
}

void Keyboard::on_buttonLowerR_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "r");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "r");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "r");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "r");
}

void Keyboard::on_buttonLowerS_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "s");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "s");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "s");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "s");
}

void Keyboard::on_buttonLowerT_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "t");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "t");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "t");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "t");
}

void Keyboard::on_buttonLowerU_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "u");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "u");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "u");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "u");
}

void Keyboard::on_buttonLowerV_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "v");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "v");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "v");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "v");
}

void Keyboard::on_buttonLowerW_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "w");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "w");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "w");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "w");
}

void Keyboard::on_buttonLowerX_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "x");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "x");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "x");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "x");
}

void Keyboard::on_buttonLowerY_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "y");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "y");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "y");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "y");
}

void Keyboard::on_buttonLowerZ_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "z");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "z");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "z");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "z");
}


/*************************************/
/********** Symbols buttons **********/
/*************************************/
void Keyboard::on_buttonQuestionMark_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "?");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "?");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "?");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "?");
}

void Keyboard::on_buttonAtSign_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "@");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "@");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "@");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "@");
}

void Keyboard::on_buttonLeftSquareBracket_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "[");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "[");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "[");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "[");
}

void Keyboard::on_buttonBackSlash_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "\\");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "\\");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "\\");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "\\");
}

void Keyboard::on_buttonRightSquareBracket_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "]");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "]");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "]");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "]");
}

void Keyboard::on_buttonCaret_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "^");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "^");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "^");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "^");
}

void Keyboard::on_buttonUnderscore_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "_");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "_");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "_");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "_");
}

void Keyboard::on_buttonEqual_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "=");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "=");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "=");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "=");
}

void Keyboard::on_buttonPipe_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "|");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "|");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "|");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "|");
}

void Keyboard::on_buttonTide_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "~");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "~");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "~");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "~");
}

void Keyboard::on_buttonDoubleQuote_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "\"");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "\"");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "\"");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "\"");
}

void Keyboard::on_buttonExclamationMark_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "!");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "!");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "!");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "!");
}

void Keyboard::on_buttonHash_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "#");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "#");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "#");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "#");
}

void Keyboard::on_buttonDollarSign_clicked()
{    
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "$");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "$");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "$");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "$");
}

void Keyboard::on_buttonPercentageSign_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "%");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "%");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "%");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "%");
}

void Keyboard::on_buttonAndSign_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "&");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "&");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "&");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "&");
}

void Keyboard::on_buttonApostrophe_clicked()
{   
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "'");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "'");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "'");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "'");
}

void Keyboard::on_buttonLeftParenBracket_clicked()
{   
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "(");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "(");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "(");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "(");
}

void Keyboard::on_buttonRightParenBracket_clicked()
{    
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + ")");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + ")");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + ")");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + ")");
}

void Keyboard::on_buttonAsterix_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "*");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "*");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "*");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "*");
}

void Keyboard::on_buttonPlus_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "+");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "+");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "+");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "+");
}

void Keyboard::on_buttonComma_clicked()
{   
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + ",");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + ",");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + ",");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + ",");
}

void Keyboard::on_buttonHyphen_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "-");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "-");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "-");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "-");
}

void Keyboard::on_buttonPeriod_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + ".");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + ".");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + ".");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + ".");
}

void Keyboard::on_buttonForwardSlash_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "/");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "/");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "/");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "/");
}

void Keyboard::on_buttonColon_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + ":");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + ":");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + ":");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + ":");
}

void Keyboard::on_buttonLessThan_clicked()
{    
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + "<");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + "<");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + "<");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + "<");
}

void Keyboard::on_buttonGreaterThan_clicked()
{
    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text() + ">");
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text() + ">");
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text() + ">");
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text() + ">");
}


/*****************************************************************************/
/********* Navigation between the 4 keyboard screens *************************/
/********* Page index 0 = Alpha Upper Case    ********************************/
/********* Page index 1 = Alpha Lower Case    ********************************/
/********* Page index 2 = Numeric             ********************************/
/********* Page index 3 = Symbols             ********************************/
/*****************************************************************************/
void Keyboard::on_buttonAlpha_clicked()
{
    // display Alpha Upper Case keyboard
    ui->stackedWidget->setCurrentIndex(0);
}

void Keyboard::on_buttonNumericAlpha_clicked()
{
    // display Alpha Upper Case keyboard
    ui->stackedWidget->setCurrentIndex(0);
}

void Keyboard::on_buttonLowerAlt_clicked()
{
    // display Alpha Upper Case keyboard
    ui->stackedWidget->setCurrentIndex(0);
}

void Keyboard::on_buttonUpperAlt_clicked()
{
    // display Alpha Lower Case keyboard
    ui->stackedWidget->setCurrentIndex(1);
}

void Keyboard::on_buttonUpperSymbols_clicked()
{
    // display symbols keyboard
    ui->stackedWidget->setCurrentIndex(2);
}

void Keyboard::on_buttonLowerSymbols_clicked()
{
    // display symbols keyboard
    ui->stackedWidget->setCurrentIndex(2);
}

void Keyboard::on_buttonUpperNumeric_clicked()
{
    // display numeric keyboard
    ui->stackedWidget->setCurrentIndex(3);
}

void Keyboard::on_buttonLowerNumeric_clicked()
{
    // display numeric keyboard
    ui->stackedWidget->setCurrentIndex(3);
}



/*****************************************************************************/
/********* Remove the last character that was entered ************************/
/*****************************************************************************/
void Keyboard::on_buttonNumericDeleteLastChar_clicked()
{
    RemoveLastCharacter();
}

void Keyboard::on_buttonUpperDeleteLastChar_clicked()
{
    RemoveLastCharacter();
}

void Keyboard::on_buttonLowerDeleteLastChar_clicked()
{
    RemoveLastCharacter();
}

void Keyboard::on_buttonSymbolsDeleteLastChar_clicked()
{
    RemoveLastCharacter();
}

void Keyboard::RemoveLastCharacter()
{
    int len = ui->aLineEditUpperCaseValueEntered->text().length();

    ui->aLineEditUpperCaseValueEntered->setText(ui->aLineEditUpperCaseValueEntered->text().remove(len-1, 1));
    ui->aLineEditLowerCaseValueEntered->setText(ui->aLineEditLowerCaseValueEntered->text().remove(len-1, 1));
    ui->aLineEditSymbolsValueEntered->setText(ui->aLineEditSymbolsValueEntered->text().remove(len-1, 1));
    ui->aLineEditNumericValueEntered->setText(ui->aLineEditNumericValueEntered->text().remove(len-1, 1));
}


/*****************************************************************************/
/********* Enter buttons to save value and proceed to the next screen ********/
/*****************************************************************************/

void Keyboard::on_buttonAlphaUpperEnter_clicked()
{
    SaveValueProceedToNextScreen();
}

void Keyboard::on_buttonAlphaLowerEnter_clicked()
{
    SaveValueProceedToNextScreen();
}

void Keyboard::on_buttonSymbolsEnter_clicked()
{
    SaveValueProceedToNextScreen();
}

void Keyboard::on_buttonNumericEnter_clicked()
{
    SaveValueProceedToNextScreen();
}

void Keyboard::SaveValueProceedToNextScreen()
{
    //TODO: is there a maximum length for value entered that needs to be check before setting and proceeding?

    // got to this screen from 1) Enter User ID, 2) Enter Patient ID, 3) Select Network (Settings)

    // set to the appropriate value (User ID, Patient ID, Network setup) based on what screen we came from

    //qDebug() << "Enter button was pressed (keyboard)";

    if(PreviousScreen == "SetUserID")
    {
        // set User ID
        TestData_User_ID_Source = QString ("Manual");
        TestData_User_ID = QString (ui->aLineEditUpperCaseValueEntered->text());

        // proceed to the next screen based on what screen we came from
        // Go to SetPatientID if entered from SetUserID
        //TODO: Go to TimeLastDose if entered from SetPatientID
        //TODO: Go to ConnectivityForm if entered from SelectNetwork

        // proceed to the next screen (SetPatientID)
        //ui->stackedWidget->setCurrentIndex(4);
        emit goToSetPatientID();

    }
    else if(PreviousScreen == "SetPatientID")
    {
        // set Patient ID
        TestData_Patient_ID_Source = QString ("manual");
        TestData_Patient_ID = QString (ui->aLineEditUpperCaseValueEntered->text());

        // proceed to the next screen (TimeLastDose)
        //ui->stackedWidget->setCurrentIndex(4);
        emit goToTimeLastDose();
    }
}

/************************************************************/
/********* Back buttons to return to previous screen ********/
/************************************************************/

void Keyboard::on_buttonAlphaUpperBack_clicked()
{
    ReturnPreviousScreen();
}

void Keyboard::on_buttonAlphaLowerBack_clicked()
{
    ReturnPreviousScreen();
}

void Keyboard::on_buttonNumericBack_clicked()
{
    ReturnPreviousScreen();
}

void Keyboard::on_buttonSymbolsBack_clicked()
{
    ReturnPreviousScreen();
}

void Keyboard::ReturnPreviousScreen()
{
    //qDebug() << "Back button was pressed (keyboard)";

    if(PreviousScreen == "SetUserID")
    {
        //go back to SetUserID screen
        emit goToUserID();
    }
    else if(PreviousScreen == "SetPatientID")
    {
        //go back to SetPatientID screen
        emit goToPatientID();
    }

    else if(PreviousScreen == "SelectNetwork")
    {
        //go back to SetPatientID screen
        emit goToNetwork();
    }

}





