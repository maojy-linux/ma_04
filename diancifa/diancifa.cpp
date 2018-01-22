/************************************************************
- Copyright (C), 2017-2018, JACK-IOT
- FileName: diancifa.cpp
- Author:  maojy    Version : V4.0       Date: 2017-12-14
- Description:     Solenoid valve interface display and jump to other interfaces
- Version:         V4.0
- Function List:
  1.connect(group_5, SIGNAL(buttonClicked(int)), this, SLOT(group_5_clicked(int)));
    //Radio button grouping binding
- History:
        <author>  <time>   <version >           <desc>
         maojy   17-12-14     4.0       Add logo and icon display
         maojy   17-12-07     3.0    Implement this process to communicate with other processes by way of POSIX shared memory, using sem semaphores for synchronization protection
         maojy   17-11-28     2.0    Using a custom signal slot connection, to achieve the jump between the various interfaces;
         maojy   17-11-23     1.0    Use controls and code to adjust the form to build each interface
***********************************************************/
#include "diancifa.h"
#include "ui_diancifa.h"
#include <stdio.h>
#include <QPainter>
#include "mainwindow.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>

extern SHAREDATA *read_data;
extern sem_t *sem_val;
diancifa::diancifa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::diancifa)
{
    ui->setupUi(this);
    ui->back->setIconSize(QSize(81,81));
    ui->back->setIcon(QIcon(":/png/image/home_81.png"));
    ui->x->setIconSize(QSize(81,81));
    ui->x->setIcon(QIcon(":/png/image/x.png"));
    ui->y->setIconSize(QSize(81,81));
    ui->y->setIcon(QIcon(":/png/image/y.png"));

    ui->radioButton->setIconSize(QSize(30,30));
    ui->radioButton_2->setIconSize(QSize(30,30));
    ui->radioButton_3->setIconSize(QSize(30,30));
    ui->radioButton_4->setIconSize(QSize(30,30));
    ui->radioButton_5->setIconSize(QSize(30,30));
    ui->radioButton_6->setIconSize(QSize(30,30));
    ui->radioButton_7->setIconSize(QSize(30,30));
    ui->radioButton_8->setIconSize(QSize(30,30));
    ui->radioButton_9->setIconSize(QSize(30,30));
    ui->radioButton_10->setIconSize(QSize(30,30));
    ui->radioButton_11->setIconSize(QSize(30,30));
    ui->radioButton_12->setIconSize(QSize(30,30));
    ui->radioButton->setIcon(QIcon(":/png/image/greenStone_1.png"));
    ui->radioButton_3->setIcon(QIcon(":/png/image/media-record_1.png"));
    ui->radioButton_5->setIcon(QIcon(":/png/image/media-record_1.png"));
    ui->radioButton_7->setIcon(QIcon(":/png/image/media-record_1.png"));
    ui->radioButton_9->setIcon(QIcon(":/png/image/media-record_1.png"));
    ui->radioButton_11->setIcon(QIcon(":/png/image/media-record_1.png"));

    ui->radioButton_2->setIcon(QIcon(":/png/image/media-record_1.png"));
    ui->radioButton_4->setIcon(QIcon(":/png/image/greenStone_1.png"));
    ui->radioButton_6->setIcon(QIcon(":/png/image/greenStone_1.png"));
    ui->radioButton_8->setIcon(QIcon(":/png/image/greenStone_1.png"));
    ui->radioButton_10->setIcon(QIcon(":/png/image/greenStone_1.png"));
    ui->radioButton_12->setIcon(QIcon(":/png/image/greenStone_1.png"));

    group_1 = new QButtonGroup; //新建分组
    group_1->addButton(ui->radioButton,1);
    group_1->addButton(ui->radioButton_2,2);
    connect(group_1, SIGNAL(buttonClicked(int)), this, SLOT(group_1_clicked(int)));

    group_2 = new QButtonGroup; //新建分组
    group_2->addButton(ui->radioButton_3,3);
    group_2->addButton(ui->radioButton_4,4);
    connect(group_2, SIGNAL(buttonClicked(int)), this, SLOT(group_2_clicked(int)));

    group_3 = new QButtonGroup; //新建分组
    group_3->addButton(ui->radioButton_5,5);
    group_3->addButton(ui->radioButton_6,6);
    connect(group_3, SIGNAL(buttonClicked(int)), this, SLOT(group_3_clicked(int)));

    group_4 = new QButtonGroup; //新建分组
    group_4->addButton(ui->radioButton_7,7);
    group_4->addButton(ui->radioButton_8,8);
    connect(group_4, SIGNAL(buttonClicked(int)), this, SLOT(group_4_clicked(int)));

    group_5 = new QButtonGroup; //新建分组
    group_5->addButton(ui->radioButton_9,9);
    group_5->addButton(ui->radioButton_10,10);
    connect(group_5, SIGNAL(buttonClicked(int)), this, SLOT(group_5_clicked(int)));

    group_6 = new QButtonGroup; //新建分组
    group_6->addButton(ui->radioButton_11,11);
    group_6->addButton(ui->radioButton_12,12);
    connect(group_6, SIGNAL(buttonClicked(int)), this, SLOT(group_6_clicked(int)));

    user_box = new QComboBox(this) ;
    user_box->setMinimumWidth(120);
    user_box->move(680,0);
    user_box->addItem(load_user+"已登录");
    user_box->addItem("退出登录");
    user_box->addItem("修改密码");
    connect(user_box,SIGNAL(currentIndexChanged(int)),this,SLOT(setindex(int)));
    quit_box = new QMessageBox ;
    yesButton.setText("确定");
    cancelButton.setText("取消");
    quit_box->addButton(&yesButton,QMessageBox::AcceptRole);
    quit_box->addButton(&cancelButton,QMessageBox::RejectRole);

    quit_box->setText("确定退出登录吗？");
    quit_box->setIcon(QMessageBox::Warning);

    m_psword_change = new psword_change ;

}


