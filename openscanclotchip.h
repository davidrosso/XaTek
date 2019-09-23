#ifndef OPENSCANCLOTCHIP_H
#define OPENSCANCLOTCHIP_H

#include <QWidget>
#include <QDialog>
#include <QMovie>
#include <QMessageBox>
#include <QDebug>
#include "insertclotchip.h"
#include "ui_openscanclotchip.h"

namespace Ui {
class OpenScanClotChip;
}

class OpenScanClotChip : public QWidget
{
    Q_OBJECT

public:
    explicit OpenScanClotChip(QWidget *parent = 0);
    ~OpenScanClotChip();

private:
    Ui::OpenScanClotChip *ui;
    InsertClotChip _insertClotChip;


private slots:
    void on_buttonScan_clicked();
    void on_buttonBack_clicked();
    void OpenScanClotChip_Click();
    void goingToPasscode();

signals:
    void HomeClicked();
    void goToPasscode();

};

#endif // OPENSCANCLOTCHIP_H
