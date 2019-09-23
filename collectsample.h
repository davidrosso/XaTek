#ifndef COLLECTSAMPLE_H
#define COLLECTSAMPLE_H

#include <QWidget>
#include <QDebug>
#include "verifyclotchip.h"
#include "ui_collectsample.h"

namespace Ui {
class CollectSample;
}

class CollectSample : public QWidget
{
    Q_OBJECT

public:
    explicit CollectSample(QWidget *parent = 0);
    ~CollectSample();

private:
    Ui::CollectSample *ui;
    VerifyClotChip _verifyClotChip;

private slots:
    void on_buttonNext_clicked();
    void on_buttonBack_clicked();
    void CollectSample_click();
    void goingToPasscode();

signals:
    void PreheatClotChip();
    void goToPasscode();

};

#endif // COLLECTSAMPLE_H
