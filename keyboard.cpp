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
    ui->ValueEntered->setText(ui->ValueEntered->text() + "0");
}

void Keyboard::on_button1_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "1");
}

void Keyboard::on_button2_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "2");
}

void Keyboard::on_button3_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "3");
}

void Keyboard::on_button4_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "4");
}

void Keyboard::on_button5_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "5");
}

void Keyboard::on_button6_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "6");
}

void Keyboard::on_button7_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "7");
}

void Keyboard::on_button8_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "8");
}

void Keyboard::on_button9_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "9");
}

/*************************************/
/*** Alphabetic UPPER CASE buttons ***/
/*************************************/
void Keyboard::on_buttonUpperA_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "A");
}

void Keyboard::on_buttonUpperB_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "B");
}

void Keyboard::on_buttonUpperC_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "C");
}

void Keyboard::on_buttonUpperD_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "D");
}

void Keyboard::on_buttonUpperE_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "E");
}

void Keyboard::on_buttonUpperF_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "F");
}

void Keyboard::on_buttonUpperG_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "G");
}

void Keyboard::on_buttonUpperH_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "H");
}

void Keyboard::on_buttonUpperI_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "I");
}

void Keyboard::on_buttonUpperJ_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "J");
}

void Keyboard::on_buttonUpperK_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "K");
}

void Keyboard::on_buttonUpperL_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "L");
}

void Keyboard::on_buttonUpperM_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "M");
}

void Keyboard::on_buttonUpperN_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "N");
}

void Keyboard::on_buttonUpperO_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "O");
}

void Keyboard::on_buttonUpperP_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "P");
}

void Keyboard::on_buttonUpperQ_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "Q");
}

void Keyboard::on_buttonUpperR_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "R");
}

void Keyboard::on_buttonUpperS_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "S");
}

void Keyboard::on_buttonUpperT_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "T");
}

void Keyboard::on_buttonUpperU_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "U");
}

void Keyboard::on_buttonUpperV_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "V");
}

void Keyboard::on_buttonUpperW_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "W");
}

void Keyboard::on_buttonUpperX_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "X");
}

void Keyboard::on_buttonUpperY_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "Y");
}

void Keyboard::on_buttonUpperZ_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "Z");
}


/*************************************/
/*** Alphabetic lower case buttons ***/
/*************************************/
void Keyboard::on_buttonLowerA_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "a");
}

void Keyboard::on_buttonLowerB_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "b");
}

void Keyboard::on_buttonLowerC_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "c");
}

void Keyboard::on_buttonLowerD_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "d");
}

void Keyboard::on_buttonLowerE_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "e");
}

void Keyboard::on_buttonLowerF_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "f");
}

void Keyboard::on_buttonLowerG_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "g");
}

void Keyboard::on_buttonLowerH_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "h");
}

void Keyboard::on_buttonLowerI_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "i");
}

void Keyboard::on_buttonLowerJ_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "j");
}

void Keyboard::on_buttonLowerK_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "k");
}

void Keyboard::on_buttonLowerL_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "l");
}

void Keyboard::on_buttonLowerM_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "m");
}

void Keyboard::on_buttonLowerN_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "n");
}

void Keyboard::on_buttonLowerO_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "o");
}

void Keyboard::on_buttonLowerP_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "p");
}

void Keyboard::on_buttonLowerQ_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "q");
}

void Keyboard::on_buttonLowerR_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "r");
}

void Keyboard::on_buttonLowerS_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "s");
}

void Keyboard::on_buttonLowerT_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "t");
}

void Keyboard::on_buttonLowerU_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "u");
}

void Keyboard::on_buttonLowerV_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "v");
}

void Keyboard::on_buttonLowerW_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "w");
}

void Keyboard::on_buttonLowerX_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "x");
}

void Keyboard::on_buttonLowerY_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "y");
}

void Keyboard::on_buttonLowerZ_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "z");
}


/*************************************/
/********** Symbols buttons **********/
/*************************************/
void Keyboard::on_buttonQuestionMark_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "?");
}

void Keyboard::on_buttonAtSign_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "@");
}

void Keyboard::on_buttonLeftSquareBracket_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "[");
}

void Keyboard::on_buttonBackSlash_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "\\");
}

void Keyboard::on_buttonRightSquareBracket_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "]");
}

void Keyboard::on_buttonCaret_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "^");
}

void Keyboard::on_buttonUnderscore_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "_");
}

void Keyboard::on_buttonEqual_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "=");
}

void Keyboard::on_buttonPipe_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "|");
}

void Keyboard::on_buttonTide_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "~");
}

void Keyboard::on_buttonDoubleQuote_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "\"");
}

void Keyboard::on_buttonExclamationMark_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "!");
}

void Keyboard::on_buttonHash_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "#");
}

void Keyboard::on_buttonDollarSign_clicked()
{    
    ui->ValueEntered->setText(ui->ValueEntered->text() + "$");
}

void Keyboard::on_buttonPercentageSign_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "%");
}

void Keyboard::on_buttonAndSign_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "&");
}

void Keyboard::on_buttonApostrophe_clicked()
{   
    ui->ValueEntered->setText(ui->ValueEntered->text() + "'");
}

void Keyboard::on_buttonLeftParenBracket_clicked()
{   
    ui->ValueEntered->setText(ui->ValueEntered->text() + "(");
}

void Keyboard::on_buttonRightParenBracket_clicked()
{    
    ui->ValueEntered->setText(ui->ValueEntered->text() + ")");
}

void Keyboard::on_buttonAsterix_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "*");
}

void Keyboard::on_buttonPlus_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "+");
}

void Keyboard::on_buttonComma_clicked()
{   
    ui->ValueEntered->setText(ui->ValueEntered->text() + ",");
}

void Keyboard::on_buttonHyphen_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "-");
}

void Keyboard::on_buttonPeriod_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + ".");
}

void Keyboard::on_buttonForwardSlash_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + "/");
}

void Keyboard::on_buttonColon_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + ":");
}

void Keyboard::on_buttonLessThan_clicked()
{    
    ui->ValueEntered->setText(ui->ValueEntered->text() + "<");
}

void Keyboard::on_buttonGreaterThan_clicked()
{
    ui->ValueEntered->setText(ui->ValueEntered->text() + ">");
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
    //ui->ValueEntered->setText(ui->ValueEntered->text() + "~");
    int len = ui->ValueEntered->text().length();

    ui->ValueEntered->setText(ui->ValueEntered->text().remove(len-1, 1));
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
        TestData_User_ID = QString (ui->ValueEntered->text());

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
        TestData_Patient_ID = QString (ui->ValueEntered->text());

        // proceed to the next screen (TimeLastDose)
        //ui->stackedWidget->setCurrentIndex(4);
        emit goToTimeLastDose();
    }
    else if(PreviousScreen == "SelectNetwork")
    {
        emit checkWifiConnection(QString (ui->ValueEntered->text()));
        ui->ValueEntered->setText("");
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
        //Clear keyboard input
        ui->ValueEntered->setText("");

        //go back to SelectNetwork screen
        emit goToNetwork();
    }

}





