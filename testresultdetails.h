#ifndef TESTRESULTDETAILS_H
#define TESTRESULTDETAILS_H

#include <QWidget>

namespace Ui {
class TestResultDetails;
}

class TestResultDetails : public QWidget
{
    Q_OBJECT

public:
    explicit TestResultDetails(QWidget *parent = 0);
    ~TestResultDetails();

private slots:
    void on_buttonBack_clicked();

    void on_buttonDone_clicked();

private:
    Ui::TestResultDetails *ui;
};

#endif // TESTRESULTDETAILS_H
