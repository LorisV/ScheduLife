#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "register.h"
#include "algorithm"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonNewActivity_clicked()
{
    if(registers.empty()){
        QMessageBox::critical(this,"Error","Create a day to schedule before");
    }
    else{
    addActWindowptr=new AddActivity(this);
    addActWindowptr->setWindowTitle("Add an Activity");
    addActWindowptr->show();
    connect(addActWindowptr,&AddActivity::isClosed,this,&MainWindow::slotUpdateRegister);
    }
}

void MainWindow::slotUpdateRegister(){

    if(addActWindowptr->isNew()){
    registers[ui->dateSelector->currentIndex()].createActivity(*addActWindowptr->getActivity());
    addActWindowptr->setAnother(false);
    }
}





void MainWindow::on_readActivity_clicked(){

    connect(ui->dateSelector,SIGNAL(activated(int)),this,SLOT(changeSelectedRegister()));
    QString txtprint;
    txtprint=registers[ui->dateSelector->currentIndex()].readScheduledActivities();
    ui->outputText->insertPlainText(txtprint);
}

void MainWindow::changeSelectedRegister(){
    ui->outputText->clear();
    QString txtprint;
    txtprint=registers[ui->dateSelector->currentIndex()].readScheduledActivities();
    ui->outputText->insertPlainText(txtprint);
}




void MainWindow::on_pushButton_clicked()
{
    Register newregister(ui->inputDate->date().year(),ui->inputDate->date().month(),ui->inputDate->date().day());
    int provindex=0;
    bool posfound=false;
    std::vector<Register>::iterator it;

    for(it=registers.begin();it!=registers.end();it++){
        if(((it)->getYear()==newregister.getYear())&&((it)->getMonth()==newregister.getMonth())&&((it)->getDay()==newregister.getDay())){
            QMessageBox::critical(this,"Warning","This register is already existent");
            return;
         }
     }

    registers.push_back(newregister);
    std::sort(registers.begin(),registers.end());

    for(it=registers.begin();it!=registers.end();it++){
        if(((it)->getYear()==newregister.getYear())&&((it)->getMonth()==newregister.getMonth())&&((it)->getDay()==newregister.getDay())){
            provindex=it-registers.begin();
        }
    }


    qDebug()<<"You have created a new register";
    QString registerDescr=QString::number(ui->inputDate->date().day())+"/"+
            QString::number(ui->inputDate->date().month())+"/"+
            QString::number(ui->inputDate->date().year());
    ui->dateSelector->insertItem(provindex,registerDescr);
}


void MainWindow::on_cleanBoard_clicked()
{
    ui->outputText->clear();
}

