#include "psword_change.h"

psword_change::psword_change(QWidget *parent) :
    QDialog(parent)
{
    QGridLayout *main_layout = new QGridLayout ;
    QLabel * old_lable = new QLabel("原密码：");
    QLabel * new_lable = new QLabel("新密码：");
    QLabel * confirm_lable = new QLabel("确认密码：");
    QPushButton *ok_button = new QPushButton("确认") ;
    QPushButton *cacle_button = new QPushButton("取消") ;
    old_line = new my_lineedit ;
    old_line->setEchoMode(QLineEdit::Password);
    old_line->installEventFilter(this);
    connect(old_line,&my_lineedit::senddata,this,&psword_change::setold);

    new_line = new my_lineedit ;
    new_line->setEchoMode(QLineEdit::Password);
    new_line->installEventFilter(this);
    connect(new_line,&my_lineedit::senddata,this,&psword_change::setnew);

    confirm_line = new my_lineedit ;
    confirm_line->setEchoMode(QLineEdit::Password);
    confirm_line->installEventFilter(this);
    connect(confirm_line,&my_lineedit::senddata,this,&psword_change::setconfirm);

    show_box = new QCheckBox("显示密码") ;
    connect(show_box, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));

    main_layout->addWidget(old_lable,0,0,1,1);
    main_layout->addWidget(new_lable,1,0,1,1);
    main_layout->addWidget(confirm_lable,2,0,1,1);
    main_layout->addWidget(old_line,0,1,1,2);
    main_layout->addWidget(new_line,1,1,1,2);
    main_layout->addWidget(confirm_line,2,1,1,2);
    main_layout->addWidget(ok_button,3,0,1,1);
    main_layout->addWidget(cacle_button,3,1,1,1);
    main_layout->addWidget(show_box,3,2,1,1);
    setLayout(main_layout);

    connect(cacle_button,SIGNAL(clicked(bool)),this,SLOT(calce_solt(bool)));
    connect(ok_button,SIGNAL(clicked(bool)),this,SLOT(ok_solt(bool)));

    error_box = new QMessageBox ;
    waring_box =new QMessageBox ;
    yesButton1.setText("确定");
    yesButton.setText("确定");
    cancelButton.setText("取消");
    waring_box->addButton(&yesButton1,QMessageBox::AcceptRole);
    waring_box->addButton(&cancelButton,QMessageBox::RejectRole);
    waring_box->setText("确定修改密码吗？");
    waring_box->setIcon(QMessageBox::Question);

    error_box->addButton(&yesButton,QMessageBox::AcceptRole);
    error_box->setIcon(QMessageBox::Warning);

    move(200,20);

}
void psword_change::ok_solt(bool)
{
    if(old_line->text() == load_psword)
    {
        if(new_line->text() == confirm_line->text())
        {
            int ret=waring_box->exec();
            if(ret==QMessageBox::AcceptRole)
            {
                load_psword = new_line->text();
                Load_OkFlag = NO_LOAD ;
                error_box->setText("密码修改成功，请重新登录！");
                error_box->exec();
                close();
            }
        }
        else
        {
            error_box->setText("两次密码不相同！");
            error_box->exec();
        }
    }
    else
    {
       error_box->setText("原密码错误！");
       error_box->exec();

    }
}

bool psword_change::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(obj == old_line)
        {
            old_line->m_numpad->VALUE->clear() ;
            old_line->m_numpad->exec();
        }
        else if(obj == new_line)
        {
            new_line->m_numpad->VALUE->clear() ;
            new_line->m_numpad->exec();
        }
        else if(obj == confirm_line)
        {
            confirm_line->m_numpad->VALUE->clear() ;
           confirm_line->m_numpad->exec();
        }
    }

}


void psword_change::setold(QString str)
{
    old_line->setText(str);
}
void psword_change::setnew(QString str)
{
    new_line->setText(str);
}
void psword_change::setconfirm(QString str)
{
    confirm_line->setText(str);
}



void psword_change::calce_solt(bool)
{
    close();
}


void psword_change::onStateChanged(int stat)
{
    if(stat == Qt::Checked)
    {
        old_line->setEchoMode(QLineEdit::Normal);
        new_line->setEchoMode(QLineEdit::Normal);
        confirm_line->setEchoMode(QLineEdit::Normal);
    }
    else if(stat == Qt::Unchecked)
    {
        old_line->setEchoMode(QLineEdit::Password);
        new_line->setEchoMode(QLineEdit::Password);
        confirm_line->setEchoMode(QLineEdit::Password);
    }
}
psword_change::~psword_change()
{

}
