#include "testresultdetails.h"
#include "ui_testresultdetails.h"

TestResultDetails::TestResultDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestResultDetails)
{
    ui->setupUi(this);

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // Test results for Tpeak shall be displayed in units of minutes and seconds, with precision of seconds.

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);

}

TestResultDetails::~TestResultDetails()
{
    delete ui;
}

void TestResultDetails::on_buttonBack_clicked()
{
    //TODO: return to previous screen
    emit HomeClicked();
}

void TestResultDetails::on_buttonDone_clicked()
{
    //TODO: unsure what action to perform
    emit HomeClicked();
}
