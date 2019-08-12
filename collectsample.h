#ifndef COLLECTSAMPLE_H
#define COLLECTSAMPLE_H

#include <QWidget>
#include <verifyclotchip.h>

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

signals:
    void PreheatClotChip();

};

#endif // COLLECTSAMPLE_H
