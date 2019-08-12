#include "setuserid.h"
#include "ui_setuserid.h"

SetUserID::SetUserID(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUserID)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_EnterUserID.png");
    ui->labelUserID->setPixmap(pix);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);    
    ui->stackedWidget->insertWidget(1, &_keyboard);
    ui->stackedWidget->insertWidget(2, &_setPatientID);

    connect(&_keyboard, SIGNAL(SetUserID()), this, SLOT(SetUserID_click()));
    connect(&_setPatientID, SIGNAL(SetUserID()), this, SLOT(SetUserID_click()));
}

SetUserID::~SetUserID()
{
    delete ui;
}

void SetUserID::SetUserID_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SetUserID::on_buttonManual_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SetUserID::on_buttonScan_clicked()
{        
    //TODO: set the user ID if manually entered
    //SetUserID (string);

    //TODO: else scan button was pressed
    //ScanUserIDBarcode()

    //TODO: add condition test to confirm user ID was set before proceeding to the next screen
    //bool CheckStatus (current screen ID);

    ui->stackedWidget->setCurrentIndex(2);
}

void SetUserID::on_buttonBack_clicked()
{
    // return to previous screen (InsertClotChip)
    emit InsertClotChip();
}
