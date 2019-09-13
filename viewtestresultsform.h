#ifndef VIEWTESTRESULTSFORM_H
#define VIEWTESTRESULTSFORM_H

#include <QWidget>
#include <QMessageBox>
#include "testresultdetails.h"
#include "ui_viewtestresultsform.h"

namespace Ui {
class ViewTestResultsForm;
}

class ViewTestResultsForm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewTestResultsForm(QWidget *parent = 0);
    ~ViewTestResultsForm();

private:
    Ui::ViewTestResultsForm *ui;
    TestResultDetails _testResultDetails;

private slots:            
    void on_buttonConfirm_clicked();
    void on_buttonBack_clicked();

signals:
    void HomeClicked();
    void SettingsOptionsClicked();

};

#endif // VIEWTESTRESULTSFORM_H
