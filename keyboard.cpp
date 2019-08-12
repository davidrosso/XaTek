#include "keyboard.h"
#include "ui_keyboard.h"
#include <QMessageBox>

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    // setup signals and slots for navigation
    //index 0 = Alpha Upper Case
    //index 1 = Alpha Lower Case
    //index 2 = Numeric
    //index 3 = Symbols

    // set default view to Alpha Upper Case
    ui->stackedWidget->setCurrentIndex(0);    
}

//TODO: created constructor for passing in the screen ID
Keyboard::Keyboard(int val, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    // set the val for screen ID so we know how this keyboard screen was accessed
    screenID = val;

    // setup signals and slots for navigation
    //index 0 = Alpha Upper Case
    //index 1 = Alpha Lower Case
    //index 2 = Numeric
    //index 3 = Symbols

    // set default view to Alpha Upper Case
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "0");
}

void Keyboard::on_button1_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "1");
}

void Keyboard::on_button2_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "2");
}

void Keyboard::on_button3_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "3");
}

void Keyboard::on_button4_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "4");
}

void Keyboard::on_button5_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "5");
}

void Keyboard::on_button6_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "6");
}

void Keyboard::on_button7_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "7");
}

void Keyboard::on_button8_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "8");
}

void Keyboard::on_button9_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "9");
}

void Keyboard::on_buttonNumericAlpha_clicked()
{
    // display Alpha Upper Case keyboard
    ui->stackedWidget->setCurrentIndex(0);
}

void Keyboard::on_buttonNumericDeleteLastChar_clicked()
{
    int len = ui->lineEditValueEntered->text().length();
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text().remove(len-1, 1));
}

/*************************************/
/*** Alphabetic UPPER CASE buttons ***/
/*************************************/
void Keyboard::on_buttonUpperA_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "A");
}

void Keyboard::on_buttonUpperB_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "B");
}

void Keyboard::on_buttonUpperC_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "C");
}

void Keyboard::on_buttonUpperD_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "D");
}

void Keyboard::on_buttonUpperE_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "E");
}

void Keyboard::on_buttonUpperF_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "F");
}

void Keyboard::on_buttonUpperG_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "G");
}

void Keyboard::on_buttonUpperH_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "H");
}

void Keyboard::on_buttonUpperI_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "I");
}

void Keyboard::on_buttonUpperJ_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "J");
}

void Keyboard::on_buttonUpperK_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "K");
}

void Keyboard::on_buttonUpperL_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "L");
}

void Keyboard::on_buttonUpperM_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "M");
}

void Keyboard::on_buttonUpperN_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "N");
}

void Keyboard::on_buttonUpperO_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "O");
}

void Keyboard::on_buttonUpperP_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "P");
}

void Keyboard::on_buttonUpperQ_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "Q");
}

void Keyboard::on_buttonUpperR_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "R");
}

void Keyboard::on_buttonUpperS_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "S");
}

void Keyboard::on_buttonUpperT_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "T");
}

void Keyboard::on_buttonUpperU_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "U");
}

void Keyboard::on_buttonUpperV_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "V");
}

void Keyboard::on_buttonUpperW_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "W");
}

void Keyboard::on_buttonUpperX_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "X");
}

void Keyboard::on_buttonUpperY_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "Y");
}

void Keyboard::on_buttonUpperZ_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "Z");
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

void Keyboard::on_buttonUpperNumeric_clicked()
{
    // display numeric keyboard
    ui->stackedWidget->setCurrentIndex(3);
}

void Keyboard::on_buttonUpperDeleteLastChar_clicked()
{
    int len = ui->lineEditValueEntered->text().length();
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text().remove(len-1, 1));
}

/*************************************/
/*** Alphabetic lower case buttons ***/
/*************************************/
void Keyboard::on_buttonLowerA_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "a");
}

void Keyboard::on_buttonLowerB_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "b");
}

void Keyboard::on_buttonLowerC_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "c");
}

void Keyboard::on_buttonLowerD_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "d");
}

void Keyboard::on_buttonLowerE_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "e");
}

void Keyboard::on_buttonLowerF_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "f");
}

void Keyboard::on_buttonLowerG_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "g");
}

void Keyboard::on_buttonLowerH_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "h");
}

void Keyboard::on_buttonLowerI_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "i");
}

void Keyboard::on_buttonLowerJ_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "j");
}

void Keyboard::on_buttonLowerK_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "k");
}

void Keyboard::on_buttonLowerL_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "l");
}

void Keyboard::on_buttonLowerM_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "m");
}

void Keyboard::on_buttonLowerN_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "n");
}

void Keyboard::on_buttonLowerO_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "o");
}

void Keyboard::on_buttonLowerP_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "p");
}

