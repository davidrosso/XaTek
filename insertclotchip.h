#ifndef INSERTCLOTCHIP_H
#define INSERTCLOTCHIP_H

#include <QWidget>
#include <QDialog>
#include <QMovie>
#include <setuserid.h>

namespace Ui {
class InsertClotChip;
}

class InsertClotChip : public QWidget
{
    Q_OBJECT

public:
    explicit InsertClotChip(QWidget *parent = 0);
    ~InsertClotChip();

private:
    Ui::InsertClotChip *ui;   
    SetUserID _setUserID;

private slots:    
    void on_buttonNext_clicked();
    void on_buttonBack_clicked();    
    void InsertClotChip_click();

signals:
    void HomeClicked();
    void SettingsOptionsClicked();
    void OpenScanClotChip();

};

#endif // INSERTCLOTCHIP_H
