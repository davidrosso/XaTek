#include "viewtestresultsform.h"

ViewTestResultsForm::ViewTestResultsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewTestResultsForm)
{
    ui->setupUi(this);

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The GUI will provide menus to view past blood test results and QA check results on the Device’s memory.
    //TODO: get a list of the completed tests

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    //The device will display the following info to the user at the end of a blood test
    //•	User ID
    //•	Patient ID
    //•	Hours since last dose
    //•	Time to peak in seconds
    //•	Date and time of the test start
    //•	Duration of the test in seconds
    //TODO: display tests results

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
    ui->stackedWidget->insertWidget(1, &_testResultDetails);

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

        //QMessageBox::information(this, "Review Test",
        //    QString("Selected test to review is:\n        %1").arg(s));

         //TODO: pass the selected test (patient ID) to the TestResultDetail page
         // for now, results are hard-coded on the TestResultDetail page
         ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::information(this, "Select Test",
            QString("Selected test to review and 'Confirm'"));
    }
}

void ViewTestResultsForm::on_buttonBack_clicked()
{
    // return to home screen
    emit HomeClicked();
}
