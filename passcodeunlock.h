#ifndef PASSCODEUNLOCK_H
#define PASSCODEUNLOCK_H

#include <QWidget>
#include "homescreen.h"

namespace Ui {
class PasscodeUnlock;
}

class PasscodeUnlock : public QWidget
{
    Q_OBJECT

public:
    explicit PasscodeUnlock(QWidget *parent = nullptr);
    ~PasscodeUnlock();    QTimer *timer;
    int batteryLevel;
    int adminPasscode;
    int userPasscode;
    int enteredPasscode;

private:
    Ui::PasscodeUnlock *ui;
    HomeScreen _homeScreen;
    SettingOptionsForm _settingOptionsForm;

private slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_button0_clicked();
    void moveHomeScreen();
    void on_buttonBack_clicked();   
    void checkPasscode(QString);
    void on_buttonUnlock_clicked();

signals:
    void HomeClicked();
    void SettingsOptionsClicked();
};

#endif // PASSCODEUNLOCK_H
