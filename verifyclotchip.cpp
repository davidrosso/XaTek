#include "verifyclotchip.h"
#include "ui_verifyclotchip.h"

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
    //TODO: add condition verfify completed before proceeding to the next screen
    //bool CheckStatus (current screen ID);

    ui->stackedWidget->setCurrentIndex(1);
}
