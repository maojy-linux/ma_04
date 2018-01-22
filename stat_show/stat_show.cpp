/************************************************************
- Copyright (C), 2017-2018, JACK-IOT
- FileName: stat_show.cpp
- Author:  maojy    Version : V4.0       Date: 2017-12-14
- Description:     Status display interface and jump to other interfaces
- Version:         V4.0
- Function List:
  1.connect(stat_timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //Read the value of shared memory and display it at intervals
- History:
        <author>  <time>   <version >           <desc>
         maojy   17-12-14     4.0       Add logo and icon display
         maojy   17-12-07     3.0    Implement this process to communicate with other processes by way of POSIX shared memory, using sem semaphores for synchronization protection
         maojy   17-11-28     2.0    Using a custom signal slot connection, to achieve the jump between the various interfaces;
         maojy   17-11-23     1.0    Use controls and code to adjust the form to build each interface
***********************************************************/
#include "stat_show.h"
#include "ui_stat_show.h"
#include <QPainter>
#include "mainwindow.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>


stat_show::stat_show(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stat_show)
{
    // setGeometry(0,0,800,480);
    ui->setupUi(this);
    QFont font;
    font.setPointSize(16);

    /*返回模式选择按钮*/
    ui->label_18->setText("模式选择");
    ui->label_18->setFont(font);
    ui->label->setText("计件显示");
    ui->label->setFont(font);
    ui->label_17->setText("参数设置");
    ui->label_17->setFont(font);
    ui->back->setIconSize(QSize(81,81));
    ui->back->setIcon(QIcon(":/png/image/home_81.png"));
    ui->work->setIconSize(QSize(81,81));
    ui->work->setIcon(QIcon(":/png/image/work_81.png"));
    ui->set->setIconSize(QSize(81,81));
    ui->set->setIcon(QIcon(":/png/image/set_81.png"));

    stat_timer=new QTimer;
    pix_on.load(":/png/image/greenStone.png");
    pix_off.load(":/png/image/media-record.png");
    connect(stat_timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    stat_timer->start(15);

}
static bool stat_tmp[16]={0};
void stat_show::timerUpDate(void)
{/*
    sem_wait(sem_val);
    if(stat_tmp[0]!=read_data->input1)
    {
        stat_tmp[0]=read_data->input1;
        if(read_data->input1)ui->input_1->setPixmap(pix_on);
        else ui->input_1->setPixmap(pix_off);
    }
    if(stat_tmp[1]!=read_data->input2)
    {
        stat_tmp[1]=read_data->input2;
        if(read_data->input2)ui->input_2->setPixmap(pix_on);
        else ui->input_2->setPixmap(pix_off);
    }
    if(stat_tmp[2]!=read_data->input3)
    {
        stat_tmp[2]=read_data->input3;
        if(read_data->input3)ui->input_3->setPixmap(pix_on);
        else ui->input_3->setPixmap(pix_off);
    }
    if(stat_tmp[3]!=read_data->input4)
    {
        stat_tmp[3]=read_data->input4;
        if(read_data->input4)ui->input_4->setPixmap(pix_on);
        else ui->input_4->setPixmap(pix_off);
    }
    if(stat_tmp[4]!=read_data->input5)
    {
        stat_tmp[4]=read_data->input5;
        if(read_data->input5)ui->input_5->setPixmap(pix_on);
        else ui->input_5->setPixmap(pix_off);
    }
    if(stat_tmp[5]!=read_data->input6)
    {
        stat_tmp[5]=read_data->input6;
        if(read_data->input6)ui->input_6->setPixmap(pix_on);
        else ui->input_6->setPixmap(pix_off);
    }
    if(stat_tmp[6]!=read_data->input7)
    {
        stat_tmp[6]=read_data->input7;
        if(read_data->input7)ui->input_7->setPixmap(pix_on);
        else ui->input_7->setPixmap(pix_off);
    }
    if(stat_tmp[7]!=read_data->input8)
    {
        stat_tmp[7]=read_data->input8;
        if(read_data->input8)ui->input_8->setPixmap(pix_on);
        else ui->input_8->setPixmap(pix_off);
    }
    if(stat_tmp[8]!=read_data->input9)
    {
        stat_tmp[8]=read_data->input9;
        if(read_data->input9)ui->input_9->setPixmap(pix_on);
        else ui->input_9->setPixmap(pix_off);
    }
    if(stat_tmp[9]!=read_data->input10)
    {
        stat_tmp[9]=read_data->input10;
        if(read_data->input10)ui->input_10->setPixmap(pix_on);
        else ui->input_10->setPixmap(pix_off);
    }
    if(stat_tmp[10]!=read_data->output1)
    {
        stat_tmp[10]=read_data->output1;
        if(read_data->output1)ui->output_1->setPixmap(pix_on);
        else ui->output_1->setPixmap(pix_off);
    }
    if(stat_tmp[11]!=read_data->output2)
    {
        stat_tmp[11]=read_data->output2;
        if(read_data->output2)ui->output_2->setPixmap(pix_on);
        else ui->output_2->setPixmap(pix_off);
    }
    if(stat_tmp[12]!=read_data->output3)
    {
        stat_tmp[12]=read_data->output3;
        if(read_data->output3)ui->output_3->setPixmap(pix_on);
        else ui->output_3->setPixmap(pix_off);
    }
    if(stat_tmp[13]!=read_data->output4)
    {
        stat_tmp[13]=read_data->output4;
    if(read_data->output4)ui->output_4->setPixmap(pix_on);
    else ui->output_4->setPixmap(pix_off);
    }
    if(stat_tmp[14]!=read_data->output5)
    {
        stat_tmp[14]=read_data->output5;
        if(read_data->output5)ui->output_5->setPixmap(pix_on);
        else ui->output_5->setPixmap(pix_off);
    }
    if(stat_tmp[15]!=read_data->output6)
    {
        stat_tmp[15]=read_data->output6;
        if(read_data->output6)ui->output_6->setPixmap(pix_on);
        else ui->output_6->setPixmap(pix_off);
    }
    sem_post(sem_val);*/
}

void stat_show::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/png/image/background.png");
    painter.drawPixmap(0,0,800,480,pix);
}

stat_show::~stat_show()
{
    delete ui;
}

void stat_show::on_work_clicked()
{
   emit display(1);
}

void stat_show::on_set_clicked()
{
    emit display(3);
}

void stat_show::on_back_clicked()
{
    emit display(0);
}
