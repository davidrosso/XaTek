#ifndef TESTRESULTDETAILS_H
#define TESTRESULTDETAILS_H

#include <QWidget>
#include "ui_testresultdetails.h"

namespace Ui {
class TestResultDetails;
}

class TestResultDetails : public QWidget
{
    Q_OBJECT

public:
    explicit TestResultDetails(QWidget *parent = 0);    
    ~TestResultDetails();

private:
    Ui::TestResultDetails *ui;
    QString _patientID;

private slots:
    void on_buttonBack_clicked();
    void on_buttonDone_clicked();

signals:
    void HomeClicked();

};

#endif // TESTRESULTDETAILS_H
