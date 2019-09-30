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

    QStringList ssidList = myOutput.split(" ");

    ui->WifiList->addItems(ssidList);
}

void SelectNetwork::on_buttonBack_clicked()
{    
    // return to the previous screen
    emit BackToConnectivity();
}

void SelectNetwork::on_buttonEnter_clicked()
{    
    ssid =ui->WifiList->currentItem()->text();

    // go to keyboard to enter password
    PreviousScreen = "SelectNetwork";
    ui->stackedWidget->setCurrentIndex(1);
}

void SelectNetwork::goToSelectNetwork()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SelectNetwork::isConnectionValid(QString pw)
{
    QProcess myProcess;
    QString myOutput;
    QString processString = "nmcli d wifi connect " + ssid + " password " + pw;
    myProcess.start(processString);
    myProcess.waitForFinished(-1);

    myProcess.start("iw wlan0 link");
    myProcess.waitForFinished(-1);
    myOutput = myProcess.readAllStandardOutput().trimmed();
    myProcess.close();

    if(myOutput == "Not connected.")
    {
        QString errorOutput = "Incorrect password for network \"" + ssid + "\"";
        QMessageBox::information(
          this,
          tr("Could not connect"),
          tr(errorOutput.toUtf8()) );
    }
    else
    {
        qDebug() << "Successfully connected to Wifi";
        ui->stackedWidget->setCurrentIndex(0);
        emit BackToConnectivity();
    }
}
