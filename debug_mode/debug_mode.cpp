#include "debug_mode.h"
#include "ui_debug_mode.h"

debug_mode::debug_mode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::debug_mode)
{
    ui->setupUi(this);
    setGeometry(0,0,800,480);
    QFont font;
    font.setPointSize(24);
    ui->motor->setText("电机");
    ui->motor->setFont(font);
    ui->back->setText("返回模式选择");
    ui->back->setFont(font);
}

debug_mode::~debug_mode()
{
    delete ui;
}

void debug_mode::on_back_clicked()
{
    this->close();
    delete this ;
}
