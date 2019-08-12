#include "homescreen.h"
#include "ui_homescreen.h"
#include <QDateTime>

HomeScreen::HomeScreen(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);

    // set the toolbar title
    setWindowTitle("XaTek Blood Analyzer");

    // button image from resource file
    ui->buttonStartNewTest->setIcon(QIcon("://Images/XatekUI_StartNewTest.png"));
    ui->buttonViewTestResults->setIcon(QIcon("://Images/XatekUI_ViewTestResults.png"));

    // setup signals and slots for navigation
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_openScanClotChip);
    ui->stackedWidget->insertWidget(2, &_viewTestResultsForm);

    connect(&_openScanClotChip, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&_viewTestResultsForm, SIGNAL(HomeClicked()), this, SLOT(moveHome()));

}

HomeScreen::~HomeScreen()
{
    delete ui;
}

void HomeScreen::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void HomeScreen::on_buttonStartNewTest_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void HomeScreen::on_buttonViewTestResults_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
