#include "serviceform.h"

ServiceForm::ServiceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceForm)
{
    ui->setupUi(this);

    ServiceNeeded(-1);
}

ServiceForm::~ServiceForm()
{
    delete ui;
}

void ServiceForm::on_buttonServiceRcr_clicked()
{
    ServiceNeeded(0);    
}

void ServiceForm::on_buttonServiceDockingStation_clicked()
{
    ServiceNeeded(1);    
}

void ServiceForm::ServiceNeeded(int val)
{
    _serviceNeeded = val;
    // reset all buttons
    ui->buttonServiceRcr->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonServiceDockingStation->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );

    switch(val)
    {
        case 0:
            // highlight weekly button
            _serviceNeededStr = "RCR";
            ui->buttonServiceRcr->setStyleSheet( "QAbstractButton{ color: white; font-weight: bold; font-size: 50px; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
            break;

        case 1:
            // highlight biweekly button
            _serviceNeededStr = "Docking Station";
            ui->buttonServiceDockingStation->setStyleSheet( "QAbstractButton{ color: white; font-weight: bold; font-size: 50px; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
            break;

        default:
            ui->buttonServiceRcr->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );
            ui->buttonServiceDockingStation->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    }
}

void ServiceForm::on_buttonBack_clicked()
{
    // return to the Settings Menu
    emit SettingsOptionsClicked();
}

void ServiceForm::on_buttonEnter_clicked()
{
    QMessageBox::information (this, "Service",
         QString("Service Needed for:  %1").arg(QString(_serviceNeededStr)));

    // return to the Settings Menu
    emit SettingsOptionsClicked();
}
