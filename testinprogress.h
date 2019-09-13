#ifndef TESTINPROGRESS_H
#define TESTINPROGRESS_H
#include <QWidget>
#include <QTimer>
#include <QThread>
#include "testcomplete.h"
#include "ui_testinprogress.h"

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

private slots:
    void TestComputations();

signals:
    void VerifyClotChip();
    void HomeClicked();

};

#endif // TESTINPROGRESS_H
