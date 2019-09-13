#include "displayforms.h"

DisplayForms::DisplayForms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayForms)
{
    ui->setupUi(this);

    // setup the image from resource file
    QPixmap pix("://Images/XatekUI_Brightness.png");
    ui->labelBrightnessIcon->setPixmap(pix.scaled(ui->labelBrightnessIcon->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //TODO: get the Brightness level from firmware
    //integer GetBrightnessLevel();
    updateBrightnessSetting(8); // for now, set to 8

    //TODO: get the screen power saver from firmware
    //int GetScreenPowerSaver();
    updatePowerSavingSetting(3); // for now, set to 3
}

DisplayForms::~DisplayForms()
{
    delete ui;
}

void DisplayForms::on_buttonTimeOut1_clicked()
{
    updatePowerSavingSetting(1);
}

void DisplayForms::on_buttonTimeOut2_clicked()
{
    updatePowerSavingSetting(2);
}

void DisplayForms::on_buttonTimeOut3_clicked()
{
    updatePowerSavingSetting(3);
}

void DisplayForms::on_buttonTimeOut4_clicked()
{
    updatePowerSavingSetting(4);
}

void DisplayForms::on_buttonTimeOut5_clicked()
{
    updatePowerSavingSetting(5);
}

void DisplayForms::on_buttonTimeOut6_clicked()
{
    updatePowerSavingSetting(6);
}

void DisplayForms::on_buttonTimeOut7_clicked()
{
    updatePowerSavingSetting(7);
}

void DisplayForms::on_buttonTimeOut8_clicked()
{
    updatePowerSavingSetting(8);
}

void DisplayForms::on_buttonTimeOut9_clicked()
{
    updatePowerSavingSetting(9);
}

void DisplayForms::on_buttonTimeOut10_clicked()
{
    updatePowerSavingSetting(10);
}

void DisplayForms::updatePowerSavingSetting(int val)
{
    // set the power saving value
    powerSavingTimer = val;

    // reset all buttons
    ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut6->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut7->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut8->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut9->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonTimeOut10->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );

    switch(powerSavingTimer)
    {
        case 1:
            powerSavingMin = "0";
            powerSavingSec = "30";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 2:
            powerSavingMin = "1";
            powerSavingSec = "00";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 3:
            powerSavingMin = "1";
            powerSavingSec = "30";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 4:
            powerSavingMin = "2";
            powerSavingSec = "00";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 5:
            powerSavingMin = "2";
            powerSavingSec = "30";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 6:
            powerSavingMin = "3";
            powerSavingSec = "00";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 7:
            powerSavingMin = "3";
            powerSavingSec = "30";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 8:
            powerSavingMin = "4";
            powerSavingSec = "00";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 9:
            powerSavingMin = "4";
            powerSavingSec = "30";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 10:
            powerSavingMin = "5";
            powerSavingSec = "00";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        default:
            powerSavingTimer = 5;
            powerSavingMin = "2";
            powerSavingSec = "30";
            ui->buttonTimeOut1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonTimeOut5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );

    }

    // update the label
    if(powerSavingSec == "30")
    {
        if(powerSavingMin == "0")
        {
            ui->label->setText(QString("30<span style='font-size:20pt; font-weight:600; color:white;'>sec</span>"));

        }
        else
        {
            ui->label->setText(QString(powerSavingMin + "<span style='font-size:20pt; font-weight:600; color:white;'>min </span>" + powerSavingSec + "<span style='font-size:20pt; font-weight:600; color:white;'>sec</span>"));
        }
    }
    else
    {
        ui->label->setText(QString(powerSavingMin + "<span style='font-size:20pt; font-weight:600; color:white;'>min</span>"));
    }
}


void DisplayForms::on_buttonBrightness1_clicked()
{
    updateBrightnessSetting(1);
}

void DisplayForms::on_buttonBrightness2_clicked()
{
    updateBrightnessSetting(2);
}

void DisplayForms::on_buttonBrightness3_clicked()
{
    updateBrightnessSetting(3);
}

void DisplayForms::on_buttonBrightness4_clicked()
{
    updateBrightnessSetting(4);
}

void DisplayForms::on_buttonBrightness5_clicked()
{
    updateBrightnessSetting(5);
}

