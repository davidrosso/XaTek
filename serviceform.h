#ifndef SERVICEFORM_H
#define SERVICEFORM_H

#include <QWidget>
#include <QMessageBox>
#include "ui_serviceform.h"

namespace Ui {
class ServiceForm;
}

class ServiceForm : public QWidget
{
    Q_OBJECT

public:
    explicit ServiceForm(QWidget *parent = 0);
    ~ServiceForm();

private:
    Ui::ServiceForm *ui;
    int _serviceNeeded;
    QString _serviceNeededStr;

private slots:
    void on_buttonServiceRcr_clicked();
    void on_buttonServiceDockingStation_clicked();
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();
    void ServiceNeeded(int);

signals:
    void SettingsOptionsClicked();
};

#endif // SERVICEFORM_H
