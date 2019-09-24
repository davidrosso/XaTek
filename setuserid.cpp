#include "setuserid.h"

extern QString PreviousScreen;
extern QString TestData_User_ID_Source;
extern QString TestData_User_ID;

SetUserID::SetUserID(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUserID)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_EnterUserID.png");
    ui->labelUserID->setPixmap(pix);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);    
    ui->stackedWidget->insertWidget(1, &_keyboardUser);
    ui->stackedWidget->insertWidget(2, &_setPatientID);

    connect(&_keyboardUser, SIGNAL(SetUserID()), this, SLOT(SetUserID_click()));
    connect(&_setPatientID, SIGNAL(SetUserID()), this, SLOT(SetUserID_click()));
    connect(&_setPatientID, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
    connect(&_keyboardUser, SIGNAL(goToUserID()),
                 this, SLOT(goingToUserID())
                );
    connect(&_keyboardUser, SIGNAL(goToSetPatientID()),
                 this, SLOT(goingToPatientID())
                );
}

SetUserID::~SetUserID()
{
    delete ui;
}

void SetUserID::SetUserID_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SetUserID::on_buttonManual_clicked()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will permit users to scan or manually enter information such as Patient ID, User ID.

    // set PreviousScreen variable
    PreviousScreen = "SetUserID";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    // go to the keyboard class to manual enter the User ID
    ui->stackedWidget->setCurrentIndex(1);
}

void SetUserID::on_buttonScan_clicked()
{        
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will permit users to scan or manually enter information such as Patient ID, User ID.

    // set PreviousScreen variable
    PreviousScreen = "SetUserID";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    TestData_User_ID_Source = QString ("scanned");
    //TODO: set the scanned user ID
    //TestData_User_ID = getUserID();
    TestData_User_ID = QString ("User ID");

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(2);
}

void SetUserID::on_buttonBack_clicked()
{
    // return to previous screen (InsertClotChip)
    emit InsertClotChip();
}

void SetUserID::goingToPasscode()
{
    //qDebug() << "Slot from SetUserID Called";
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}

void SetUserID::goingToUserID()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SetUserID::goingToPatientID()
{
    ui->stackedWidget->setCurrentIndex(2);
}
