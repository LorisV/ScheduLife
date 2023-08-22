#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addactivity.h"
#include "register.h"
#include "vector"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonNewActivity_clicked();

    void on_readActivity_clicked();

    void on_pushButton_clicked();

    void on_cleanBoard_clicked();

public slots:
    void slotUpdateRegister();

    void changeSelectedRegister();

private:
    Ui::MainWindow *ui;
    AddActivity*addActWindowptr;
    std::vector<Register> registers;
};
#endif // MAINWINDOW_H
