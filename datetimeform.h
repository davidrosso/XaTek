#ifndef DATETIMEFORM_H
#define DATETIMEFORM_H

#include <QWidget>
#include <QModelIndexList>

namespace Ui {
class DateTimeForm;
}

class DateTimeForm : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString saveMonth MEMBER month)
    Q_PROPERTY(QString saveDay MEMBER day)

public:
    explicit DateTimeForm(QWidget *parent = 0);
    ~DateTimeForm();
    QString month, day, hour, minute;

private:
    Ui::DateTimeForm *ui;
    QModelIndexList *indexes;
    std::string timezone;

private slots:
    void updateSettings();
    void updateMonth(QString in);
    void updateDay(QString in);
    void updateHour(QString in);
    void updateMinute(QString in);
    void updateTimezone(QString in);
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();

signals:
    void SettingsOptionsClicked();    
};

#endif // DATETIMEFORM_H
