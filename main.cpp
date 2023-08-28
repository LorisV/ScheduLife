#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/img/AppImages/LogoApp.png"));
    w.setWindowTitle("ScheduLife");
    w.show();
    return a.exec();

}
