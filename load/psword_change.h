#ifndef PSWORD_CHANGE_H
#define PSWORD_CHANGE_H

#include <QDialog>
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGridLayout"
#include "QDialog"
#include "QLabel"
#include "QPushButton"
#include "my_lineedit/my_lineedit.h"
#include <QCheckBox>
#include "includes.h"
#include "QMessageBox"
#include <QEvent>
namespace Ui {
class psword_change;
}

class psword_change : public QDialog
{
    Q_OBJECT

public:
    explicit psword_change(QWidget *parent = 0);
    ~psword_change();
    my_lineedit *old_line ;
    my_lineedit *new_line ;
    my_lineedit *confirm_line;
    QCheckBox *show_box;
    QMessageBox *error_box;
    QMessageBox *waring_box;

private:
    Ui::psword_change *ui;
    QPushButton yesButton ;
    QPushButton yesButton1 ;
    QPushButton cancelButton ;
private slots:
    void onStateChanged(int stat);
    void calce_solt(bool);
    void ok_solt(bool);
    void setold(QString str);
    void setnew(QString str);
    void setconfirm(QString str);
public slots:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // PSWORD_CHANGE_H
