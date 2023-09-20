#include "removeactivity.h"
#include "ui_removeactivity.h"

removeActivity::removeActivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeActivity)
{
    ui->setupUi(this);
}

removeActivity::~removeActivity()
{
    delete ui;
}

void removeActivity::on_closeButton_clicked()
{
    close();
}


void removeActivity::on_resetButton_clicked()
{
    QTime baseValue(0,0,0);
    ui->inputDescr->clear();
    ui->inputStartTime->setTime(baseValue);
    ui->inputEndTime->setTime(baseValue);
}


void removeActivity::on_confirmButton_clicked()
{
    Activity*toRemoveAct;
    toRemoveAct=new Activity();
    toRemoveAct->setDescription(ui->inputDescr->text().toStdString());
    toRemoveAct->setStartHh(ui->inputStartTime->time().hour());
    toRemoveAct->setStartMm(ui->inputStartTime->time().minute());
    toRemoveAct->setEndHh(ui->inputEndTime->time().hour());
    toRemoveAct->setEndMm(ui->inputEndTime->time().minute());
    close();
    emit isClosed();
}

