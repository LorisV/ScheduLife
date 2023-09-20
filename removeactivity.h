#ifndef REMOVEACTIVITY_H
#define REMOVEACTIVITY_H

#include <QDialog>
#include "activity.h"

namespace Ui {
class removeActivity;
}

class removeActivity : public QDialog
{
    Q_OBJECT

public:
    explicit removeActivity(QWidget *parent = nullptr);
    ~removeActivity();

signals:
    void isClosed();

private slots:

    void on_closeButton_clicked();

    void on_resetButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::removeActivity *ui;
};

#endif // REMOVEACTIVITY_H
