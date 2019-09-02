#ifndef SETTINGOPTIONSFORM_H
#define SETTINGOPTIONSFORM_H

#include <QWidget>
#include <setadminpasscode.h>
#include <setuserpasscode.h>
#include <displayforms.h>
#include <datetimeform.h>
#include <connectivityform.h>
#include <qualityassuranceform.h>
#include <serviceform.h>
#include <selectnetwork.h>
#include <bluetoothpairing.h>

namespace Ui {
class SettingOptionsForm;
}

class SettingOptionsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingOptionsForm(QWidget *parent = 0);
    ~SettingOptionsForm();

private:
    Ui::SettingOptionsForm *ui;
    SetAdminPasscode _setAdminPasscode;
    SetUserPasscode _setUserPasscode;
    DisplayForms _displayForms;
    DateTimeForm _dateTimeForms;
    ConnectivityForm _connectivityForm;
    QualityAssuranceForm _qualityAssuranceForm;
    ServiceForm _serviceForms;
    SelectNetwork _selectNetwork;
    BluetoothPairing _bluetoothPairing;

private slots:
    void on_buttonAdminPasscode_clicked();
    void on_buttonUserPasscode_clicked();
    void on_buttonDisplaySettings_clicked();
    void on_buttonDateTime_clicked();
    void on_buttonConnectivity_clicked();
    void on_buttonQuality_clicked();
    void on_buttonService_clicked();
    void on_buttonBack_clicked();
    void moveToSettingsOptions();

signals:
    void HomeClicked();
};

#endif // SETTINGOPTIONSFORM_H