void DisplayForms::on_buttonBrightness6_clicked()
{
    updateBrightnessSetting(6);
}

void DisplayForms::on_buttonBrightness7_clicked()
{
    updateBrightnessSetting(7);
}

void DisplayForms::on_buttonBrightness8_clicked()
{
    updateBrightnessSetting(8);
}

void DisplayForms::on_buttonBrightness9_clicked()
{
    updateBrightnessSetting(9);
}

void DisplayForms::on_buttonBrightness10_clicked()
{
    updateBrightnessSetting(10);
}

void DisplayForms::on_buttonBrightness11_clicked()
{
    updateBrightnessSetting(11);
}

void DisplayForms::on_buttonBrightness12_clicked()
{
    updateBrightnessSetting(12);
}

void DisplayForms::on_buttonBrightness13_clicked()
{
    updateBrightnessSetting(13);
}

void DisplayForms::on_buttonBrightness14_clicked()
{
    updateBrightnessSetting(14);
}

void DisplayForms::on_buttonBrightness15_clicked()
{
    updateBrightnessSetting(15);
}

void DisplayForms::on_buttonBrightness16_clicked()
{
    updateBrightnessSetting(16);
}

void DisplayForms::on_buttonBrightness17_clicked()
{
    updateBrightnessSetting(17);
}

void DisplayForms::on_buttonBrightness18_clicked()
{
    updateBrightnessSetting(18);
}

void DisplayForms::on_buttonBrightness19_clicked()
{
    updateBrightnessSetting(19);
}

void DisplayForms::on_buttonBrightness20_clicked()
{
    updateBrightnessSetting(20);
}


void DisplayForms::updateBrightnessSetting(int val)
{
    brightnessLevel = val;

    // reset all buttons
    ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness15->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness16->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness17->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness18->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness19->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );
    ui->buttonBrightness20->setStyleSheet( "QAbstractButton{ color: rgb(208, 225, 241); border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); }" );


    switch (val)
    {
        case 1:
            brightnessLevel = 1;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 2:
            brightnessLevel = 2;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 3:
            brightnessLevel = 3;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 4:
            brightnessLevel = 4;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 5:
            brightnessLevel = 5;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 6:
            brightnessLevel = 6;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 7:
            brightnessLevel = 7;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 8:
            brightnessLevel = 8;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 9:
            brightnessLevel = 9;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 10:
            brightnessLevel = 10;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 11:
            brightnessLevel = 11;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 12:
            brightnessLevel = 12;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 13:
            brightnessLevel = 13;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 14:
            brightnessLevel = 14;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 15:
            brightnessLevel = 15;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness15->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 16:
            brightnessLevel = 16;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness15->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness16->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 17:
            brightnessLevel = 17;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness15->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness16->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness17->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 18:
            brightnessLevel = 18;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness15->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness16->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness17->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness18->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 19:
            brightnessLevel = 19;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness15->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness16->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness17->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness18->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness19->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        case 20:
            brightnessLevel = 20;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness9->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness10->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness11->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness12->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness13->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness14->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness15->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness16->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness17->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness18->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness19->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness20->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

        default:
            brightnessLevel = 8;
            ui->buttonBrightness1->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness2->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness3->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness4->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness5->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness6->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness7->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            ui->buttonBrightness8->setStyleSheet( "QAbstractButton{ color: white; border-width: 1px; border-style: solid; border-color: rgb(87, 138, 198); background-color: white;}" );
            break;

    }
}


void DisplayForms::on_buttonBack_clicked()
{
    // return to the Settings Menu
    emit SettingsOptionsClicked();
}

void DisplayForms::on_buttonEnter_clicked()
{
    QMessageBox::information(this, "Display Settings",
        QString("Brightness set to:        %1\nPower Saving set to:   %2min %3sec").arg(QString::number(brightnessLevel), powerSavingMin, powerSavingSec));

    //TODO set the Brightness level
    //SetBrightnessLevel(int);

    //TODO: set the screen power saver
    //SetScreenPowerSaver(int);

    // return to the Settings Menu
    emit SettingsOptionsClicked();
}
