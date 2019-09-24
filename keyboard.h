#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include "timelastdose.h"
#include "ui_keyboard.h"

namespace Ui {
class Keyboard;
}

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = 0);
    ~Keyboard();

private:
    Ui::Keyboard *ui;       
    //TimeLastDose _timeLastDose;

private slots:
    void on_button0_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_buttonNumericAlpha_clicked();

    void on_buttonUpperA_clicked();
    void on_buttonUpperB_clicked();
    void on_buttonUpperC_clicked();
    void on_buttonUpperD_clicked();
    void on_buttonUpperE_clicked();
    void on_buttonUpperF_clicked();
    void on_buttonUpperG_clicked();
    void on_buttonUpperH_clicked();
    void on_buttonUpperI_clicked();
    void on_buttonUpperJ_clicked();
    void on_buttonUpperK_clicked();
    void on_buttonUpperL_clicked();
    void on_buttonUpperM_clicked();
    void on_buttonUpperN_clicked();
    void on_buttonUpperO_clicked();
    void on_buttonUpperP_clicked();
    void on_buttonUpperQ_clicked();
    void on_buttonUpperR_clicked();
    void on_buttonUpperS_clicked();
    void on_buttonUpperT_clicked();
    void on_buttonUpperU_clicked();
    void on_buttonUpperV_clicked();
    void on_buttonUpperW_clicked();
    void on_buttonUpperX_clicked();
    void on_buttonUpperY_clicked();
    void on_buttonUpperZ_clicked();
    void on_buttonUpperAlt_clicked();
    void on_buttonUpperSymbols_clicked();
    void on_buttonUpperNumeric_clicked();

    void on_buttonLowerA_clicked();
    void on_buttonLowerB_clicked();
    void on_buttonLowerC_clicked();
    void on_buttonLowerD_clicked();
    void on_buttonLowerE_clicked();
    void on_buttonLowerF_clicked();
    void on_buttonLowerG_clicked();
    void on_buttonLowerH_clicked();
    void on_buttonLowerI_clicked();
    void on_buttonLowerJ_clicked();
    void on_buttonLowerK_clicked();
    void on_buttonLowerL_clicked();
    void on_buttonLowerM_clicked();
    void on_buttonLowerN_clicked();
    void on_buttonLowerO_clicked();
    void on_buttonLowerP_clicked();
    void on_buttonLowerQ_clicked();
    void on_buttonLowerR_clicked();
    void on_buttonLowerS_clicked();
    void on_buttonLowerT_clicked();
    void on_buttonLowerU_clicked();
    void on_buttonLowerV_clicked();
    void on_buttonLowerW_clicked();
    void on_buttonLowerX_clicked();
    void on_buttonLowerY_clicked();
    void on_buttonLowerZ_clicked();
    void on_buttonLowerAlt_clicked();
    void on_buttonLowerSymbols_clicked();
    void on_buttonLowerNumeric_clicked();

    void on_buttonQuestionMark_clicked();
    void on_buttonAtSign_clicked();
    void on_buttonLeftSquareBracket_clicked();
    void on_buttonBackSlash_clicked();
    void on_buttonRightSquareBracket_clicked();
    void on_buttonCaret_clicked();
    void on_buttonUnderscore_clicked();
    void on_buttonEqual_clicked();
    void on_buttonPipe_clicked();
    void on_buttonTide_clicked();
    void on_buttonDoubleQuote_clicked();
    void on_buttonExclamationMark_clicked();
    void on_buttonHash_clicked();
    void on_buttonDollarSign_clicked();
    void on_buttonPercentageSign_clicked();
    void on_buttonAndSign_clicked();
    void on_buttonApostrophe_clicked();
    void on_buttonLeftParenBracket_clicked();
    void on_buttonRightParenBracket_clicked();
    void on_buttonAsterix_clicked();
    void on_buttonPlus_clicked();
    void on_buttonComma_clicked();
    void on_buttonHyphen_clicked();
    void on_buttonPeriod_clicked();
    void on_buttonForwardSlash_clicked();
    void on_buttonColon_clicked();
    void on_buttonLessThan_clicked();
    void on_buttonGreaterThan_clicked();
    void on_buttonAlpha_clicked();

    void on_buttonUpperDeleteLastChar_clicked();
    void on_buttonLowerDeleteLastChar_clicked();
    void on_buttonNumericDeleteLastChar_clicked();
    void on_buttonSymbolsDeleteLastChar_clicked();
    void RemoveLastCharacter();

    void on_buttonAlphaLowerEnter_clicked();
    void on_buttonAlphaUpperEnter_clicked();
    void on_buttonNumericEnter_clicked();
    void on_buttonSymbolsEnter_clicked();
    void SaveValueProceedToNextScreen();

    void on_buttonAlphaUpperBack_clicked();
    void on_buttonAlphaLowerBack_clicked();
    void on_buttonNumericBack_clicked();
    void on_buttonSymbolsBack_clicked();
    void ReturnPreviousScreen();

signals:
    void SetUserID();
    void SetPatientID();
    void goToUserID();
    void goToPatientID();
    void goToNetwork();
    void goToTimeLastDose();
    void goToSetPatientID();

};

#endif // KEYBOARD_H
