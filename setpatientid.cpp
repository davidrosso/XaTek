#include "setpatientid.h"

extern QString PreviousScreen;
extern QString TestData_Patient_ID_Source;
extern QString TestData_Patient_ID;

SetPatientID::SetPatientID(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetPatientID)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_EnterPatientID.png");
    ui->labelPatientID->setPixmap(pix);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_keyboardPatient);
    ui->stackedWidget->insertWidget(2, &_timeLastDose);

    connect(&_keyboardPatient, SIGNAL(SetPatientID()), this, SLOT(SetPatientID_click()));
    connect(&_timeLastDose, SIGNAL(SetPatientID()), this, SLOT(SetPatientID_click()));
    connect(&_timeLastDose, SIGNAL(goToPasscode()),
                 this, SLOT(goingToPasscode())
                );
    connect(&_keyboardPatient, SIGNAL(goToPatientID()),
                 this, SLOT(goingToPatientID())
                );
    connect(&_keyboardPatient, SIGNAL(goToTimeLastDose()),
                 this, SLOT(goToTimeLastDose())
                );
}

SetPatientID::~SetPatientID()
{
    delete ui;
}

void SetPatientID::SetPatientID_click()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SetPatientID::on_buttonManual_clicked()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will permit users to scan or manually enter information such as Patient ID, User ID.

    // set PreviousScreen variable
    PreviousScreen = "SetPatientID";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    // go to the keyboard class to manual enter the Patient ID
    ui->stackedWidget->setCurrentIndex(1);

}

void SetPatientID::on_buttonScan_clicked()
{
    // set PreviousScreen variable
    PreviousScreen = "SetPatientID";
    //qDebug() << "previous screen: " + PreviousScreen.toUtf8();

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software will permit users to scan or manually enter information such as Patient ID, User ID.

    TestData_Patient_ID_Source = QString ("scanned");

    //TODO: set the scanned patient ID
    //TestData_Patient_ID = getPatientID();
    TestData_Patient_ID = QString ("Patient ID");

    // proceed to the next screen
    ui->stackedWidget->setCurrentIndex(2);
}

void SetPatientID::on_buttonBack_clicked()
{
    // return to previous screen (SetUserID)
    emit SetUserID();
}

void SetPatientID::goingToPasscode()
{
    //qDebug() << "Slot from SetPatientID Called";
    ui->stackedWidget->setCurrentIndex(0);
    emit goToPasscode();
}

void SetPatientID::goingToPatientID()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SetPatientID::goToTimeLastDose()
{
    ui->stackedWidget->setCurrentIndex(2);
}
