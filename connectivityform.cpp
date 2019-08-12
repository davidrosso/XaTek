#include "connectivityform.h"
#include "ui_connectivityform.h"
#include <QMessageBox>

ConnectivityForm::ConnectivityForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectivityForm)
{
    ui->setupUi(this);

    // setup the image from resource file
    ui->buttonWifiImage->setIcon(QIcon("://Images/XatekUI_WiFi.png"));
    ui->buttonWifiImage->setIconSize(QSize(700, 200));

    ui->buttonBluetoothImage->setIcon(QIcon("://Images/XatekUI_Bluetooth.png"));
    ui->buttonBluetoothImage->setIconSize(QSize(700, 200));

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_selectNetwork);
    ui->stackedWidget->insertWidget(2, &_bluetoothPairing);

    connect(&_selectNetwork, SIGNAL(BackToConnectivity()), this, SLOT(MoveBack()));
    connect(&_bluetoothPairing, SIGNAL(BackToConnectivity()), this, SLOT(MoveBack()));
}

ConnectivityForm::~ConnectivityForm()
{
    delete ui;
}

void ConnectivityForm::on_buttonWifiText_clicked()
{
    SetupWiFi();
}

void ConnectivityForm::on_buttonWifiImage_clicked()
{
    SetupWiFi();
}

void ConnectivityForm::on_buttonBluetoothImage_clicked()
{
    SetupBluetooth();
}

void ConnectivityForm::on_buttonBluetoothText_clicked()
{
    SetupBluetooth();
}

void ConnectivityForm::MoveBack()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ConnectivityForm::SetupWiFi()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ConnectivityForm::SetupBluetooth()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ConnectivityForm::on_buttonBack_clicked()
{
    // return to previous screen
    emit SettingsOptionsClicked();
}

void ConnectivityForm::on_buttonEnter_clicked()
{    
    //TODO: Not sure what this button is used for
    //TODO: Do we need this button?
}
