#ifndef PREHEATCLOTCHIP_H
#define PREHEATCLOTCHIP_H

#include <QWidget>
#include <collectsample.h>

namespace Ui {
class PreheatClotchip;
}

class PreheatClotchip : public QWidget
{
    Q_OBJECT

public:
    explicit PreheatClotchip(QWidget *parent = 0);
    ~PreheatClotchip();

private:
    Ui::PreheatClotchip *ui;
    CollectSample _collectSample;

private slots:
    void on_buttonNext_clicked();
    void on_buttonBack_clicked();
    void PreheatClotChip_click();

signals:
    void PreparePatient();

};

#endif // PREHEATCLOTCHIP_H
