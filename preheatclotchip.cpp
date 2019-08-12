#include "preheatclotchip.h"
#include "ui_preheatclotchip.h"

PreheatClotchip::PreheatClotchip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreheatClotchip)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_PreHeatClotChip.png");
    ui->labelPreheatClotchip->setPixmap(pix);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_collectSample);

    connect(&_collectSample, SIGNAL(PreheatClotChip()), this, SLOT(PreheatClotChip_click()));
}

PreheatClotchip::~PreheatClotchip()
{
    delete ui;
}

void PreheatClotchip::PreheatClotChip_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PreheatClotchip::on_buttonNext_clicked()
{
    //TODO: how to confirm clotchip is preheated before moving to the next screen

    ui->stackedWidget->setCurrentIndex(1);
}

void PreheatClotchip::on_buttonBack_clicked()
{
    // return to previous screen (PreparePatient)
    emit PreparePatient();
}
