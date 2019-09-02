#ifndef QUALITYASSURANCEFORM_H
#define QUALITYASSURANCEFORM_H

#include <QWidget>

namespace Ui {
class QualityAssuranceForm;
}

class QualityAssuranceForm : public QWidget
{
    Q_OBJECT

public:
    explicit QualityAssuranceForm(QWidget *parent = 0);
    ~QualityAssuranceForm();

private:
    Ui::QualityAssuranceForm *ui;
    int QualityAssuranceSetting;
    QString QualityAssuranceSettingStr;

private slots:
    void on_buttonQualityWeekly_clicked();
    void on_buttonQualityBiweekly_clicked();
    void on_buttonQualityMonthly_clicked();
    void on_buttonQualityQuarterly_clicked();
    void on_buttonBack_clicked();
    void on_buttonEnter_clicked();
    void UpdateQualityAssurance(int);

signals:
    //void HomeClicked();
    void SettingsOptionsClicked();
};

#endif // QUALITYASSURANCEFORM_H
