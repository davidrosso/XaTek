#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QThread>
#include <QMessageBox>
#include <QPlainTextEdit>

extern QString my_global_string;

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

    // setup the timer to display current time
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(setTimer()));
    timer->start(100);

    // TODO: get the Battery Level from the harware and display the appropriate image
    //setBatteryImage(GetBatteryLevel());

    // for now set the battery level to zero
    BatteryLevel = 0;
    SetBatteryImage(BatteryLevel);

    // TODO: get test in progress status from firmware
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

void MainWindow::setTimer()
{
    QTime currentTime = QTime::currentTime();
    QString currentTimeStr = currentTime.toString("hh:mm");

    // remove leading zero when time is before noon
    if(currentTime.hour() < 10)
    {
        currentTimeStr[0] = ' ';
    }

    // TODO: get the Battery Level from the harware and display the appropriate image
    //setBatteryImage(GetBatteryLevel())

    //TODO: determine if device is charging, if so then display the battery charging icon
    // TODO: set the battery changing icon
    // bool isCharging = IsDeviceCharging();

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
