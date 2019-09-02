#include "verifyclotchip.h"
#include "ui_verifyclotchip.h"
#include <QMessageBox>
#include <QtXml>
#include <QDebug>
#include <QDate>
#include <QDateTime>

extern QString PreviousScreen;
//extern QString TestData_ClotChip_ID;
//extern QString TestData_RCR_ID;
//extern QString TestData_Device_ID;
//extern QString TestData_Organization_ID;
//extern QString TestData_User_ID_Source;
//extern QString TestData_User_ID;
//extern QString TestData_Patient_ID_Source;
//extern QString TestData_Patient_ID;
extern QString TestData_DateTimeTestStart;
//extern QString TestData_DateTimeLastDose;
//extern QString TestData_HoursSinceLastDose;
//extern QString TestData_PeakTimeUnits;
//extern QString TestData_PeakTimeInSeconds;
//extern QString TestData_DeltaEpsilon;
//extern QString TestData_Capacitance;
//extern QString TestData_TestDurationInSeconds;
//extern QString TestData_TestDurationUnits;
//extern QString TestData_Errors;
//extern QString TestData_CRC;
extern QString DateTimeFormat;

//QString dateTimeFormat = "yyyy-MM-dd HH:mm:ss"; //
//QString dateTimeFormat2 = "yyyy-MM-ddThh:mm:ss.nnnnnn+|-hh:mm"; //

VerifyClotChip::VerifyClotChip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerifyClotChip)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_VerifyingClotChip.png");
    ui->labelVerifyClotChip->setPixmap((pix.scaled(575,685)));

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_testInProgress);

    connect(&_testInProgress, SIGNAL(VerifyClotChip()), this, SLOT(VerifyClotChip_click()));

}

VerifyClotChip::~VerifyClotChip()
{
    delete ui;
}

void VerifyClotChip::VerifyClotChip_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void VerifyClotChip::on_buttonBack_clicked()
{
    //TODO: return to previous screen
    emit CollectSample();
}

void VerifyClotChip::on_buttonNext_clicked()
{    
    // set PreviousScreen variable
    PreviousScreen = "VerifyClotChip";    

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If the device senses the cap on the ClotChip is missing, the user is warned and the workflow is stopped
    //TODO: Check if ClotChip Cap is on

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If the RCR door is opened after the start of readings, the user is warned and the workflow is stopped.
    //TODO: Check if Door is open

    // all checks are ok, set the Test Start Date/Time
    TestData_DateTimeTestStart = QDateTime::currentDateTime().toString(DateTimeFormat);

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

















