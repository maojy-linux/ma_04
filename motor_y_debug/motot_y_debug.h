#ifndef MOTOT_Y_DEBUG_H
#define MOTOT_Y_DEBUG_H

#include <QMainWindow>
#include <QButtonGroup> //分组设置
#include <QComboBox>
#include "QMessageBox"
#include "QPushButton"
#include "load/psword_change.h"

namespace Ui {
class motot_y_debug;
}

class motot_y_debug : public QMainWindow
{
    Q_OBJECT

public:
    explicit motot_y_debug(QWidget *parent = 0);
    ~motot_y_debug();
    QComboBox *user_box;
    QMessageBox *quit_box;
    QPushButton yesButton ;
    QPushButton cancelButton ;
    psword_change *m_psword_change;

private:
    Ui::motot_y_debug *ui;
    QButtonGroup *direction_group;
    QButtonGroup *stat_group;
signals:
    void display(int num);
private slots:
    void on_x_clicked();
    void on_diancifa_clicked();
    void on_back_clicked();
    void direction_group_clicked(int id);
    void stat_group_clicked(int id);
    void setindex(int);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MOTOT_Y_DEBUG_H
