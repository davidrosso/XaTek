#ifndef SELECTNETWORK_H
#define SELECTNETWORK_H

#include <QWidget>
#include <QTimer>
#include <QList>
#include <QInputDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QProcess>
#include "keyboard.h"
#include "ui_selectnetwork.h"

namespace Ui {
class SelectNetwork;
}

class SelectNetwork : public QWidget
{
    Q_OBJECT

public:
    explicit SelectNetwork(QWidget *parent = 0);
    ~SelectNetwork();
    //int foundCount;
    //QNetworkConfiguration netcfg;
    //QStringList WiFisList;
    //QList<QNetworkConfiguration> netcfgList;

private:
    Ui::SelectNetwork *ui;
    Keyboard _keyboardNetwork;
    QTimer *findTimer;
    QNetworkSession *session;
    QString ssid;

private slots:
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();
    void FindActiveWirelessNetworks();
    void goToSelectNetwork();
    void isConnectionValid(QString pw);
signals:
    void SettingsOptionsClicked();
    void BackToConnectivity();

};

#endif // SELECTNETWORK_H
