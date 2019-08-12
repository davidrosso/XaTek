#ifndef SELECTNETWORK_H
#define SELECTNETWORK_H

#include <QWidget>
#include <keyboard.h>

namespace Ui {
class SelectNetwork;
}

class SelectNetwork : public QWidget
{
    Q_OBJECT

public:
    explicit SelectNetwork(QWidget *parent = 0);
    ~SelectNetwork();

private:
    Ui::SelectNetwork *ui;
    Keyboard _keyboard;

private slots:
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();

signals:
    void SettingsOptionsClicked();
    void BackToConnectivity();

};

#endif // SELECTNETWORK_H
