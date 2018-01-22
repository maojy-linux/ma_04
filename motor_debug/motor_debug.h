#ifndef MOTOR_DEBUG_H
#define MOTOR_DEBUG_H

#include <QMainWindow>
#include <QComboBox>
#include "QMessageBox"
#include "QPushButton"
#include "load/psword_change.h"

namespace Ui {
class motor_debug;
}

class motor_debug : public QMainWindow
{
    Q_OBJECT

public:
    explicit motor_debug(QWidget *parent = 0);
    ~motor_debug();
    QComboBox *user_box;
    QMessageBox *quit_box;
    QPushButton yesButton ;
    QPushButton cancelButton ;
    psword_change *m_psword_change;

private:
    Ui::motor_debug *ui;
    QButtonGroup *direction_group;
    QButtonGroup *stat_group;
signals:
    void display(int num);
private slots:
    void on_y_clicked();
    void on_diancifa_clicked();
    void on_back_clicked();
    void direction_group_clicked(int id);
    void stat_group_clicked(int id);
    void setindex(int);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MOTOR_DEBUG_H
