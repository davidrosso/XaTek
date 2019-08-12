#ifndef TESTINPROGRESS_H
#define TESTINPROGRESS_H

#include <QWidget>

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

signals:
    void VerifyClotChip();
};

#endif // TESTINPROGRESS_H
