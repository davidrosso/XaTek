#include "openscanclotchip.h"
#include <QFileInfo>

extern QString PreviousScreen;
extern QString TestData_ClotChip_ID;
extern QString TestData_Organization_ID;
extern QString TestData_RCR_ID;

OpenScanClotChip::OpenScanClotChip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenScanClotChip)
{
    ui->setupUi(this);

//    qDebug() << QCoreApplication::libraryPaths();
//    qDebug() << QMovie::supportedFormats();
//    qDebug() << QLibraryInfo::location(QLibraryInfo::PluginsPath);
//    QFileInfo check_file("://Images/XatekUI_OpenScanClotChip.gif");
//    if(check_file.exists() && check_file.isFile())
//    {
//        qDebug() << "File exists";
//    }
//    else
//    {
//        qDebug() << "File not found";
//    }

    // Load animated GIF
    QMovie* _movie = new QMovie("://Images/XatekUI_OpenScanClotChip.gif");
    if (!_movie->isValid())
    {
        qDebug() << "GIF Failed to load.";
    }
    ui->labelScanClotChip->setMovie(_movie);   
    _movie->setScaledSize(QSize().scaled(575, 785, Qt::KeepAspectRatio));
    _movie->setScaledSize(QSize().transposed());
    _movie->setSpeed(300); // 3x speed
    _movie->start();
    ui->labelScanClotChip->show();

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_insertClotChip);

    connect(&_insertClotChip, SIGNAL(OpenScanClotChip()), this, SLOT(OpenScanClotChip_Click()));
    connect(&_insertClotChip, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
}

OpenScanClotChip::~OpenScanClotChip()
{
    delete ui;
}

void OpenScanClotChip::on_buttonScan_clicked()
{   
    // set PreviousScreen variable
    PreviousScreen = "OpenScanClotChip";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will only permit the device to scan (not manually enter) ClotChips and QA ClotChips for their IDs.
    //TODO: Scan ClotChip
    //ScanClotChipBarcode();
    TestData_ClotChip_ID = QString ("Scanned ClotChip ID");

    //TODO: Get Organization ID set by Admin to identify all devices
    //OrganizationID();
    TestData_Organization_ID = QString ("Organization ID set by Admin");


    //TODO: check that scan was sucessful before proceeding to the next screen
    //bool okToProceed = CheckStatus(current screen ID);

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(1);
}

void OpenScanClotChip::OpenScanClotChip_Click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void OpenScanClotChip::on_buttonBack_clicked()
{
    // return to previous screen (HomeScreen)
    emit HomeClicked();
}

void OpenScanClotChip::goingToPasscode()
{
    //qDebug() << "Slot from OpenScanClotChip Called";
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}
