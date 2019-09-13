#ifndef BLUETOOTHPAIRING_H
#define BLUETOOTHPAIRING_H

#include <QWidget>
#include <QMessageBox>
#include "ui_bluetoothpairing.h"

namespace Ui {
class BluetoothPairing;
}

class BluetoothPairing : public QWidget
{
    Q_OBJECT

public:
    explicit BluetoothPairing(QWidget *parent = 0);
    ~BluetoothPairing();

private:
    Ui::BluetoothPairing *ui;

private slots:
    void on_buttonEnter_clicked();
    void on_buttonBack_clicked();

signals:
    void BackToConnectivity();

};

#endif // BLUETOOTHPAIRING_H
