#include "testcomplete.h"
#include "passcodeunlock.h"

extern QString PreviousScreen;
extern QString TestRecordFilePath;
extern QString TestData_ClotChip_ID;
extern QString TestData_RCR_ID;
extern QString TestData_Device_ID;
extern QString TestData_Organization_ID;
extern QString TestData_User_ID_Source;
extern QString TestData_User_ID;
extern QString TestData_Patient_ID_Source;
extern QString TestData_Patient_ID;
extern QString TestData_DateTimeTestStart;
extern QString TestData_DateTimeLastDose;
extern QString TestData_HoursSinceLastDose;
extern QString TestData_PeakTimeUnits;
extern QString TestData_PeakTime;
extern QString TestData_DeltaEpsilon;
extern QString TestData_Capacitance;
extern QString TestData_TestDuration;
extern QString TestData_TestDurationUnits;
extern QString TestData_Errors;
extern QString TestData_CRC;
extern QString DateTimeFormat;

TestComplete::TestComplete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestComplete)
{
    ui->setupUi(this);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    //ui->stackedWidget->insertWidget(1, &_passcodeunlock);

    //connect(&_passcodeunlock, SIGNAL(SetUserID()), this, SLOT(SetUserID_click()));
}

TestComplete::~TestComplete()
{
    delete ui;
}

void TestComplete::on_buttonUnlock_clicked()
{
    // create XML test data record
    CreateTestDataXML();

    // go to home screen
    //ui->stackedWidget->setCurrentIndex(0); //Go to passcode unlock screen
    ui->stackedWidget->lower();
    emit goToPasscode();
    //qDebug("TestComplete Signal 1");

}

void TestComplete::CreateTestDataXML()
{
    // write XML
    QDomDocument xmlDoc;

    //QDomElement encoding = xmlDoc.createElement("?xml version="1.0" encoding="UTF-8"?");
    //xmlDoc.appendChild(encoding);

    // create root element and add to the XML file
    QDomElement root = xmlDoc.createElement("TestDate");
    root.setAttribute("created", QDateTime::currentDateTime().toString(DateTimeFormat));
    xmlDoc.appendChild(root);

    // add the test data elements under the root element
    QDomElement ClotChip_ID_Node = xmlDoc.createElement("ClotChip_ID");
    ClotChip_ID_Node.setAttribute("value", TestData_ClotChip_ID);
    root.appendChild(ClotChip_ID_Node);

    QDomElement RCR_ID_Node = xmlDoc.createElement("RCR_ID");
    RCR_ID_Node.setAttribute("value", TestData_RCR_ID);
    root.appendChild(RCR_ID_Node);

    QDomElement Device_ID_Node = xmlDoc.createElement("Device_ID");
    Device_ID_Node.setAttribute("value", TestData_Device_ID);
    root.appendChild(Device_ID_Node);

    QDomElement Organization_ID_Node = xmlDoc.createElement("Organization_ID");
    Organization_ID_Node.setAttribute("value", TestData_Organization_ID);
    root.appendChild(Organization_ID_Node);

    QDomElement User_ID_Node = xmlDoc.createElement("User_ID");
    User_ID_Node.setAttribute("source", TestData_User_ID_Source);
    User_ID_Node.setAttribute("value", TestData_User_ID);
    root.appendChild(User_ID_Node);

    QDomElement Patient_ID_Node = xmlDoc.createElement("Patient_ID");
    Patient_ID_Node.setAttribute("source", TestData_Patient_ID_Source);
    Patient_ID_Node.setAttribute("value", TestData_Patient_ID);
    root.appendChild(Patient_ID_Node);

    QDomElement DateTimeLastDose_Node = xmlDoc.createElement("Last_Dose_Date_Time");
    DateTimeLastDose_Node.setAttribute("value", TestData_DateTimeLastDose);
    root.appendChild(DateTimeLastDose_Node);

    QDomElement Start_DateTime_Node = xmlDoc.createElement("Start_Test_Date_Time");
    Start_DateTime_Node.setAttribute("value", TestData_DateTimeTestStart);
    root.appendChild(Start_DateTime_Node);

    QDomElement Hours_Since_Last_Dose_Node = xmlDoc.createElement("Hours_Since_Last_Dose");
    Hours_Since_Last_Dose_Node.setAttribute("value", TestData_HoursSinceLastDose);
    root.appendChild(Hours_Since_Last_Dose_Node);

    QDomElement Peak_Time_In_Seconds_Node = xmlDoc.createElement("Time_To_Peak");
    Peak_Time_In_Seconds_Node.setAttribute("units", TestData_PeakTimeUnits);
    Peak_Time_In_Seconds_Node.setAttribute("value", TestData_PeakTime);
    root.appendChild(Peak_Time_In_Seconds_Node);

    QDomElement Delta_Epsilon_Node = xmlDoc.createElement("Delta_Epsilon");
    Delta_Epsilon_Node.setAttribute("value", TestData_DeltaEpsilon);
    root.appendChild(Delta_Epsilon_Node);

    QDomElement Capacitance_Node = xmlDoc.createElement("Capacitance");
    Capacitance_Node.setAttribute("value", TestData_Capacitance);
    root.appendChild(Capacitance_Node);

    QDomElement Test_Duration_In_Seconds_Node = xmlDoc.createElement("Test_Duration");
    Test_Duration_In_Seconds_Node.setAttribute("units", TestData_TestDurationUnits);
    Test_Duration_In_Seconds_Node.setAttribute("value", TestData_TestDuration);

    root.appendChild(Test_Duration_In_Seconds_Node);

    QDomElement Errors_Node = xmlDoc.createElement("Errors");
    Errors_Node.setAttribute("value", TestData_Errors);
    root.appendChild(Errors_Node);

    QDomElement CRC_Node = xmlDoc.createElement("Hash_Value");
    CRC_Node.setAttribute("value", TestData_CRC);
    root.appendChild(CRC_Node);

    //write the XML file    
    QFile file(TestRecordFilePath + TestData_Patient_ID + ".xml");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing";
        //return -1;
    }
    else
    {
        QTextStream stream(&file);
        stream << xmlDoc.toString();
        file.close();
    }
}
