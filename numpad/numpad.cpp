/*
 *   Copyright 20012 Maxime Haselbauer <maxime.haselbauer@googlemail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <QString>
#include "numpad.h"
#include "ui_numpad.h"

numpad::numpad(QDialog *parent) :
    QDialog(parent),
    NUMPAD(new Ui::numpad)
{
    VALUE=new QString("");
    if (parent!=0){
        NUMPAD->setupUi(parent);
    }
    else{
        NUMPAD->setupUi(this);
    }
    isOpend = false;
    move(450,80);
    QObject::connect(NUMPAD->QPB_0,SIGNAL(clicked()),this,SLOT(append_0()));
    QObject::connect(NUMPAD->QPB_1,SIGNAL(clicked()),this,SLOT(append_1()));
    QObject::connect(NUMPAD->QPB_2,SIGNAL(clicked()),this,SLOT(append_2()));
    QObject::connect(NUMPAD->QPB_3,SIGNAL(clicked()),this,SLOT(append_3()));
    QObject::connect(NUMPAD->QPB_4,SIGNAL(clicked()),this,SLOT(append_4()));
    QObject::connect(NUMPAD->QPB_5,SIGNAL(clicked()),this,SLOT(append_5()));
    QObject::connect(NUMPAD->QPB_6,SIGNAL(clicked()),this,SLOT(append_6()));
    QObject::connect(NUMPAD->QPB_7,SIGNAL(clicked()),this,SLOT(append_7()));
    QObject::connect(NUMPAD->QPB_8,SIGNAL(clicked()),this,SLOT(append_8()));
    QObject::connect(NUMPAD->QPB_9,SIGNAL(clicked()),this,SLOT(append_9()));
    QObject::connect(NUMPAD->QPB_POINT,SIGNAL(clicked()),this,SLOT(append_point()));
    QObject::connect(NUMPAD->QPB_BACK,SIGNAL(clicked()),this,SLOT(append_back()));
    QObject::connect(NUMPAD->QPB_CLEAR,SIGNAL(clicked()),this,SLOT(append_clear()));
    QObject::connect(NUMPAD->QPB_ENTER,SIGNAL(clicked()),this,SLOT(append_enter()));
    QObject::connect(NUMPAD->QPB_PLUS_MINUS,SIGNAL(clicked()),this,SLOT(toggle_plus_minus()));
}

numpad::~numpad()
{
    delete NUMPAD;
}

void numpad::append_0(){
    VALUE->append("0");
    emit value_changed(get_Value());
}
void numpad::append_1(){
    VALUE->append("1");
    emit value_changed(get_Value());
}
void numpad::append_2(){
    VALUE->append("2");
    emit value_changed(get_Value());
}
void numpad::append_3(){
    VALUE->append("3");
    emit value_changed(get_Value());
}
void numpad::append_4(){
    VALUE->append("4");
    emit value_changed(get_Value());
}
void numpad::append_5(){
    VALUE->append("5");
    emit value_changed(get_Value());
}
void numpad::append_6(){
VALUE->append("6");
emit value_changed(get_Value());
}
void numpad::append_7(){
VALUE->append("7");
emit value_changed(get_Value());
}
void numpad::append_8(){
    VALUE->append("8");
    emit value_changed(get_Value());
}
void numpad::append_9(){
    VALUE->append("9");
    emit value_changed(get_Value());
}
void numpad::append_point(){
    //VALUE->append(".");
    emit value_changed(get_Value());
}
void numpad::append_back(){
    VALUE->clear();
    isOpend = false ;
    close();
}
void numpad::append_clear(){
    clear_value();
}
void numpad::append_enter(){
    get_Value();
    VALUE->clear();
    isOpend = false ;
    close();
}
QString numpad::get_Value(){
    if(VALUE->toInt() >= 999999)
      *VALUE = VALUE->left(VALUE->length()-1);
    return *VALUE;
}
void numpad::toggle_plus_minus(){
    *VALUE = VALUE->left(VALUE->length()-1);
    emit value_changed(get_Value());
}
void numpad::clear_value(){
    VALUE->clear();
    emit value_changed(*VALUE);
}

