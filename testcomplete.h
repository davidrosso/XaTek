#ifndef TESTCOMPLETE_H
#define TESTCOMPLETE_H

#include <QWidget>

namespace Ui {
class TestComplete;
}

class TestComplete : public QWidget
{
    Q_OBJECT

public:
    explicit TestComplete(QWidget *parent = 0);
    ~TestComplete();

private slots:
    void on_buttonUnlock_clicked();
    void CreateTestDataXML();

private:
    Ui::TestComplete *ui;
};

#endif // TESTCOMPLETE_H
