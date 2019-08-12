#include "qualityassuranceform.h"
#include "ui_qualityassuranceform.h"
#include <QMessageBox>

QualityAssuranceForm::QualityAssuranceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QualityAssuranceForm)
{
    ui->setupUi(this);

    // TODO: get the Quality Asurrence setting from the firmware and hightlight the setting    
    //integer GetQualityAssurance();

    // set the Quality Assurance value from firmware, for now set to 1 (Bi-weekly).
    UpdateQualityAssurance(1);

}

QualityAssuranceForm::~QualityAssuranceForm()
{
    delete ui;
}

void QualityAssuranceForm::on_buttonQualityWeekly_clicked()
{
    UpdateQualityAssurance(0);
}

void QualityAssuranceForm::on_buttonQualityBiweekly_clicked()
{
    UpdateQualityAssurance(1);
}

void QualityAssuranceForm::on_buttonQualityMonthly_clicked()
{
    UpdateQualityAssurance(2);
}

void QualityAssuranceForm::on_buttonQualityQuarterly_clicked()
{
    UpdateQualityAssurance(3);
}

void QualityAssuranceForm::UpdateQualityAssurance(int val)
{
    QualityAssuranceSetting = val;

    // reset all buttons
    ui->buttonQualityWeekly->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonQualityBiweekly->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonQualityMonthly->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonQualityQuarterly->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); font-weight: normal; font-size: 40px; border-width: 0px; border-style: solid; border-color: rgb(87, 138, 198); }" );

    switch(val)
    {
        case 0:
            // highlight weekly button
            QualityAssuranceSettingStr = "Weekly";
            ui->buttonQualityWeekly->setStyleSheet( "QAbstractButton{ color: white; font-weight: bold; font-size: 50px; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
            break;

        case 1:
            // highlight biweekly button
            QualityAssuranceSettingStr = "Biweekly";
            ui->buttonQualityBiweekly->setStyleSheet( "QAbstractButton{ color: white; font-weight: bold; font-size: 50px; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
            break;

        case 2:
            // highlight monthly button          
            QualityAssuranceSettingStr = "Monthly";
            ui->buttonQualityMonthly->setStyleSheet( "QAbstractButton{ color: white; font-weight: bold; font-size: 50px; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
            break;

        case 3:
            // highlight quarterly button
            QualityAssuranceSettingStr = "Quarterly";
            ui->buttonQualityQuarterly->setStyleSheet( "QAbstractButton{ color: white; font-weight: bold; font-size: 50px; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
            break;
    }
}


void QualityAssuranceForm::on_buttonBack_clicked()
{
    // return to the Settings Menu
    emit SettingsOptionsClicked();
}

void QualityAssuranceForm::on_buttonEnter_clicked()
{
   QMessageBox::information (this, "Quality Assurance",
        QString("Quality Assurance Set to:  %1").arg(QString(QualityAssuranceSettingStr)));

//   QDate date = QDate::fromString(text);
//           int age = computeAge(date);
//           QMessageBox::information (0, "The Age",
//                                     QString("The age is %1").arg(QString::number(age)));

    // TODO: set the quality assurance
    // 0 = Weekly
    // 1 = Bi-Weekly
    // 2 = Monthly
    // 3 = Quarterly
    //SetQualityAssurance(QualityAssuranceSetting);

    // return to the Settings Menu
    emit SettingsOptionsClicked();
}
