#include "mainwindow.h"
#include <QFile>
#include <QFileInfo>
#include <QDir>

extern QString DateTimeFormat;
extern QString ConfigFilePath;
extern QString AdminPasscode;
extern QString UserPasscode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set the toolbar title
    setWindowTitle("XaTek Blood Analyzer");

    // set the background gradient image from resource file
    QPixmap bkgnd("://Images/XatekUI_Backdrop.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    // set the menu options image from resource file
    ui->pushButtonOptionsMenu->setIcon(QIcon("://Images/XatekUI_OptionsMenu.png"));

    // create xml file to store passcodes and connectivity settings
    QFile file(ConfigFilePath);
    if(file.exists())
    {
        // open and read settings from the XaTek config file and get key/value pairs
        ReadConfigXML();
    }
    else
    {
        InitializeConfigXML();
    }

    // setup the timer to display current time
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(setTimer()));
    timer->start(100);

    //TODO: get the Battery Level from the harware and display the appropriate image
    //setBatteryImage(GetBatteryLevel());

    // for now set the battery level to zero
    BatteryLevel = 0;
    SetBatteryImage(BatteryLevel);

    //TODO: get test in progress status from firmware
    //bool TestInProgress = GetStatus();

    // for now set the progress status to true
    TestInProgress = true;

    // set the image based on the results of the GetBatteryLevel() and GetStatus() results
    SetButtonActionImage();

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);    
    ui->stackedWidget->insertWidget(1, &_settingOptionsForm);
    ui->stackedWidget->insertWidget(2, &_passcodeUnlock);
    ui->stackedWidget->insertWidget(3, &_openScanClotChip);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::InitializeConfigXML()
{
    // write XML
    QDomDocument xmlConfigDoc;

    // create root element and add to the XML file    
    QDomElement root = xmlConfigDoc.createElement("XaTek_Config");
    root.setAttribute("created", QDateTime::currentDateTime().toString(DateTimeFormat));    
    xmlConfigDoc.appendChild(root);

    // add the elements under the root element    
    QDomElement AdminNode = xmlConfigDoc.createElement("Admin_Passcode");
    AdminNode.setAttribute("modified", QDateTime::currentDateTime().toString(DateTimeFormat));
    QDomText AdminPasscode = xmlConfigDoc.createTextNode(QString(""));
    AdminNode.appendChild(AdminPasscode);
    root.appendChild(AdminNode);

    // add the elements under the root element
    QDomElement UserNode = xmlConfigDoc.createElement("User_Passcode");
    UserNode.setAttribute("modified", QDateTime::currentDateTime().toString(DateTimeFormat));
    QDomText UserPasscode = xmlConfigDoc.createTextNode(QString(""));
    UserNode.appendChild(UserPasscode);
    root.appendChild(UserNode);

    // add the elements under the root element
    QDomElement WifiNode = xmlConfigDoc.createElement("WiFi");
    WifiNode.setAttribute("value", "");
    root.appendChild(WifiNode);

    QDomElement BluetoothNode = xmlConfigDoc.createElement("Bluetooth");
    BluetoothNode.setAttribute("value", "");
    root.appendChild(BluetoothNode);

    //write the XML file
    QFile file(ConfigFilePath);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing";
    }
    else
    {
        QTextStream stream(&file);
        stream << xmlConfigDoc.toString();
        file.close();
    }
}


void MainWindow::ReadConfigXML()
{
    QFile xmlFile (ConfigFilePath);

    if (!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this,"Load XML File Problem", "Couldn't open xmlfile.xml to load settings for download", QMessageBox::Ok);
        return;
    }

    xmlReader.setDevice(&xmlFile);

    //Parse the XML until we reach end of it
    while(!xmlReader.atEnd() && !xmlReader.hasError())
    {
        // Read next element
        QXmlStreamReader::TokenType token = xmlReader.readNext();

        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }

        //If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement)
        {
            if(xmlReader.name() == "Admin_Passcode")
            {
                QString passcodeValue = xmlReader.readElementText();

                AdminPasscode = QString (passcodeValue);
                //qDebug() << "User_Passcode: " + passcodeValue;
            }

            if(xmlReader.name() == "User_Passcode")
            {
                QString passcodeValue = xmlReader.readElementText();

                UserPasscode = QString (passcodeValue);
                //qDebug() << "User_Passcode: " + passcodeValue;
            }

            if(xmlReader.name() == "WiFi")
            {
                //qDebug() << "WiFi: " + xmlReader.readElementText();
            }

            if(xmlReader.name() == "Bluetooth")
            {
                //qDebug() << "Bluetooth: " + xmlReader.readElementText();
            }
        }
    }
}


