#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QWidget>
#include <openscanclotchip.h>
#include <viewtestresultsform.h>
#include <settingoptionsform.h>

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

private slots:
    void on_buttonStartNewTest_clicked();
    void on_buttonViewTestResults_clicked();
    void moveHome();

signals:
    void SettingsOptionsClicked();

};

#endif // HOMESCREEN_H
