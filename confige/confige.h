#ifndef CONFIGE_H
#define CONFIGE_H

#include <QMainWindow>
#include "my_lineedit/my_lineedit.h"
#include <QEvent>
#include <QPainter>
#include <QComboBox>
#include "confige/config_manage.h"
#include "QMessageBox"
namespace Ui {
class confige;
}

class confige : public QMainWindow
{
    Q_OBJECT

public:
    explicit confige(QWidget *parent = 0);
    ~confige();
    QComboBox *mode_box;
    config_manage *m_manage ;
private:
    Ui::confige *ui;
    my_lineedit *line_qianmenjin;
    my_lineedit *line_suoyanjuli;
    my_lineedit *line_suoyannum;
    QMessageBox *err_box;
    QPushButton yesbutton;
public slots:
    void setqianmenjin(QString data);
    void setsuoyanjuli(QString data);
    void setsuoyannum(QString data);

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_work_clicked();

    void on_show_clicked();

    void on_back_clicked();

    void on_pushButton_clicked();

    void SetMode(int num);


signals:
    void display(int num);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // CONFIGE_H
