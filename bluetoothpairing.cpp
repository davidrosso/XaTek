#include "bluetoothpairing.h"
#include "ui_bluetoothpairing.h"
#include <QMessageBox>

BluetoothPairing::BluetoothPairing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BluetoothPairing)
{
    ui->setupUi(this);

    //TODO: get a list of networks
    //GetBluetoothDevices();

    // for now, just populate some generic networks
    QListWidgetItem *item1 = new QListWidgetItem("Docking Station 03");
    item1 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetBluetoothDevices->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem("Docking Station 27");
    item2 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetBluetoothDevices->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem("Docking Station 31");
    item3 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetBluetoothDevices->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem("Docking Station 14");
    item4 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetBluetoothDevices->addItem(item4);

}

BluetoothPairing::~BluetoothPairing()
{
    delete ui;
}

void BluetoothPairing::on_buttonEnter_clicked()
{
    const QString& s = ui->listWidgetBluetoothDevices->currentItem()->text();

    QMessageBox::information(this, "Begin Pairing",
        QString("Selected Device for pairing is:        %1").arg(s));

    //TODO: begin pairing with the selected docking station
    //TODO: Show pairing status?
    //TODO: what if pasword entered is incorrect
}

void BluetoothPairing::on_buttonBack_clicked()
{
    // return to the previous screen
    emit BackToConnectivity();
}

