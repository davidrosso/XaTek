#include "verifyclotchip.h"

extern QString PreviousScreen;
extern QString TestData_DateTimeTestStart;
extern QString DateTimeFormat;

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
    connect(&_testInProgress, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
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
    //TODO: Check if door is open

    // all checks are ok, set the Test Start Date/Time
    TestData_DateTimeTestStart = QDateTime::currentDateTime().toString(DateTimeFormat);

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void VerifyClotChip::goingToPasscode()
{
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}
















