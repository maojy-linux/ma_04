#ifndef CHOOCE_H
#define CHOOCE_H

#include <QWidget>
#include "load/load_debug.h"
#include "work/work.h"
#include "stat_show/stat_show.h"
#include "confige/confige.h"
#include "motor_debug/motor_debug.h"
#include "motor_y_debug/motot_y_debug.h"
#include "diancifa/diancifa.h"
class work;
namespace Ui {
class chooce;
}

class chooce : public QWidget
{
    Q_OBJECT

public:
    explicit chooce(QWidget *parent = 0);
    ~chooce();
private slots:
    void on_work_mode_clicked();

    void on_debug_mode_clicked();

public slots:
    void show_window(int num);
signals:
    void display(int num);
private:
    Ui::chooce *ui;
    QString mode="模式选择";
    QString work_mode="工作模式";
    QString debug="调试模式";
    work *my_work;
    stat_show *my_shat_show;
    confige *my_confige;
    motor_debug *my_motor_debug;
    motot_y_debug *my_motot_y_debug;
    diancifa *my_diancifa;
public:
    load_debug *m_load;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CHOOCE_H
