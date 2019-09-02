#ifndef DISPLAYFORMS_H
#define DISPLAYFORMS_H

#include <QWidget>

namespace Ui {
class DisplayForms;
}

class DisplayForms : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayForms(QWidget *parent = 0);
    ~DisplayForms();

    int brightnessLevel = 0;
    int powerSavingTimer = 0;
    QString powerSavingMin = "";
    QString powerSavingSec = "";

private:
    Ui::DisplayForms *ui;

private slots:
    void updatePowerSavingSetting(int);
    void updateBrightnessSetting(int);
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();
    void on_buttonTimeOut1_clicked();
    void on_buttonTimeOut2_clicked();
    void on_buttonTimeOut3_clicked();
    void on_buttonTimeOut4_clicked();
    void on_buttonTimeOut5_clicked();
    void on_buttonTimeOut6_clicked();
    void on_buttonTimeOut7_clicked();
    void on_buttonTimeOut8_clicked();
    void on_buttonTimeOut9_clicked();
    void on_buttonTimeOut10_clicked();

    void on_buttonBrightness1_clicked();
    void on_buttonBrightness2_clicked();
    void on_buttonBrightness3_clicked();
    void on_buttonBrightness4_clicked();
    void on_buttonBrightness5_clicked();
    void on_buttonBrightness6_clicked();
    void on_buttonBrightness7_clicked();
    void on_buttonBrightness8_clicked();
    void on_buttonBrightness9_clicked();
    void on_buttonBrightness10_clicked();
    void on_buttonBrightness11_clicked();
    void on_buttonBrightness12_clicked();
    void on_buttonBrightness13_clicked();
    void on_buttonBrightness14_clicked();
    void on_buttonBrightness15_clicked();
    void on_buttonBrightness16_clicked();
    void on_buttonBrightness17_clicked();
    void on_buttonBrightness18_clicked();
    void on_buttonBrightness19_clicked();
    void on_buttonBrightness20_clicked();

signals:
    void SettingsOptionsClicked();
    //void HomeClicked();
};

#endif // DISPLAYFORMS_H
