#include "collectsample.h"
#include "ui_collectsample.h"

CollectSample::CollectSample(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollectSample)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_CollectSample.png");
    ui->labelCollectSample->setPixmap(pix);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_verifyClotChip);

    connect(&_verifyClotChip, SIGNAL(CollectSample()), this, SLOT(CollectSample_click()));
}

CollectSample::~CollectSample()
{
    delete ui;
}

void CollectSample::CollectSample_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void CollectSample::on_buttonNext_clicked()
{
    //TODO: confirm that the sample is collected and ready for next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void CollectSample::on_buttonBack_clicked()
{
    // return to previous screen (PreheatClotChip)
    emit PreheatClotChip();
}
