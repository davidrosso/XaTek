#include "viewtestresultsform.h"
#include "ui_viewtestresultsform.h"
#include <QMessageBox>

ViewTestResultsForm::ViewTestResultsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewTestResultsForm)
{
    ui->setupUi(this);

    //TODO: get a list of the completed tests
    //GetCompletedTests();

    // for now, just populate some generic networks
    QListWidgetItem *item1 = new QListWidgetItem("March 13  10:20    Patient ID #");
    item1 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetTestsToReview->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem("March 22  23:30    Patient ID #");
    item2 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetTestsToReview->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem("April 8  3:15      Patient ID #");
    item3 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetTestsToReview->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem("April 21  16:30    Patient ID #");
    item4 ->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->listWidgetTestsToReview->addItem(item4);

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    //ui->stackedWidget->insertWidget(1, &_testResultDetails);


    //connect(&_testResultDetails, SIGNAL(s), this, SLOT(Confirmed_click()));


}

ViewTestResultsForm::~ViewTestResultsForm()
{
    delete ui;
}

void ViewTestResultsForm::on_buttonConfirm_clicked()
{
    if(ui->listWidgetTestsToReview->currentItem())
    {
        const QString& s = ui->listWidgetTestsToReview->currentItem()->text();

         QMessageBox::information(this, "Review Test",
             QString("Selected test to review is:\n        %1").arg(s));

         //ui->stackedWidget->setCurrentIndex(1);

         hide(); // hide the current ViewTestResultsForm
         _testResultDetails = new TestResultDetails(this);
         _testResultDetails->show();

    }
}



void ViewTestResultsForm::on_buttonBack_clicked()
{
    // return to previous screen (MainWindow)
    emit HomeClicked();
}
