#include "preheatclotchip.h"

extern QString PreviousScreen;

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
    connect(&_collectSample, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
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
    // set PreviousScreen variable
    PreviousScreen = "PreheatClotchip";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    //TODO: check that preheat complete before proceeding to the next screen
    //bool okToProceed = CheckStatus(current screen ID);

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void PreheatClotchip::on_buttonBack_clicked()
{
    // return to previous screen (PreparePatient)
    emit PreparePatient();
}

void PreheatClotchip::goingToPasscode()
{
    qDebug() << "Slot from PreheatClotChip Called";
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}
