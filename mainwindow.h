#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QThread>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtXml>
#include <QDebug>
#include <QProcess>
#include <QTime>
#include <QDate>
#include "passcodeunlock.h"
#include "openscanclotchip.h"
#include "settingoptionsform.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;
    int BatteryLevel;
    bool TestInProgress;
    int ActionTaken;

private:
    Ui::MainWindow *ui;
    SettingOptionsForm _settingOptionsForm;
    PasscodeUnlock _passcodeUnlock;
    OpenScanClotChip _openScanClotChip;
    QXmlStreamReader xmlReader;
    QTime currentTime;

public slots:
    void setTimer();

private slots:
    void on_pushButtonOptionsMenu_clicked();
    void on_buttonAction_clicked();    
    void on_buttonTestInProgress_clicked();
    void on_buttonUnlockKeypad_clicked();
    void GetBatteryLevel();
    void SetBatteryImage(int);
    void SetButtonActionImage();
    void BackToMainWindowClick();
    bool SettingOptionsComplete();
    void InitializeConfigXML();
    void ReadConfigXML();
    void backToHome_clicked();

signals:
    void SettingsOptionsClicked();
    void sendToPasscodeUnlock();

};

#endif // MAINWINDOW_H
