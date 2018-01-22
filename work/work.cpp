/************************************************************
- Copyright (C), 2017-2018, JACK-IOT
- FileName: work.cpp
- Author:  maojy    Version : V4.0       Date: 2017-12-14
- Description:     Work piece interface display and jump with other interfaces
- Version:         V4.0
- Function List:
  1.connect(work_timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //Timing function of the timer slot function binding
- History:
        <author>  <time>   <version >           <desc>
         maojy   17-12-14     4.0       Add logo and icon display
         maojy   17-12-07     3.0    Implement this process to communicate with other processes by way of POSIX shared memory, using sem semaphores for synchronization protection
         maojy   17-11-28     2.0    Using a custom signal slot connection, to achieve the jump between the various interfaces;
         maojy   17-11-23     1.0    Use controls and code to adjust the form to build each interface
***********************************************************/
#include "work.h"
#include "ui_work.h"
#include "mainwindow.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <stdio.h>
#include <QPainter>


work::work(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::work)
{
    ui->setupUi(this);
    //setGeometry(0,0,800,480);
    my_messagebox= new QMessageBox;
    QFont font;
    font.setPointSize(24);
    /*锁眼个数显示*/
    ui->suoyan->display(0);
    ui->suoyan->setFont(font);
    ui->suoyan_text->setText("锁眼：");
    ui->suoyan_text->setFont(font);
    ui->suoyan_num->setText("个");
    ui->suoyan_num->setFont(font);

    /*件数显示*/
    ui->jianshu->display(0);
    ui->jianshu->setFont(font);
    ui->jianshu_text->setText("件数：");
    ui->jianshu_text->setFont(font);
    ui->jianshu_num->setText("件");
    ui->jianshu_num->setFont(font);

    /*归零按钮*/
    ui->suoyan0->setIconSize(QSize(88,44));    //模式选择
    ui->suoyan0->setIcon(QIcon(":/png/image/edit-delete.png"));
    ui->jianshu0->setIconSize(QSize(88,44));    //模式选择
    ui->jianshu0->setIcon(QIcon(":/png/image/edit-delete.png"));


    /*返回模式选择按钮*/

    ui->back->setIconSize(QSize(81,81));
    ui->back->setIcon(QIcon(":/png/image/home_81.png"));
    ui->show->setIconSize(QSize(81,81));
    ui->show->setIcon(QIcon(":/png/image/menu.png"));
    ui->set->setIconSize(QSize(81,81));
    ui->set->setIcon(QIcon(":/png/image/set_81.png"));

    work_timer=new QTimer;
    connect(work_timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    work_timer->start(15);

   // ui->back->setFont(font);


}

void work::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/png/image/background.png");
    painter.drawPixmap(0,0,800,480,pix);
}


extern SHAREDATA *read_data;
void work::timerUpDate(void)
{
/*
    sem_wait(sem_val);
    ui->suoyan->display(read_data->suoyan);
    ui->jianshu->display(read_data->jianshu);
    sem_post(sem_val);
*/
}




work::~work()
{
    delete ui;
}

void work::on_suoyan0_clicked()
{
    QPushButton yesButton ;
    QPushButton cancelButton ;
    yesButton.setText("确定");
    cancelButton.setText("取消");
    my_messagebox->addButton(&yesButton,QMessageBox::AcceptRole);
    my_messagebox->addButton(&cancelButton,QMessageBox::RejectRole);

    my_messagebox->setText("确定清零锁眼数量吗？");
    my_messagebox->setIcon(QMessageBox::Warning);
    int ret=my_messagebox->exec();
    if(ret==QMessageBox::AcceptRole)
    {
/*
        sem_wait(sem_val);
        read_data->suoyan=0;
        sem_post(sem_val);*/
    }
    else if(ret==QMessageBox::RejectRole)
    {

    }



}

void work::on_jianshu0_clicked()
{
    QPushButton yesButton ;
    QPushButton cancelButton ;
    yesButton.setText("确定");
    cancelButton.setText("取消");
    my_messagebox->addButton(&yesButton,QMessageBox::AcceptRole);
    my_messagebox->addButton(&cancelButton,QMessageBox::RejectRole);
    my_messagebox->setText("确定清零件数吗？");
    my_messagebox->setIcon(QMessageBox::Warning);
    int ret=my_messagebox->exec();

    if(ret==QMessageBox::AcceptRole)
    {/*
        sem_wait(sem_val);
        read_data->jianshu=0;
        sem_post(sem_val);*/
    }
    else if(ret==QMessageBox::RejectRole)
    {

    }

}

void work::on_back_clicked()
{
   emit display(0);
}

void work::on_show_clicked()
{
    emit display(2);
}



void work::on_set_clicked()
{
    emit display(3);
}
