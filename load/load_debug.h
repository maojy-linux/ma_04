#ifndef LOAD_DEBUG_H
#define LOAD_DEBUG_H

#include "includes.h"
#include "my_lineedit/my_lineedit.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QDialog"
#include "QLabel"
#include "QPushButton"
#include <QEvent>
#include <QTimer>
#include <QCheckBox>
class load_debug : public QDialog
{
    Q_OBJECT

public:
    explicit load_debug(QWidget *parent = 0);
    ~load_debug();
    my_lineedit *user_line ;
    my_lineedit *psword_line ;
    QLabel *load_stat ;

private:
    QPushButton *ok_button ;
    QTimer *wait_timer ;
signals:
    void display(int);
public slots:
    bool eventFilter(QObject *obj, QEvent *event);
    void calce_solt(bool);
    void ok_solt(bool);
private slots:
    void timerUpDate(void);
    void setuser(QString data);
    void setpsword(QString data);
    void onStateChanged(int stat);
};

#endif // LOAD_DEBUG_H
