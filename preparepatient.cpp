#include "preparepatient.h"
#include "ui_preparepatient.h"

PreparePatient::PreparePatient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreparePatient)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_PreparePatient.png");
    ui->labelPrepPatient->setPixmap(pix);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_preheatClotchip);

    connect(&_preheatClotchip, SIGNAL(PreparePatient()), this, SLOT(PreparePatient_click()));
}

PreparePatient::~PreparePatient()
{
    delete ui;
}

void PreparePatient::PreparePatient_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PreparePatient::on_buttonNext_clicked()
{
    //TODO: add condition test to confirm blood collectoin was completed before proceeding to the next screen
    //bool CheckStatus (current screen ID);

    ui->stackedWidget->setCurrentIndex(1);
}

void PreparePatient::on_buttonBack_clicked()
{
    // return to previous screen (TimeLastDose)
    emit TimeLastDose();
}
