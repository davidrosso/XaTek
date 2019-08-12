#include "testinprogress.h"
#include "ui_testinprogress.h"

TestInProgress::TestInProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestInProgress)
{
    ui->setupUi(this);

    // setup the image from resource file
    //QPixmap pix("://Images/XatekUI_VerifyingClotChip.png");
    //ui->labelVerifyClotChip->setPixmap((pix.scaled(575,685)));

    // setup signals and slots for navigation
    //ui->stackedWidget->setCurrentIndex(0);
    //ui->stackedWidget->insertWidget(1, &_testInProgress);

}

TestInProgress::~TestInProgress()
{
    delete ui;
}
