#include "insertclotchip.h"
#include "ui_insertclotchip.h"

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
}

InsertClotChip::~InsertClotChip()
{
    delete ui;
}

void InsertClotChip::on_buttonNext_clicked()
{        
    //TODO: add check to check the status before proceeding
    //bool CheckStatus (current screen ID);

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
