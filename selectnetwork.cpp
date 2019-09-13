#include "selectnetwork.h"

SelectNetwork::SelectNetwork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectNetwork)
{
    ui->setupUi(this);

    findTimer = new QTimer();
    findTimer->setInterval(20000); // update list every 20 seconds

    connect(findTimer,&QTimer::timeout,this,&SelectNetwork::FindActiveWirelessNetworks);
    findTimer->start();
    foundCount = 0;

    FindActiveWirelessNetworks();

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_keyboard);

}


SelectNetwork::~SelectNetwork()
{
    delete ui;
}


void SelectNetwork::FindActiveWirelessNetworks()
{
    //TODO: confirm this works on the board and displays available networks

    ui->listWidgetNetworks->clear();

    QNetworkConfigurationManager ncm;
    netcfgList = ncm.allConfigurations();
    WiFisList.clear();
    ui->treeWidgetWiFis->clear();

    for (auto &x : netcfgList)
    {
        //ui->listWidgetNetworks->addItem(x.name() + ": " + QString(x.bearerType()) );
        //qDebug() << x.type() + ": " + x.name();

        if(x.name() == "")
        {
            WiFisList << "Unknown(Other Network)";
        }
        else
        {
            WiFisList << x.name();
        }

        //if (x.bearerType() == QNetworkConfiguration::BearerWLAN)
        //{
            //if (x.name() == "YouDesiredNetwork")
            //{
            //    cfg = x;
            //}
        //}
    }

    for(int i=0; i<WiFisList.size(); i++)
    {
        bool exist = false;
        QTreeWidgetItem * item = new QTreeWidgetItem();

        for(int j=0; j<ui->treeWidgetWiFis->topLevelItemCount(); j++)
        {
            QTreeWidgetItem *index = ui->treeWidgetWiFis->topLevelItem(j);
            QString str = index->text(1);
            //qDebug() << "item: " + str;
            if(str == WiFisList[i])
            {
                exist = true;
                break;
            }
        }
        if(!exist)
        {
            item->setTextAlignment(0,Qt::AlignLeft);
            //item->setTextAlignment(1,Qt::AlignLeft);
            //item->setText(0,QString::number(++foundCount));
            item->setText  (0,WiFisList[i]);
            ui->treeWidgetWiFis->addTopLevelItem(item);
        }
    }
}

void SelectNetwork::on_buttonBack_clicked()
{    
    // return to the previous screen
    emit BackToConnectivity();
}

void SelectNetwork::on_buttonEnter_clicked()
{    
    const QString& s = ui->listWidgetNetworks->currentItem()->text();

    // display/confirm the selected network
    QMessageBox::information(this, "Network Connection",
        QString("Selected Network is:        %1").arg(s));

    // connect to the selected network
    //auto session = new QNetworkSession(cfg, this);
    //session->open();

    // go to keyboard class to enter password
    ui->stackedWidget->setCurrentIndex(1);

}
