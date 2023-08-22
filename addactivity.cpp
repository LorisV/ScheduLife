#include "addactivity.h"
#include "ui_addactivity.h"


AddActivity::AddActivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddActivity)
{
    ui->setupUi(this);
}

AddActivity::~AddActivity()
{
    delete ui;
}

void AddActivity::on_pushButton_2_clicked()
{
    close();
    another=false;
}

void AddActivity::on_pushButton_clicked()
{
    QTime baseValue(0,0,0);
    ui->inputDescr->clear();
    ui->inputStartTime->setTime(baseValue);
    ui->inputEndTime->setTime(baseValue);
}


void AddActivity::on_pushButton_3_clicked()
{
    Activity*newactivity;
    newactivity=new Activity();
    newactivity->setDescription(ui->inputDescr->text().toStdString());
    newactivity->setStartHh(ui->inputStartTime->time().hour());
    newactivity->setStartMm(ui->inputStartTime->time().minute());
    newactivity->setEndHh(ui->inputEndTime->time().hour());
    newactivity->setEndMm(ui->inputEndTime->time().minute());
    ptr=newactivity;
    another=true;
    close();
    emit isClosed();
}

