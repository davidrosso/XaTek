#ifndef CONNECTIVITYFORM_H
#define CONNECTIVITYFORM_H

#include <QWidget>
#include <selectnetwork.h>
#include <bluetoothpairing.h>

namespace Ui {
class ConnectivityForm;
}

class ConnectivityForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectivityForm(QWidget *parent = 0);
    ~ConnectivityForm();

private:
    Ui::ConnectivityForm *ui;    
    SelectNetwork _selectNetwork;
    BluetoothPairing _bluetoothPairing;

private slots:        
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();
    void on_buttonBluetoothImage_clicked();
    void on_buttonBluetoothText_clicked();
    void on_buttonWifiText_clicked();    
    void on_buttonWifiImage_clicked();
    void SetupWiFi();
    void SetupBluetooth();
    void MoveBack();

signals:
    void SettingsOptionsClicked();

};

#endif // CONNECTIVITYFORM_H
