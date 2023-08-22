#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "register.h"
#include "algorithm"

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
    addActWindowptr=new AddActivity(this);
    addActWindowptr->show();
    connect(addActWindowptr,&AddActivity::isClosed,this,&MainWindow::slotUpdateRegister);
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
}




void MainWindow::on_pushButton_clicked()
{
    Register newregister(ui->inputDate->date().year(),ui->inputDate->date().month(),ui->inputDate->date().day());
    int provindex=0;
    bool posfound=false;
    std::vector<Register>::iterator it;
    /*it=registers.begin();
    if(it!=registers.end()){
    while(it!=registers.end()){
        qDebug()<<"CycleEntered";
        if((it->getYear()<newregister.getYear())||((it->getYear()==newregister.getYear())&&(it->getMonth()<newregister.getMonth()))||
           ((it->getYear()==newregister.getYear())&&(it->getMonth()==newregister.getMonth())&&(it->getDay()<newregister.getDay()))){
            it++;
        }
        else if (!posfound){
            qDebug()<<"option4";
            provindex=it-registers.begin();
            posfound=true;
            it++;
        } else{
            qDebug()<<"option5";
            registers.resize(registers.size()+1);
            registers.insert(it,*(it-1));
        }
        it=registers.begin();
        for(int i=0;i!=provindex;i++){
            it++;
        }
         registers.insert(it,newregister);
    }
    }else{
        registers.push_back(newregister);
    }*/
    registers.push_back(newregister);

    std::sort(registers.begin(),registers.end());

    for(it=registers.begin();it!=registers.end();it++){
        if(((it)->getYear()==newregister.getYear())&&((it)->getMonth()==newregister.getMonth())&&((it)->getDay()==newregister.getDay())){
            provindex=it-registers.begin();
        }
    }


    qDebug()<<"You have created a new register, number is"<<newregister.getNumber();
    QString registerDescr=QString::number(ui->inputDate->date().day())+"/"+
            QString::number(ui->inputDate->date().month())+"/"+
            QString::number(ui->inputDate->date().year());
    ui->dateSelector->insertItem(provindex,registerDescr);
    //ui->dateSelector->addItem(registerDescr);

}


void MainWindow::on_cleanBoard_clicked()
{
    ui->outputText->clear();
}

