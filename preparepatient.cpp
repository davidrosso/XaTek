#include "preparepatient.h"

extern QString PreviousScreen;

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
    connect(&_preheatClotchip, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
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
    // set PreviousScreen variable
    PreviousScreen = "PreparePatient";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    //TODO: check prepare patient is complete before proceeding to the next screen
    //bool okToProceed = CheckStatus(current screen ID);

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void PreparePatient::on_buttonBack_clicked()
{
    // return to previous screen (TimeLastDose)
    emit TimeLastDose();
}

void PreparePatient::goingToPasscode()
{
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}