void MainWindow::setTimer()
{
    QTime currentTime = QTime::currentTime();
    QString currentTimeStr = currentTime.toString("hh:mm");

    // remove leading zero when time is before noon
    if(currentTime.hour() < 10)
    {
        currentTimeStr[0] = ' ';
    }

    //TODO: get the Battery Level from the harware and display the appropriate image
    //setBatteryImage(GetBatteryLevel())

    //TODO: set the battery changing icon if device is charging
    //bool isCharging = IsDeviceCharging();

    // for now, display the battery charging icon have the colon blink
    if((currentTime.second() % 2) == 0)
    {
        currentTimeStr[2] = ' ';

        ui->labelBatteryCharge->show();
    }
    else
    {
        // battery icon to blink is level 'to low'
        if(BatteryLevel < 900)
        {
            ui->labelBatteryCharge->hide();
        }
    }

    ui->labelTime->setText(currentTimeStr);

    QDate currentDate = QDate::currentDate();
    QString currentDateStr = currentDate.toString("MM/dd/yy");
    ui->labelDate->setText(currentDateStr);

    BatteryLevel = BatteryLevel+2;
    SetBatteryImage(BatteryLevel);

    if(BatteryLevel >= 450)
    {
        TestInProgress = false;
    }

    SetButtonActionImage();
}


void MainWindow::GetBatteryLevel()
{
    //TODO: get the battery level
}

void MainWindow::SetBatteryImage(int batteryLevel)
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // GUI will display battery level in margin at all times.

    // setup the appropriate battery image from resource file
    // there are 5 battery level images (0%, 25%, 50%, 75%, 100%)

    if(batteryLevel < 250)
    {
        // per 11114-0016_01 ClotChip Software Requirements Specification.docx
        // Software shall notify the user via the GUI when the battery is low.

        QPixmap pixBattery("://Images/XatekUI_Battery00.png");
        ui->labelBatteryLevelImage->setPixmap(pixBattery);

        //TODO: what to do if battery level is below minimum value while working in the setup of a new test.
    }
    else if(batteryLevel > 250 && batteryLevel <= 500)
    {
        QPixmap pixBattery("://Images/XatekUI_Battery25.png");
        ui->labelBatteryLevelImage->setPixmap(pixBattery);
    }
    else if(batteryLevel > 500 && batteryLevel <= 750)
    {
        QPixmap pixBattery("://Images/XatekUI_Battery50.png");
        ui->labelBatteryLevelImage->setPixmap(pixBattery);
    }    
    else if(batteryLevel > 750 && batteryLevel <= 900)
    {
        QPixmap pixBattery("://Images/XatekUI_Battery75.png");
        ui->labelBatteryLevelImage->setPixmap(pixBattery);
    }
    else if(batteryLevel > 900)
    {
        QPixmap pixBattery("://Images/XatekUI_Battery100.png");
        ui->labelBatteryLevelImage->setPixmap(pixBattery);

        // for now, hide the battery charging icon since we are fully charged.
        ui->labelBatteryCharge->hide();
    }
}

void MainWindow::SetButtonActionImage()
{
    if(BatteryLevel < 250)
    {
        QPixmap pixmap("://Images/XatekUI_BatteryNeedsCharge.png");
        QIcon buttonIcon(pixmap);
        ui->buttonAction->setIcon(buttonIcon);
        ui->buttonAction->show();
        ActionTaken = 0;
    }
    else if(TestInProgress == true)
    {
        QPixmap pixmap("://Images/XatekUI_CancelTestInProgress.png");
        QIcon buttonIcon(pixmap);
        ui->buttonAction->setIcon(buttonIcon);
        ui->buttonAction->show();
        ActionTaken = 1;
    }
    else
    {
        QPixmap pixmap("://Images/XatekUI_Unlock.png");
        QIcon buttonIcon(pixmap);
        ui->buttonAction->setIcon(buttonIcon);
        ui->buttonAction->show();
        ActionTaken = 2;
    }
}

void MainWindow::on_buttonAction_clicked()
{
    //TODO: check if settings are complete before
    if( SettingOptionsComplete() == true )
    {
        switch(ActionTaken)
        {
            case 0:
            case 1:
            case 2:
            default:
                ui->stackedWidget-> setCurrentIndex(2);
                break;
        }
    }
}

void MainWindow::on_buttonTestInProgress_clicked()
{
    QMessageBox::information(this,
        tr("Battery Level Low"),
        tr("The battery level is to low to continue.\nPlease charge the device.") );
}

void MainWindow::on_buttonUnlockKeypad_clicked()
{

}

void MainWindow::BackToMainWindowClick()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonOptionsMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

bool MainWindow::SettingOptionsComplete()
{
    bool okToContinue = true;

    //qDebug() << "Admin_Passcode: " + AdminPasscode;
    //qDebug() << "User_Passcode: " + UserPasscode;

    // check admin passcode is set
    if(AdminPasscode == "")
    {
        QMessageBox::information(this,
            tr("Setup not Complete"),
            tr("The Admin Passcode must be set before the device can be used. Please access the Option Menu and setup the Admin Passcode.") );

        okToContinue = false;
    }

    // check user passcode is set
    else if(UserPasscode == "")
    {
        QMessageBox::information(this,
            tr("Setup not Complete"),
            tr("The User Passcode must be set before the device can be used.\n\nPlease access the Option Menu and setup the User Passcode.") );

        okToContinue = false;
    }

    // check connectivity is setup (Wifi/Bluetooth)
    //TODO: Check the connectivity setup

    return okToContinue;
}





















