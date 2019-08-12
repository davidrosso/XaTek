#ifndef PREPAREPATIENT_H
#define PREPAREPATIENT_H

#include <QWidget>
#include <preheatclotchip.h>

namespace Ui {
class PreparePatient;
}

class PreparePatient : public QWidget
{
    Q_OBJECT

public:
    explicit PreparePatient(QWidget *parent = 0);
    ~PreparePatient();

private:
    Ui::PreparePatient *ui;
    PreheatClotchip _preheatClotchip;

private slots:
    void on_buttonNext_clicked();
    void on_buttonBack_clicked();
    void PreparePatient_click();

signals:
    void TimeLastDose();

};

#endif // PREPAREPATIENT_H
