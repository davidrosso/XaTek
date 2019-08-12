#include "testresultdetails.h"
#include "ui_testresultdetails.h"

TestResultDetails::TestResultDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestResultDetails)
{
    ui->setupUi(this);
}

TestResultDetails::~TestResultDetails()
{
    delete ui;
}

void TestResultDetails::on_buttonBack_clicked()
{

}

void TestResultDetails::on_buttonDone_clicked()
{

}
