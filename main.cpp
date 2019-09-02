#include "mainwindow.h"
#include <QApplication>
#include <QtXml>
#include <QDebug>

/**************************************************************************
 * Test Record Consists of the following information
 * and will be stored as global variables below and then set throughout the application.
    ClotChip ID
    RCR ID
    Device ID
    Organization ID
    User ID
    Patient ID
    Date and time of the start of the test
    Hours since last dose
    Time to peak in seconds
    Delta epsilon in normalized real permittivity
    Capacitance values recorded during the test (one each second)
    Duration of the test in seconds
    Any errors detected during the test
    Hash value of the data packet
*
***************************************************************************/

QString PreviousScreen;
QString TestData_ClotChip_ID;                           // set in OpenScanClotChip
QString TestData_RCR_ID;                                // set in InsertClotChip
QString TestData_Device_ID;                             // set in OpenScanClotChip
QString TestData_Organization_ID;                       // set in OpenScanClotChip
QString TestData_User_ID_Source;                        // set in SetUserID
QString TestData_User_ID;                               // set in SetUserID
QString TestData_Patient_ID_Source;                     // set in SetPatientID
QString TestData_Patient_ID;                            // set in SetPatientID
QString TestData_DateTimeTestStart;                     // set in TimeLastDose
QString TestData_DateTimeLastDose;                      // set in TimeLastDose
QString TestData_HoursSinceLastDose;                    // set in TimeLastDose
QString TestData_PeakTimeInSeconds = "Calculated from Capacitance";
QString TestData_PeakTimeUnits = "Seconds";             // set in
QString TestData_DeltaEpsilon = "Calculated from Capacitance";
QString TestData_Capacitance;                           // set in
QString TestData_TestDurationInSeconds;                 // set in
QString TestData_TestDurationUnits = "Seconds";         // set in
QString TestData_Errors = "Error Codes from Test";      // set in
QString TestData_CRC = "SHA-256 hash";                  // set in
QString DateTimeFormat = "yyyy-MM-dd HH:mm:ss";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
