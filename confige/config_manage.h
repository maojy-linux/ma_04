#ifndef CONFIG_MANAGE_H
#define CONFIG_MANAGE_H

#include <QDialog>

#include "includes.h"
#include "QGridLayout"
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include "numpad/numpad.h"
#include "includes.h"
#include "QDebug"
#include "QTreeWidgetItem"
#include <QEvent>
#include <QPushButton>
#include "my_lineedit/my_lineedit.h"
#include <QHBoxLayout>
#include <QMessageBox>

static int Item_Cnt;

class AddInfo :public QDialog
{
    Q_OBJECT
public:
    explicit AddInfo(QWidget *parent = 0);
    ~AddInfo();
    QLabel *lab1;
    QLabel *lab2;
    QLabel *lab3;
    my_lineedit *line1;
    my_lineedit *line2;
    my_lineedit *line3;
    QPushButton *ok;
    QPushButton *cal;
private:
    QGridLayout *main_layout;
    QHBoxLayout *hb_layout;
    QMessageBox *war_box;
    QPushButton yesButton;


public slots:
    bool eventFilter(QObject*obj, QEvent*);
private slots:
    void setlin1(QString str);
    void setlin2(QString str);
    void setlin3(QString str);
    void ok_clicked();
    void cal_clicked();
signals:
    void add_success(QString,QString,QString);
};


class config_manage : public QDialog
{
    Q_OBJECT

public:
    explicit config_manage(QWidget *parent = 0);
    ~config_manage();
    void ReadConfigData(void);
    QTableWidget *main_table;

    QPushButton *add;
    QPushButton *del;
    QPushButton *save;
    QPushButton *quit;

    QTableWidgetItem *lab_s[30];

    numpad *m_numpad;
    AddInfo *m_add;
private:
    QMessageBox *err_box;
    QPushButton yesButton1;
    QPushButton yesButton2;

    QMessageBox *war_box;
    QPushButton yesbutton;

    QString LastData ;
   void ManageInit(void);
   void free_config(void);
   void ModifyConfigeInfo(QTableWidgetItem *item);
   void SaveConfigData(void);
private slots:
   void getwidget(QTableWidgetItem *item);
   void add_clicked();
   void del_clicked();
   void save_clicked();
   void quit_clicked();
   void SetItemText(QString str);
   void add_succes(QString,QString,QString);

};



#endif // CONFIG_MANAGE_H
