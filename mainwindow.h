#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <passcodeunlock.h>
#include <openscanclotchip.h>
#include <settingoptionsform.h>

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

signals:
    void SettingsOptionsClicked();

};

#endif // MAINWINDOW_H
