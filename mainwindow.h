#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "welcome/welcome.h"
#include "chooce/chooce.h"

#include <QSharedMemory>



class work;
class stat_show;
class confige;
class chooce;
class welcome;
class motor_debug;
class motot_y_debug;
class diancifa;

typedef struct sharedata
{
    int suoyan;
    int jianshu;
    bool input1;
    bool input2;
    bool input3;
    bool input4;
    bool input5;
    bool input6;
    bool input7;
    bool input8;
    bool input9;
    bool input10;
    bool output1;
    bool output2;
    bool output3;
    bool output4;
    bool output5;
    bool output6;
    int suoyannumber;
    int suoyanjuli;
    int qianmenji;
    bool diancifa1;
    bool diancifa2;
    bool diancifa3;
    bool diancifa4;
    bool diancifa5;
    bool diancifa6;
    int xifen_x;
    int shishiweizhi_x;
    int sudu_x;
    int jiasudu_x;
    int jiansudu_x;
    bool fangxian_x;
    bool tuoji_x;
    int xifen_y;
    int shishiweizhi_y;
    int sudu_y;
    int jiasudu_y;
    int jiansudu_y;
    bool fangxian_y;
    bool tuoji_y;
}SHAREDATA;

//extern SHAREDATA *read_data,*write_data;


class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void shareinit(void);
private:
    welcome *my_welcome;
    chooce *my_chooce;


    QSharedMemory *share_data;
    QString buff="欢迎使用杰克缝纫机";
    QTimer *load_timer;

private slots:
    void show_chooce(int num);

};

#endif // MAINWINDOW_H
