#ifndef VERIFYCLOTCHIP_H
#define VERIFYCLOTCHIP_H
#include <QWidget>
#include <QMessageBox>
#include <QtXml>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include "testinprogress.h"
#include "ui_verifyclotchip.h"

namespace Ui {
class VerifyClotChip;
}

class VerifyClotChip : public QWidget
{
    Q_OBJECT

public:
    explicit VerifyClotChip(QWidget *parent = 0);
    ~VerifyClotChip();

private:
    Ui::VerifyClotChip *ui;
    TestInProgress _testInProgress;

private slots:
    void on_buttonBack_clicked();
    void on_buttonNext_clicked();
    void VerifyClotChip_click();
    void goingToPasscode();

signals:
    void CollectSample();
    void goToPasscode();

};

#endif // VERIFYCLOTCHIP_H
