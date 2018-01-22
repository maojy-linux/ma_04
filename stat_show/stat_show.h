#ifndef STAT_SHOW_H
#define STAT_SHOW_H

#include <QMainWindow>
#include <QTimer>
namespace Ui {
class stat_show;
}

class stat_show : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat_show(QWidget *parent = 0);
    ~stat_show();
    char in[10]={0};
    char out[6]={0};


private slots:
    void on_work_clicked();

    void on_set_clicked();

    void on_back_clicked();

    void timerUpDate(void);
signals:
    void display(int num);

private:
    Ui::stat_show *ui;
    QTimer *stat_timer;
    QPixmap pix_on,pix_off;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STAT_SHOW_H
