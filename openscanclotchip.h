#ifndef OPENSCANCLOTCHIP_H
#define OPENSCANCLOTCHIP_H

#include <QWidget>
#include <QDialog>
#include <QMovie>
#include <insertclotchip.h>

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

signals:
    void HomeClicked();

};

#endif // OPENSCANCLOTCHIP_H
