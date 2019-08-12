#include "openscanclotchip.h"
#include "ui_openscanclotchip.h"
#include <QMovie>
#include <QMessageBox>

OpenScanClotChip::OpenScanClotChip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenScanClotChip)
{
    ui->setupUi(this);

    // Load animated GIF
    QMovie* _movie = new QMovie("://Images/XatekUI_OpenScanClotChip.gif");
    ui->labelScanClotChip->setMovie(_movie);   
    _movie->setScaledSize(QSize().scaled(575, 785, Qt::KeepAspectRatio));
    _movie->setScaledSize(QSize().transposed());
    _movie->setSpeed(300); // 3x speed
    _movie->start();
    ui->labelScanClotChip->show();

    //TODO: get status
    //bool CheckStatus (current screen ID);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_insertClotChip);

    connect(&_insertClotChip, SIGNAL(OpenScanClotChip()), this, SLOT(OpenScanClotChip_Click()));

}

OpenScanClotChip::~OpenScanClotChip()
{
    delete ui;
}

void OpenScanClotChip::on_buttonScan_clicked()
{
    //TODO: believe the data will be sent to the UI by the same mechanize keyboard keys are received.
    //TODO: will need to test on hardware to verify.
    //ScanClotChipBarcode()

    //TODO: Needed if the data is sent to the UI
    //SetClotChipID (string)

    //TODO: add condition test to check the scan was valid before proceeding to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void OpenScanClotChip::OpenScanClotChip_Click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void OpenScanClotChip::on_buttonBack_clicked()
{
    // return to previous screen (MainWindow)
    emit HomeClicked();
}
