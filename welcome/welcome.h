#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <qlabel.h>
#include <QPushButton>
#include "chooce/chooce.h"
#include <QThread>
#include <QProgressDialog>
#include <QTimer>
namespace Ui {
class welcome;
}


class welcome : public QWidget
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = 0);
    ~welcome();
private:
    Ui::welcome *ui;
    QString buff="欢迎使用杰克缝纫机";
    QTimer *load_timer;
private slots:
    void timerUpDate(void);
signals:
    void display(int num);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // WELCOME_H
