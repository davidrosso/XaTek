#include "insertclotchip.h"

extern QString PreviousScreen;
extern QString TestData_RCR_ID;

InsertClotChip::InsertClotChip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsertClotChip)
{
    ui->setupUi(this);

    // Load animated GIF
    QMovie* _movie = new QMovie("://Images/XatekUI_InsertClotChipRCR.gif");
    ui->labelInsertClotChip->setMovie(_movie);
    _movie->setScaledSize(QSize().scaled(575, 785, Qt::KeepAspectRatio));
    _movie->setScaledSize(QSize().transposed());
    _movie->setSpeed(300); // 3x speed
    _movie->start();
    ui->labelInsertClotChip->show();

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_setUserID);

    connect(&_setUserID, SIGNAL(InsertClotChip()), this, SLOT(InsertClotChip_click()));
    connect(&_setUserID, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
}

InsertClotChip::~InsertClotChip()
{
    delete ui;
}

void InsertClotChip::on_buttonNext_clicked()
{        
    // set PreviousScreen variable
    PreviousScreen = "InsertClotChip";

    //TODO: get the RCR ID
    //TestData_RCR_ID = getRcrID();
    TestData_RCR_ID = QString ("RCR ID Retrieved from EEPROM");

    //TODO: check clotchip was inserted sucessful before proceeding to the next screen
    //bool okToProceed = CheckStatus(current screen ID);

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void InsertClotChip::InsertClotChip_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void InsertClotChip::on_buttonBack_clicked()
{
    //return to previous screen (OpenScanClotChip)
    emit OpenScanClotChip();
}

void InsertClotChip::goingToPasscode()
{
    qDebug() << "Slot from InsertClotChip Called";
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}

