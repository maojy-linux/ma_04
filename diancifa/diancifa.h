#ifndef DIANCIFA_H
#define DIANCIFA_H

#include <QMainWindow>
#include <QButtonGroup> //分组设置
#include <QComboBox>
#include "QMessageBox"
#include "QPushButton"
#include "load/psword_change.h"
namespace Ui {
class diancifa;
}

class diancifa : public QMainWindow
{
    Q_OBJECT

public:
    explicit diancifa(QWidget *parent = 0);
    ~diancifa();
    QComboBox *user_box;
    QMessageBox *quit_box;
    QPushButton yesButton ;
    QPushButton cancelButton ;
    psword_change *m_psword_change;
private:
    Ui::diancifa *ui;
    QButtonGroup* group_1;
    QButtonGroup* group_2;
    QButtonGroup* group_3;
    QButtonGroup* group_4;
    QButtonGroup* group_5;
    QButtonGroup* group_6;

private slots:
    void group_1_clicked(int id);
    void group_2_clicked(int id);
    void group_3_clicked(int id);
    void group_4_clicked(int id);
    void group_5_clicked(int id);
    void group_6_clicked(int id);

    void on_y_clicked();
    void on_x_clicked();
    void on_back_clicked();
    void setindex(int);

signals:
    void display(int num);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // DIANCIFA_H
