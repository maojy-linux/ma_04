/************************************************************
- Copyright (C), 2017-2018, JACK-IOT
- FileName: welcome.cpp
- Author:  maojy    Version : V4.0       Date: 2017-12-14
- Description:     Welcome interface shows and automatically jump to the work piece interface
- Version:         V4.0
- Function List:
  1.connect(load_timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //Timing function of the timer slot function binding
- History:
        <author>  <time>   <version >           <desc>
         maojy   17-12-14     4.0       Add logo and icon display
         maojy   17-12-07     3.0    Implement this process to communicate with other processes by way of POSIX shared memory, using sem semaphores for synchronization protection
         maojy   17-11-28     2.0    Using a custom signal slot connection, to achieve the jump between the various interfaces;
         maojy   17-11-23     1.0    Use controls and code to adjust the form to build each interface
***********************************************************/
#include "welcome.h"
#include "ui_welcome.h"
#include <QPainter>
#include <stdio.h>

static int cnt=0;

/************************************************************
- Function:       welcome::welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome)
- Description:    Class constructor
- Calls:          setPointSize();
                  setText();
                  setFont();
- Called By:      None
- Input:          None
- Output:         None
- Return:         None
- Others:         None
***********************************************************/
welcome::welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
  //  setGeometry(0,0,800,480);
    QFont font;
    font.setPointSize(24);
    /*欢迎使用杰克*/
    ui->text->setText(buff);
    ui->text->setFont(font);
    ui->verision->setText("版本：V1.00");
    load_timer=new QTimer;
    connect(load_timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    load_timer->start(15);

}

void welcome::timerUpDate(void)
{
    int max=100;
    cnt++;
    ui->loading->setValue(cnt);
    if(cnt==max)
    {
        load_timer->stop();
        emit display(0);
        this->close();  //释放原窗口
        delete this;
    }

}

void welcome::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/png/image/background.png");
    painter.drawPixmap(0,0,800,480,pix);
}

welcome::~welcome()
{
    delete ui;
}


