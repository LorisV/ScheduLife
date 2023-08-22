#ifndef ADDACTIVITY_H
#define ADDACTIVITY_H

#include <QDialog>
#include "activity.h"

namespace Ui {
class AddActivity;
}

class AddActivity : public QDialog
{
    Q_OBJECT

public:
    explicit AddActivity(QWidget *parent = nullptr);
    ~AddActivity();

    Activity*getActivity(){
        return ptr;
    }

    bool isNew(){
        return another;
    }

    void setAnother(bool anthr){
        another=anthr;
    }

signals:
    void isClosed();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddActivity *ui;
    Activity*ptr;
    bool another=false;
};

#endif // ADDACTIVITY_H