void diancifa::setindex(int num)
{
    if(num == 1)
    {
        int ret = quit_box->exec();
        if(ret == QMessageBox::AcceptRole)
        {
            user_box->setCurrentIndex(0);
            Load_OkFlag = NO_LOAD ;
            close();
        }
        else
        {
            user_box->setCurrentIndex(0);
        }
    }
    else if(num == 2)
    {
        m_psword_change->exec();
        user_box->setCurrentIndex(0);
        if(Load_OkFlag == NO_LOAD)
        close();
    }
}


void diancifa::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/png/image/background.png");
    painter.drawPixmap(0,0,800,480,pix);
}

diancifa::~diancifa()
{
    delete ui;
}

void diancifa::group_1_clicked(int id)
{
    /*sem_wait(sem_val);
    if(id==1)read_data->diancifa1=true;
    else if(id==2)read_data->diancifa1=false;
    printf("%d\n",read_data->diancifa1);
    sem_post(sem_val);*/
}

void diancifa::group_2_clicked(int id)
{
    /*sem_wait(sem_val);
    if(id==1)read_data->diancifa2=true;
    else if(id==2)read_data->diancifa2=false;
    sem_post(sem_val);*/
}

void diancifa::group_3_clicked(int id)
{
    /*sem_wait(sem_val);
    if(id==4)read_data->diancifa3=true;
    else if(id==3)read_data->diancifa3=false;
    sem_post(sem_val);*/
}

void diancifa::group_4_clicked(int id)
{
   /* sem_wait(sem_val);
    if(id==6)read_data->diancifa4=true;
    else if(id==5)read_data->diancifa4=false;
    sem_post(sem_val);*/
}

void diancifa::group_5_clicked(int id)
{
   /* sem_wait(sem_val);
    if(id==8)read_data->diancifa5=true;
    else if(id==7)read_data->diancifa5=false;
    sem_post(sem_val);*/
}

void diancifa::group_6_clicked(int id)
{
    /*sem_wait(sem_val);
    if(id==10)read_data->diancifa6=true;
    else if(id==11)read_data->diancifa6=false;
    sem_post(sem_val);*/
}


void diancifa::on_x_clicked()
{
    emit display(4);
}

void diancifa::on_y_clicked()
{
    emit display(5);
}

void diancifa::on_back_clicked()
{
    emit display(0);
}
