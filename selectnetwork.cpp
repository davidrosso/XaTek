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
    //ui->treeWidgetWiFis->setColumnWidth(0,250);
    //ui->treeWidgetWiFis->setColumnWidth(1,200);

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

    QProcess myProcess;
    QStringList arguments;
    QString stdout;

    myProcess.start("ifconfig wlan0 up");
    myProcess.waitForFinished(-1);
    arguments << "-c" << "iw dev wlan0 scan | grep SSID";
    myProcess.start("sh", arguments);
    myProcess.waitForFinished(-1);
    QString myOutput(myProcess.readAllStandardOutput());
    myProcess.close();

//    myProcess.start("iw dev wlan0 scan | grep SSID");
//    myProcess.waitForFinished(-1);
//    QString myOutput(myProcess.readAllStandardOutput());
//    myProcess.close();
    myOutput = myOutput.remove("\n\t").remove("\n").remove("\t").remove("SSID:").trimmed();
    qDebug() << myOutput;

    QStringList ssidList = myOutput.split(" ");
    qDebug() << ssidList;

    /******************************************************************


    ui->listWidgetNetworks->clear();

    QNetworkConfigurationManager ncm;
    netcfgList.clear();
    WiFisList.clear();
    ui->treeWidgetWiFis->clear();
    auto netcfgList = ncm.allConfigurations();
    ncm.updateConfigurations();

    //qDebug() << netcfgList;

    for (auto &x : netcfgList)
    {
        //ui->listWidgetNetworks->addItem(x.name() + ": " + QString(x.bearerType()) );
        //qDebug() << x.type() + x.name();

        if(x.name() == "")
        {
            WiFisList << "Unknown(Other Network)";
        }
//        else if(x.bearerType() == QNetworkConfiguration::BearerWLAN)
//        {
//            qDebug() << x.name();
//            WiFisList << x.name();
//        }
        //qDebug() << x.bearerType();
        //qDebug() << x.name();
        if (x.bearerType() == QNetworkConfiguration::BearerWLAN)
        {
            //qDebug() << x.name();
            if (x.name() == "YouDesiredNetwork")
            {
                //cfg = x;
            }
        }
    }
    //qDebug() << WiFisList;

***********************************************************************************/

    for(int i=0; i<ssidList.size(); i++)
    {
        bool exist = false;
        QTreeWidgetItem * item = new QTreeWidgetItem();

        for(int j=0; j<ui->treeWidgetWiFis->topLevelItemCount(); j++)
        {
            QTreeWidgetItem *index = ui->treeWidgetWiFis->topLevelItem(j);
            QString str = index->text(1);
            //qDebug() << "item: " + str;
            if(str == ssidList[i])
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
            item->setText  (0,ssidList[i]);
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
