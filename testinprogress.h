#ifndef TESTINPROGRESS_H
#define TESTINPROGRESS_H
#include <testcomplete.h>
#include <QWidget>
#include <QTimer>

namespace Ui {
class TestInProgress;
}

class TestInProgress : public QWidget
{
    Q_OBJECT

public:
    explicit TestInProgress(QWidget *parent = 0);
    ~TestInProgress();

private:
    Ui::TestInProgress *ui;
    TestComplete _testComplete;
    QTimer *testInProgressTimer;
    int TestDuration = 0;

public slots:
    void TestTimer();

signals:
    void VerifyClotChip();
    void HomeClicked();


};

#endif // TESTINPROGRESS_H
