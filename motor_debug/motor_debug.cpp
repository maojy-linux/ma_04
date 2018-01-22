/************************************************************
- Copyright (C), 2017-2018, JACK-IOT
- FileName: motot_debug.cpp
- Author:  maojy    Version : V4.0       Date: 2017-12-14
- Description:     X-axis motor interface display and jump to other interfaces
- Version:         V4.0
- Function List:
  1.connect(direction_group, SIGNAL(buttonClicked(int)), this, SLOT(direction_group_clicked(int)));
    //Radio button grouping binding
- History:
        <author>  <time>   <version >           <desc>
         maojy   17-12-14     4.0       Add logo and icon display
         maojy   17-12-07     3.0    Implement this process to communicate with other processes by way of POSIX shared memory, using sem semaphores for synchronization protection
         maojy   17-11-28     2.0    Using a custom signal slot connection, to achieve the jump between the various interfaces;
         maojy   17-11-23     1.0    Use controls and code to adjust the form to build each interface
***********************************************************/
#include "motor_debug.h"
#include "ui_motor_debug.h"
#include "stdio.h"
#include <QPainter>

motor_debug::motor_debug(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::motor_debug)
{
    ui->setupUi(this);
    ui->back->setIconSize(QSize(81,81));
    ui->back->setIcon(QIcon(":/png/image/home_81.png"));
    ui->diancifa->setIconSize(QSize(81,81));
    ui->diancifa->setIcon(QIcon(":/png/image/diancifa.png"));
    ui->y->setIconSize(QSize(81,81));
    ui->y->setIcon(QIcon(":/png/image/y.png"));

    direction_group = new QButtonGroup; //新建分组
    direction_group->addButton(ui->radioButton_3,0);
    direction_group->addButton(ui->radioButton_4,1);

    stat_group = new QButtonGroup;
    stat_group->addButton(ui->radioButton,2);
    stat_group->addButton(ui->radioButton_2,3);

    connect(direction_group, SIGNAL(buttonClicked(int)), this, SLOT(direction_group_clicked(int)));
    connect(stat_group,SIGNAL(buttonClicked(int)),this,SLOT(stat_group_clicked(int)));

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

void motor_debug::setindex(int num)
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


void motor_debug::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/png/image/background.png");
    painter.drawPixmap(0,0,800,480,pix);
}

motor_debug::~motor_debug()
{
    delete ui;
}

void motor_debug::on_y_clicked()
{
    emit display(5);
}

void motor_debug::on_diancifa_clicked()
{
     emit display(6);
}

void motor_debug::on_back_clicked()
{
    emit display(0);
}

void motor_debug::direction_group_clicked(int id)
{

}
void motor_debug::stat_group_clicked(int id)
{

}
