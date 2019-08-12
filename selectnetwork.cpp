#include "selectnetwork.h"
#include "ui_selectnetwork.h"
#include <QMessageBox>

SelectNetwork::SelectNetwork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectNetwork)
{
    ui->setupUi(this);

    //TODO: get a list of networks
    //GetNetworks();

    // for now, just populate some generic networks
    QListWidgetItem *item1 = new QListWidgetItem("Hospital Network");
    item1 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetNetworks->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem("Guest Network");
    item2 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetNetworks->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem("Network 3");
    item3 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetNetworks->addItem(item3);


    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_keyboard);


}

SelectNetwork::~SelectNetwork()
{
    delete ui;
}

void SelectNetwork::on_buttonBack_clicked()
{    
    // return to the previous screen
    emit BackToConnectivity();
}

void SelectNetwork::on_buttonEnter_clicked()
{    
    const QString& s = ui->listWidgetNetworks->currentItem()->text();

    QMessageBox::information(this, "Network Connection",
        QString("Selected Network is:        %1").arg(s));

    // go to keyboard class to enter password
    ui->stackedWidget->setCurrentIndex(1);

}
