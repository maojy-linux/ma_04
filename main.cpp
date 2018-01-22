#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>

/*
工程名称：
        ma04_interface
项目需求：
        根据需求设计界面，且和PLC进程通信，控制整机。
工程师名：
        Jack_Iot_maojy
编写说明：
    V1.0版本：
        用控件与代码调整形式搭建各个界面；
        用在类中定义其他类的方式实现界面跳转；------------Jack_Iot_maojy    20171123
    V2.0版本：
        采用自定义信号槽连接，实现各个界面之间的跳转;------Jack_Iot_maojy    20171128
    V3.0版本：
        实现此进程与其它进程进行通信方式，方式为POSIX共享内存，使用sem信号量进行同步保护；
        共享内存名为：read_shm；
        信号量名为：share_sem；-----------------------Jack_Iot_maojy    20171207
    V4.0版本：
        添加显示LOGO和按钮图标功能；--------------------Jack_Iot_maojy    20171214

调试记录：
    V1.0版本：
        界面之间可以互相跳转，但存在多次跳转之后程序变卡，需要优化跳转方式；
                            ------------------------Jack_Iot_maojy    20171124
    V2.0版本：
        测试发现1.0版本会出现跳转多次变卡，分析认为是由于每次跳转都创建新的类，占内存较大，
        故采用自定义信号槽连接的方式，只需创建一次类即可，经跳转功能测试正常；
                            ------------------------Jack_Iot_maojy    20171129
    V3.0版本：
        前期采用qt自带的共享内存方式，但由于需要和非qt进程通信，故采用Linux自带的共享内存方式
        进行通信,且采用信号量进行同步保护，经测试，进程间能正常通信；
                            ------------------------Jack_Iot_maojy    20171208
    V4.0版本：
        显示LOGO和按钮图标功能正常，但由于不同图片背景色不同造成画面不统一，需要优化；
                            ------------------------Jack_Iot_maojy    20171215
*/


#include "confige/config_manage.h"
#include "input/frminput.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);/*
    int id = QFontDatabase::addApplicationFont("/usr/local/qt5.4.1/lib/fonts/Droid Sans Fallback.ttf");
    QString msyh = QFontDatabase::applicationFontFamilies (id).at(0);
    QFont font(msyh,10);
    font.setPointSize(15);
    a.setFont(font);*/
    Dialog *w;
    w=new Dialog;
   // config_manage q ;
   // q.main_table->show();
    return a.exec();
}
