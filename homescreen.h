#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include "openscanclotchip.h"
#include "settingoptionsform.h"
#include "viewtestresultsform.h"
#include "testresultdetails.h"
#include "ui_homescreen.h"

namespace Ui {
class HomeScreen;
}

class HomeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit HomeScreen(QDialog *parent = nullptr);
    ~HomeScreen();    

private:
    Ui::HomeScreen *ui;
    SettingOptionsForm _settingOptionsForm;
    OpenScanClotChip _openScanClotChip;
    ViewTestResultsForm _viewTestResultsForm;
    TestResultDetails _testResultDetails;

private slots:
    void on_buttonStartNewTest_clicked();
    void on_buttonViewTestResults_clicked();
    void moveHome();

signals:
    void SettingsOptionsClicked();

};

#endif // HOMESCREEN_H