void Keyboard::on_buttonLowerQ_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "q");
}

void Keyboard::on_buttonLowerR_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "r");
}

void Keyboard::on_buttonLowerS_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "s");
}

void Keyboard::on_buttonLowerT_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "t");
}

void Keyboard::on_buttonLowerU_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "u");
}

void Keyboard::on_buttonLowerV_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "v");
}

void Keyboard::on_buttonLowerW_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "w");
}

void Keyboard::on_buttonLowerX_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "x");
}

void Keyboard::on_buttonLowerY_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "y");
}

void Keyboard::on_buttonLowerZ_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "z");
}

void Keyboard::on_buttonLowerAlt_clicked()
{
    // display Alpha Upper Case keyboard
    ui->stackedWidget->setCurrentIndex(0);
}

void Keyboard::on_buttonLowerSymbols_clicked()
{    
    // display symbols keyboard
    ui->stackedWidget->setCurrentIndex(2);
}

void Keyboard::on_buttonLowerNumeric_clicked()
{
    // display numeric keyboard
    ui->stackedWidget->setCurrentIndex(3);
}

void Keyboard::on_buttonLowerDeleteLastChar_clicked()
{
    int len = ui->lineEditValueEntered->text().length();
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text().remove(len-1, 1));
}



/*************************************/
/********** Symbols buttons **********/
/*************************************/
void Keyboard::on_buttonQuestionMark_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "?");
}

void Keyboard::on_buttonAtSign_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "@");
}

void Keyboard::on_buttonLeftSquareBracket_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "[");
}

void Keyboard::on_buttonBackSlash_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "\\");
}

void Keyboard::on_buttonRightSquareBracket_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "]");
}

void Keyboard::on_buttonCaret_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "^");
}

void Keyboard::on_buttonUnderscore_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "_");
}

void Keyboard::on_buttonEqual_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "=");
}

void Keyboard::on_buttonPipe_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "|");
}

void Keyboard::on_buttonTide_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "~");
}

void Keyboard::on_buttonDoubleQuote_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "\"");
}

void Keyboard::on_buttonExclamationMark_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "!");
}

void Keyboard::on_buttonHash_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "#");
}

void Keyboard::on_buttonDollarSign_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "$");
}

void Keyboard::on_buttonPercentageSign_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "%");
}

void Keyboard::on_buttonAndSign_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "&");
}

void Keyboard::on_buttonApostrophe_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "'");
}

void Keyboard::on_buttonLeftParenBracket_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "[");
}

void Keyboard::on_buttonRightParenBracket_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "]");
}

void Keyboard::on_buttonAsterix_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "*");
}

void Keyboard::on_buttonPlus_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "+");
}

void Keyboard::on_buttonComma_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + ",");
}

void Keyboard::on_buttonHyphen_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "-");
}

void Keyboard::on_buttonPeriod_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + ".");
}

void Keyboard::on_buttonForwardSlash_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "e");
}

void Keyboard::on_buttonColon_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + ":");
}

void Keyboard::on_buttonLessThan_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + "<");
}

void Keyboard::on_buttonGreaterThan_clicked()
{
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text() + ">");
}

void Keyboard::on_buttonAlpha_clicked()
{
    // display Alpha Upper Case keyboard
    ui->stackedWidget->setCurrentIndex(0);
}

void Keyboard::on_buttonDeleteLastChar_clicked()
{
    int len = ui->lineEditValueEntered->text().length();
    ui->lineEditValueEntered->setText(ui->lineEditValueEntered->text().remove(len-1, 1));
}


/*************************************/
/********* Enter/Back buttons ********/
/*************************************/

void Keyboard::on_buttonEnter_clicked()
{
    QMessageBox::information(this, "Passcode",
        QString("Value Entered was:        %1\n").arg(QString(ui->lineEditValueEntered->text())));

    //TODO: is there a maximum length for value entered

    // got to this screen from 1) Enter User ID, 2) Enter Patient ID, 3) Select Network (Settings)

    //TODO: need to set to the appropriate value (User ID, Patient ID, Network setup) based on the screenID
    //TODO: SetUserID(string);
    //TODO: SetPatientID(string);
    //TODO: NetworkConnection(string);

    //TODO: proceed to the next screen based on the screenID
    //TODO: Go to SetPatientID if entered from SetUserID
    //TODO: Go to TimeLastDose if entered from SetPatientID
    //TODO: Go to ConnectivityForm if entered from SelectNetwork

}

void Keyboard::on_buttonBack_clicked()
{
    //TODO: return to the previous screen based on the screenID
    //TODO: 1) Enter User ID, 2) Enter Patient ID, 3) Select Network (Settings)

    // for now, always return to set User ID screen
    emit SetUserID();

}

