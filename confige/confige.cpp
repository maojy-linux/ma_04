#include "confige.h"
#include "ui_confige.h"
#include <QPainter>
#include <stdio.h>

confige::confige(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::confige)
{
    ui->setupUi(this);

    QFont font;
    font.setPointSize(16);
    line_qianmenjin = new my_lineedit(this);
    line_suoyanjuli = new my_lineedit(this);
    line_suoyannum = new my_lineedit(this);

    line_qianmenjin->setGeometry(200,390,110,30);
    line_suoyanjuli->setGeometry(200,290,110,30);
    line_suoyannum->setGeometry(200,190,110,30);

    connect(line_qianmenjin,&my_lineedit::senddata,this,&confige::setqianmenjin);
    connect(line_suoyanjuli,&my_lineedit::senddata,this,&confige::setsuoyanjuli);
    connect(line_suoyannum,&my_lineedit::senddata,this,&confige::setsuoyannum);

    line_qianmenjin->installEventFilter(this);
    line_suoyanjuli->installEventFilter(this);
    line_suoyannum->installEventFilter(this);

    ui->back->setIconSize(QSize(81,81));
    ui->back->setIcon(QIcon(":/png/image/home_81.png"));
    ui->work->setIconSize(QSize(81,81));
    ui->work->setIcon(QIcon(":/png/image/work_81.png"));
    ui->show->setIconSize(QSize(81,81));
    ui->show->setIcon(QIcon(":/png/image/menu.png"));

    mode_box = new QComboBox(this) ;
    mode_box->move(480,30);
    mode_box->resize(120,30);
    mode_box->setEditable(true);
    mode_box->lineEdit()->setPlaceholderText(QStringLiteral("模式选择"));
    mode_box->lineEdit()->setReadOnly(true);
    mode_box->lineEdit()->setAlignment(Qt::AlignCenter);
    mode_box->addItem("模式一");
    mode_box->addItem("模式二");
    mode_box->addItem("模式三");
    mode_box->addItem("模式四");
    mode_box->addItem("模式五");
    mode_box->addItem("模式六");
    mode_box->setStyleSheet("QComboBox::drop-down{border:none;min-width:20px;background:transparent;}");
    mode_box->setCurrentIndex(-1);
    connect(mode_box,SIGNAL(currentIndexChanged(int)),this,SLOT(SetMode(int)));
    m_manage = new config_manage(this) ;
    m_manage->ReadConfigData();
    Mode_Count_Tmp = Mode_Count ;
    Mode_Count = 0;
    ui->pushButton->setStyleSheet("background-color:rgb(197,189,151)");
    ui->pushButton_2->setStyleSheet("background-color:rgb(197,189,151)");

    err_box = new QMessageBox ;
    yesbutton.setText("确定");
    err_box->addButton(&yesbutton,QMessageBox::AcceptRole);
    err_box->setIcon(QMessageBox::Warning);

}

void confige::SetMode(int num)
{
    if(num < Mode_Count_Tmp)
    {
        line_suoyannum->setText(m_manage->lab_s[num*4+1]->text());
        line_suoyanjuli->setText(m_manage->lab_s[num*4+2]->text());
        line_qianmenjin->setText(m_manage->lab_s[num*4+3]->text());
    }
    else
    {
        err_box->setText("所选模式未设置参数\n请重新选择");
        err_box->exec();
       // mode_box->setCurrentIndex(-1);
    }
}



bool confige::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(obj == line_qianmenjin)
        {
            line_qianmenjin->m_numpad->show();
        }
        else if(obj == line_suoyanjuli)
        {
            line_suoyanjuli->m_numpad->show();
        }
        else if(obj == line_suoyannum)
        {
            line_suoyannum->m_numpad->show();
        }


    }

}

void confige::setqianmenjin(QString data)
{
    line_qianmenjin->setText(data);
}

void confige::setsuoyanjuli(QString data)
{
    line_suoyanjuli->setText(data);
}

void confige::setsuoyannum(QString data)
{
    line_suoyannum->setText(data);
}

void confige::on_work_clicked()
{
    emit display(1);
}

void confige::on_show_clicked()
{
    emit display(2);
}

void confige::on_back_clicked()
{
    emit display(0);
}

void confige::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/png/image/background.png");
    painter.drawPixmap(0,0,800,480,pix);
}

confige::~confige()
{
    delete ui;
}


void confige::on_pushButton_clicked()
{
    m_manage->ReadConfigData();
    m_manage->main_table->show();
}
