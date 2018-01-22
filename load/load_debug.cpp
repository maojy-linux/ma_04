#include "load_debug.h"

load_debug::load_debug(QWidget *parent) :
    QDialog(parent)
{
    user_line = new my_lineedit(this);
    user_line->installEventFilter(this);
    connect(user_line,&my_lineedit::senddata,this,&load_debug::setuser);

    psword_line = new my_lineedit(this);
    psword_line->setEchoMode(QLineEdit::Password);
    psword_line->installEventFilter(this);
    connect(psword_line,&my_lineedit::senddata,this,&load_debug::setpsword);

    load_stat = new QLabel ;

    QGridLayout *main_layout = new QGridLayout ;
    QLabel * user_lable = new QLabel("用户名");
    QLabel * psword_lable = new QLabel("密码：");
    ok_button = new QPushButton("登录") ;
    QPushButton *calce_button = new QPushButton("退出") ;


    QCheckBox *show_box = new QCheckBox("显示密码") ;
    connect(show_box, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));

    main_layout->addWidget(user_lable,0,0,1,1);
    main_layout->addWidget(psword_lable,1,0,1,1);
    main_layout->addWidget(user_line,0,1,1,2);
    main_layout->addWidget(psword_line,1,1,1,2);
    main_layout->addWidget(ok_button,2,0,1,1);
    main_layout->addWidget(calce_button,2,1,1,1);
    main_layout->addWidget(show_box,2,2,1,1);
    main_layout->addWidget(load_stat,3,0,1,3);

    setLayout(main_layout);

    connect(calce_button,SIGNAL(clicked(bool)),this,SLOT(calce_solt(bool)));
    connect(ok_button,SIGNAL(clicked(bool)),this,SLOT(ok_solt(bool)));

    wait_timer = new QTimer ;
    connect(wait_timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    move(200,20);
}

void load_debug::ok_solt(bool)
{
    if(Load_FailCnt >= LOAD_FAIL_MAX)
    {
        Load_WaitTime = WAIT_TIME ;
        ok_button->setEnabled(false);
        wait_timer->start(1000);
    }
    if(Load_WaitTime == NO_WAIT)
    {
        if(user_line->text() == load_user)
        {
            if(psword_line->text() == load_psword)
            {
                load_stat->setText("登陆成功");
                Load_OkFlag = OK_LOAD ;
                Load_FailCnt = 0 ;
                emit display(4);
                close();
            }
            else
            {
                Load_FailCnt ++ ;
                load_stat->setText("密码错误  已输错"+QString::number(Load_FailCnt,10));
            }
        }
        else
        {
            Load_FailCnt ++ ;
            load_stat->setText("账号错误  已输错"+QString::number(Load_FailCnt,10));
        }
    }
}

void load_debug::onStateChanged(int stat)
{
    if(stat == Qt::Checked)
    {
        psword_line->setEchoMode(QLineEdit::Normal);
    }
    else if(stat == Qt::Unchecked)
    {
        psword_line->setEchoMode(QLineEdit::Password);
    }
}

void load_debug::setuser(QString data)
{
    user_line->setText(data);
}

void load_debug::setpsword(QString data)
{
    psword_line->setText(data);
}

void load_debug::timerUpDate(void)
{
    Load_WaitTime -- ;
    load_stat->setText("请等待："+QString::number(Load_WaitTime,10));
    if(Load_WaitTime == NO_WAIT)
    {
        wait_timer->stop();
        Load_FailCnt = 0 ;
        ok_button->setEnabled(true);
    }
}



void load_debug::calce_solt(bool)
{
    close();
}

bool load_debug::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(obj == psword_line)
        {
            psword_line->m_numpad->VALUE->clear() ;
            psword_line->m_numpad->exec();
            load_stat->setText("请登录 ");
        }
        else if(obj == user_line)
        {
            user_line->m_numpad->VALUE->clear() ;
            user_line->m_numpad->exec();
            load_stat->setText("请输入密码 ");
        }
    }

}

load_debug::~load_debug()
{

}
