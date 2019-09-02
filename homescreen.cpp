#include "homescreen.h"
#include "ui_homescreen.h"
#include <QDateTime>
#include <QDebug>
extern QString PreviousScreen;

HomeScreen::HomeScreen(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);

    // set the toolbar title
    setWindowTitle("XaTek Blood Analyzer");

    // button image from resource file
    ui->buttonStartNewTest->setIcon(QIcon("://Images/XatekUI_StartNewTest.png"));
    ui->buttonViewTestResults->setIcon(QIcon("://Images/XatekUI_ViewTestResults.png"));

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_openScanClotChip);
    ui->stackedWidget->insertWidget(2, &_viewTestResultsForm);
    ui->stackedWidget->insertWidget(3, &_settingOptionsForm);
    ui->stackedWidget->insertWidget(4, &_testResultDetails);


    connect(&_openScanClotChip, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&_viewTestResultsForm, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&_settingOptionsForm, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&_testResultDetails, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
}

HomeScreen::~HomeScreen()
{
    delete ui;
}

void HomeScreen::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void HomeScreen::on_buttonStartNewTest_clicked()
{  
    // set PreviousScreen variable
    PreviousScreen = "HomeScreen";

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // Prior to a test commencing, the user will be informed if there is not sufficient battery charge to complete a test.
    //TODO: do not start a test until the device is paired with at least 1 docking station.
    //int batteryLevel = GetBatteryLevel();

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // Prior to a test commencing, the user will be informed if there is not sufficient memory to complete a test
    //TODO: check for sufficient memory
    //int memoryLevel = GetMemoryLevel();

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will not allow the user to start a test until at least one docking station pairing has been completed.
    //TODO: get list of paired docking station
    //ArrayList dockStations = GetPairedDevices();

    // proceed to next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void HomeScreen::on_buttonViewTestResults_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
