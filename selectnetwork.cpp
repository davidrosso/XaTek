#include "selectnetwork.h"

extern QString PreviousScreen;

SelectNetwork::SelectNetwork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectNetwork)
{
    ui->setupUi(this);

    findTimer = new QTimer();
    findTimer->setInterval(20000); // update list every 20 seconds

    connect(findTimer,&QTimer::timeout,this,&SelectNetwork::FindActiveWirelessNetworks);
    findTimer->start();
    //foundCount = 0;
    //ui->treeWidgetWiFis->setColumnWidth(0,250);
    //ui->treeWidgetWiFis->setColumnWidth(1,200);

    FindActiveWirelessNetworks();

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_keyboardNetwork);

    connect(&_keyboardNetwork, SIGNAL(goToNetwork()),
                 this, SLOT(goToSelectNetwork())
                );
    connect(&_keyboardNetwork, SIGNAL(checkWifiConnection(QString)),
                 this, SLOT(isConnectionValid(QString))
                );

}


SelectNetwork::~SelectNetwork()
{
    delete ui;
}


void SelectNetwork::FindActiveWirelessNetworks()
{
    QProcess myProcess;
    QStringList arguments;
    QString myOutput = "";
    ui->WifiList->clear();

    ui->WifiList->setStyleSheet("background-color: transparent; border: 10px; border-color: black; ");

    myProcess.start("ifconfig wlan0 up");
    myProcess.waitForFinished(-1);
    arguments << "-c" << "iw dev wlan0 scan | grep SSID";
    myProcess.start("sh", arguments);
    myProcess.waitForFinished(-1);
    myOutput = myProcess.readAllStandardOutput();
    myProcess.close();

    myOutput = myOutput.remove("\n\t").remove("\n").remove("\t").remove("SSID:").trimmed();
    //qDebug() << myOutput;

    QStringList ssidList = myOutput.split(" ");
    //qDebug() << ssidList;

    ui->WifiList->addItems(ssidList);


}

void SelectNetwork::on_buttonBack_clicked()
{    
    // return to the previous screen
    emit BackToConnectivity();
}

void SelectNetwork::on_buttonEnter_clicked()
{    
    //const QString& s = ui->listWidgetNetworks->currentItem()->text();

    // display/confirm the selected network
    //QMessageBox::information(this, "Network Connection",
        //QString("Selected Network is:        %1").arg(s));

    // connect to the selected network
    //auto session = new QNetworkSession(cfg, this);
    //session->open();

    // go to keyboard class to enter password
    PreviousScreen = "SelectNetwork";
    ui->stackedWidget->setCurrentIndex(1);

}

void SelectNetwork::goToSelectNetwork()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SelectNetwork::isConnectionValid(QString pw)
{
    qDebug() << pw;
}
