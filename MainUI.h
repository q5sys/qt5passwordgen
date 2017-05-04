#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>

namespace Ui {
    class MainUI;
}

class MainUI : public QMainWindow {
    Q_OBJECT

public:
    MainUI();
    ~MainUI();

public slots:
    void makePass();
    void copyPass();

private:
    Ui::MainUI *ui;

protected:
    QString makePwd(QString chars, int length);
};

#endif
