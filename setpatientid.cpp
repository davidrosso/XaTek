#include "setpatientid.h"
#include "ui_setpatientid.h"

SetPatientID::SetPatientID(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetPatientID)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_EnterPatientID.png");
    ui->labelPatientID->setPixmap(pix);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_keyboard);
    ui->stackedWidget->insertWidget(2, &_timeLastDose);

    connect(&_keyboard, SIGNAL(SetPatientID()), this, SLOT(SetPatientID_click()));
    connect(&_timeLastDose, SIGNAL(SetPatientID()), this, SLOT(SetPatientID_click()));
}

SetPatientID::~SetPatientID()
{
    delete ui;
}

void SetPatientID::SetPatientID_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SetPatientID::on_buttonManual_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SetPatientID::on_buttonScan_clicked()
{
    //TODO: set the patient ID if manually entered
    //SetUserID (string);

    //TODO: else scan button was pressed
    //ScanUserIDBarcode()

    //TODO: add condition test to confirm patient ID was set before proceeding to the next screen
    //bool CheckStatus (current screen ID);
    ui->stackedWidget->setCurrentIndex(2);
}

void SetPatientID::on_buttonBack_clicked()
{
    // return to previous screen (SetUserID)
    emit SetUserID();
}
