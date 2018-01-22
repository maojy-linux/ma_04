#include "my_lineedit/my_lineedit.h"
#include <QApplication>
#include <QDebug>
my_lineedit ::my_lineedit(QWidget *parent)
    :QLineEdit(parent)
{
    m_numpad = new numpad();
   // m_numpad->setWindowModality(Qt::NonModal);
   // m_numpad->setFocusPolicy(Qt::NoFocus);
    connect(m_numpad,&numpad::value_changed,this,&my_lineedit::textchange);


}





void my_lineedit::textchange(QString str)
{
    emit senddata(str);

}



my_lineedit ::~my_lineedit()
{

}
