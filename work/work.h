#ifndef WORK_H
#define WORK_H

#include <QWidget>
#include <qlabel.h>
#include <QPushButton>
#include "stat_show/stat_show.h"
#include "confige/confige.h"
#include <QTimer>
#include <QMessageBox>
namespace Ui {
class work;
}

class work : public QDialog
{
    Q_OBJECT

public:
    explicit work(QWidget *parent = 0);
    ~work();
    stat_show *my_show;
    confige *my_confige;
    QTimer* work_timer;
   QMessageBox *my_messagebox;
private slots:
    void on_suoyan0_clicked();

    void on_jianshu0_clicked();

    void on_back_clicked();

    void on_show_clicked();

    void on_set_clicked();

    void timerUpDate(void);
signals:
    void display(int num);
private:
    Ui::work *ui;
    QString buff="清零";
    QString back="返回模式选择";

    int suoyan_cnt=11;
    int jianshu_cnt=12;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // WORK_H
