#include "testinprogress.h"

extern QString TestData_Capacitance;
extern QString TestData_PeakTime;
extern QString TestData_PeakTimeUnits;
extern QString TestData_DeltaEpsilon;
extern QString TestData_Capacitance;
extern QString TestData_TestDuration;
extern QString TestData_TestDurationUnits;
extern QString TestData_Errors;
extern QString TestData_CRC;

TestInProgress::TestInProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestInProgress)
{
    ui->setupUi(this);

    testInProgressTimer = new QTimer(this);
    connect(testInProgressTimer, SIGNAL(timeout()), this,SLOT(TestTimer()));
    testInProgressTimer->start();

    // setup the image from resource file
    //QPixmap pix("://Images/XatekUI_VerifyingClotChip.png");
    //ui->labelVerifyClotChip->setPixmap((pix.scaled(575,685)));

    // setup signals and slots for navigation
    //ui->stackedWidget->setCurrentIndex(0);
    //ui->stackedWidget->insertWidget(1, &_testInProgress);

    //TODO: get any errors detected during the test
    //ArrayList TestCapacitanceValues =  GetTestCapacitanceValues();

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_testComplete);
}

TestInProgress::~TestInProgress()
{
    delete ui;
}

void TestInProgress::TestTimer()
{       
    //TODO: implement the following requirements

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If the initial capacitance readings of the ClotChip are out of range, then the user is warned and the workflow is stopped.
    //The range of the initial capacitance reading are:
        // 10 kHz signal frequency - 15 nF to 26 nF
        // 100 kHz signal frequency - 1.4 nF to 2.6 nF
        // 1 MHz signal frequency - 130 pF to 250 pF
        // 2 MHz signal frequency - 70 pF to 120 pF
        // 5 MHz signal frequency - 30 pF to 45 pF

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // If the rate of change of the capacitance values for the first 30 seconds are not between 0.2 pF/sec and 0.8 pF/sec, then the user is warned and the workflow is stopped.

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If the magnitude of the rate of change of the capacitance values after the first 30 seconds is greater than 0.8 pF/sec, then the user is warned and the workflow is stopped

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If the temperature of the RCR is not within 37C +/- 0.5 C within 25 seconds of starting the readings then the user is warned and the workflow is stopped.

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If the temperature of the RCR drifts by +/- 0.5 C during the test, the user is warned and the workflow is stopped.

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If the user does not acknowledge the countdown screen of 30 seconds to “collect blood, examine for large air bubbles, and properly seat the ClotChip,” the user is warned and the blood test is voided.

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //If user the time since last successful QA check has expired, the user is not allowed to start a test


    TestDuration = TestDuration + 1;

    // for now, display the test in progress screen for 15 seconds and then automatically transition to the "TestComplete" screen
    if(TestDuration >= 1500000)
    {
        TestComputations();

        ui->stackedWidget->setCurrentIndex(1);
    }
}

void TestInProgress::TestComputations()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software shall allow calibration of the capacitance values.
    // The calibration will be performed at 5 frequencies and with an average of 100 data points per frequency.

    //TODO: get the capacitance values (one each second)
    //ArrayList TestCapacitanceValues =  GetTestCapacitanceValues();

    // for now, just create a generic test data record
    TestData_Capacitance        = "capacitance values (one each second of test)";
    TestData_PeakTime           = "calculated from capacitance";
    TestData_PeakTimeUnits      = "seconds";
    TestData_DeltaEpsilon       = "calculated from capacitance";
    TestData_TestDuration       = "15";
    TestData_TestDurationUnits  = "seconds";
    TestData_Errors             = "error codes from test";
    TestData_CRC                = "SHA-256 hash";
}
