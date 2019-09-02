#ifndef VERIFYCLOTCHIP_H
#define VERIFYCLOTCHIP_H
#include <QWidget>
#include <testinprogress.h>

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
    //QString format;

private slots:
    void on_buttonBack_clicked();
    void on_buttonNext_clicked();
    void VerifyClotChip_click();
    //void CreateTestDataXML();

signals:
    void CollectSample();

};

#endif // VERIFYCLOTCHIP_H
