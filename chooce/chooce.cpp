/************************************************************
- Copyright (C), 2017-2018, JACK-IOT
- FileName: chooce.cpp
- Author:  maojy    Version : V4.0       Date: 2017-12-14
- Description:     Mode selection interface display and jump to other interface
- Function List:
  1.emit display(1);
    //transmit a signal
- History:
        <author>  <time>   <version >           <desc>
         maojy   17-12-14     4.0       Add logo and icon display
         maojy   17-12-07     3.0    Implement this process to communicate with other processes by way of POSIX shared memory, using sem semaphores for synchronization protection
         maojy   17-11-28     2.0    Using a custom signal slot connection, to achieve the jump between the various interfaces;
         maojy   17-11-23     1.0    Use controls and code to adjust the form to build each interface
***********************************************************/
#include "chooce.h"
#include "ui_chooce.h"
#include "work/work.h"
#include <QPainter>

static int stat_chooce=0;

chooce::chooce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooce)
{
    ui->setupUi(this);
    //setGeometry(0,0,800,480);
    QFont font;
    font.setPointSize(24);
    /*选择标签*/
    ui->mode_chooce->setText(mode);    //模式选择
    ui->mode_chooce->setFont(font);
    /*工作按钮*/
    ui->label->setText(work_mode);
    ui->label->setFont(font);
    ui->work_mode->setIconSize(QSize(81,81));    //模式选择
    ui->work_mode->setIcon(QIcon(":/png/image/work_81.png"));
    /*调试按钮*/
    ui->label_2->setText(debug);
    ui->label_2->setFont(font);
    ui->debug_mode->setIconSize(QSize(81,81));    //模式选择
    ui->debug_mode->setIcon(QIcon(":/png/image/set3.png"));

    m_load = new load_debug(this) ;

    my_work= new work(this);
    my_shat_show= new stat_show(this);
    my_confige= new confige(this);

    my_motor_debug= new motor_debug(this);
    my_motot_y_debug= new motot_y_debug(this);
    my_diancifa= new diancifa(this);

    connect(my_work,&work::display,this,&chooce::show_window);
    connect(my_shat_show,&stat_show::display,this,&chooce::show_window);
    connect(my_confige,&confige::display,this,&chooce::show_window);

    connect(my_motor_debug,&motor_debug::display,this,&chooce::show_window);
    connect(my_motot_y_debug,&motot_y_debug::display,this,&chooce::show_window);
    connect(my_diancifa,&diancifa::display,this,&chooce::show_window);

    connect(m_load,SIGNAL(display(int)),this,SLOT(show_window(int)));
}

void chooce::show_window(int num)
{
    /*关闭上一次打开的界面*/
    if(stat_chooce==1)
    {
        my_work->close();
    }
    else if (stat_chooce==2)
    {
        my_shat_show->close();
    }
    else if (stat_chooce==3)
    {
        my_confige->close();
    }
    else if(stat_chooce==4)
    {
        my_motor_debug->close();
    }
    else if(stat_chooce==5)
    {
        my_motot_y_debug->close();
    }
    else if(stat_chooce==6)
    {
        my_diancifa->close();
    }
    /*打开本次点击的界面*/
    if(num==1)
    {
        my_work->show();
        stat_chooce=1;
    }
    else if(num==2)
    {
        my_shat_show->show();
        stat_chooce=2;
    }
    else if(num==3)
    {
        my_confige->show();
        stat_chooce=3;
    }
    else if(num==4)
    {
        my_motor_debug->show();
        stat_chooce=4;
    }
    else if(num==5)
    {
        my_motot_y_debug->show();
        stat_chooce=5;
    }
    else if(num==6)
    {
        my_diancifa->show();
        stat_chooce=6;
    }


}


void chooce::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/png/image/background.png");
    painter.drawPixmap(0,0,800,480,pix);
}
void chooce::on_work_mode_clicked()
{
    emit display(1);
    //this->close();  //释放原窗口
    //delete this;
}

void chooce::on_debug_mode_clicked()
{
    if(Load_OkFlag == OK_LOAD)
    {
        emit display(4);
    }
    else
    {
        m_load->user_line->clear();
        m_load->psword_line->clear();
        m_load->load_stat->setText("请输入账号 ");
        m_load->setWindowModality(Qt::NonModal);
        m_load->show();
    }


}


chooce::~chooce()
{
    delete ui;
}


