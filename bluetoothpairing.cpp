#include "bluetoothpairing.h"
#include "ui_bluetoothpairing.h"
#include <QMessageBox>

BluetoothPairing::BluetoothPairing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BluetoothPairing)
{
    ui->setupUi(this);

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // Software in device will only show XaTek docking stations when scanning for docking stations.

    //TODO: get a list of bluetooth devices
    //ArrayList btDevices = GetBluetoothDevices();

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
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // Software will require GUI interaction by the user to initiate pairing the device with a docking station.

    const QString& s = ui->listWidgetBluetoothDevices->currentItem()->text();
    QMessageBox::information(this, "Begin Pairing", QString("Selected Device for pairing is:        %1").arg(s));

    //TODO: begin pairing with the selected docking station
    //TODO: Show pairing status?
    //TODO: what if pasword entered is incorrect

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will store the pairing too allow the handheld to reconnect with the docking without further operator intervention.
    // Software will connect with previously paired Docks in range of the Device.
    //TODO: save paired device for further use.


    emit BackToConnectivity();
}

void BluetoothPairing::on_buttonBack_clicked()
{
    // return to the previous screen
    emit BackToConnectivity();
}

