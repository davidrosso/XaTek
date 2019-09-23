#include "collectsample.h"

extern QString PreviousScreen;

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
    connect(&_verifyClotChip, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
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
    // set PreviousScreen variable
    PreviousScreen = "CollectSample";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    //TODO: check that a sample was collected before proceeding to the next screen
    //bool okToProceed = CheckStatus(current screen ID);

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void CollectSample::on_buttonBack_clicked()
{
    // return to previous screen (PreheatClotChip)
    emit PreheatClotChip();
}

void CollectSample::goingToPasscode()
{
    //qDebug() << "Slot from CollectSample Called";
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}
