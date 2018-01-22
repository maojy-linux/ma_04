#ifndef MY_LINEEDIT
#define MY_LINEEDIT
#include <QLineEdit>
#include "numpad/numpad.h"

class my_lineedit: public QLineEdit
{
    Q_OBJECT
public :
    explicit my_lineedit(QWidget *parent = 0);
    ~my_lineedit() ;
public:
    numpad *m_numpad;
public slots:
    void textchange(QString str);
signals:
    void senddata(QString data);

};



#endif // MY_LINEEDIT

