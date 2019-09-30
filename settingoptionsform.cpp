#include "settingoptionsform.h"
#include "homescreen.h"

SettingOptionsForm::SettingOptionsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingOptionsForm)
{
    ui->setupUi(this);

    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // GUI will provide menus to affect power management, connectivity to WIFI and BT, user instruction options such as option to bypass non-critical instructions, time management settings, brightness settings, and QA Check frequency.

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &_setAdminPasscode);
    ui->stackedWidget->insertWidget(2, &_setUserPasscode);
    ui->stackedWidget->insertWidget(3, &_displayForms);
    ui->stackedWidget->insertWidget(4, &_dateTimeForms);
    ui->stackedWidget->insertWidget(5, &_connectivityForm);
    ui->stackedWidget->insertWidget(6, &_qualityAssuranceForm);
    ui->stackedWidget->insertWidget(7, &_serviceForms);
    ui->stackedWidget->insertWidget(8, &_selectNetwork);
    ui->stackedWidget->insertWidget(9, &_bluetoothPairing);

    connect(&_setAdminPasscode, SIGNAL(SettingsOptionsClicked()), this, SLOT(moveToSettingsOptions()));
    connect(&_setUserPasscode, SIGNAL(SettingsOptionsClicked()), this, SLOT(moveToSettingsOptions()));
    connect(&_displayForms, SIGNAL(SettingsOptionsClicked()), this, SLOT(moveToSettingsOptions()));
    connect(&_dateTimeForms, SIGNAL(SettingsOptionsClicked()), this, SLOT(moveToSettingsOptions()));
    connect(&_connectivityForm, SIGNAL(SettingsOptionsClicked()), this, SLOT(moveToSettingsOptions()));
    connect(&_qualityAssuranceForm, SIGNAL(SettingsOptionsClicked()), this, SLOT(moveToSettingsOptions()));
    connect(&_serviceForms, SIGNAL(SettingsOptionsClicked()), this, SLOT(moveToSettingsOptions()));
}

SettingOptionsForm::~SettingOptionsForm()
{
    delete ui;
}

void SettingOptionsForm::moveToSettingsOptions()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SettingOptionsForm::on_buttonAdminPasscode_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SettingOptionsForm::on_buttonUserPasscode_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void SettingOptionsForm::on_buttonDisplaySettings_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void SettingOptionsForm::on_buttonDateTime_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void SettingOptionsForm::on_buttonConnectivity_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void SettingOptionsForm::on_buttonQuality_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void SettingOptionsForm::on_buttonService_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void SettingOptionsForm::on_buttonBack_clicked()
{
    emit goHome();
}
