#ifndef DEBUG_MODE_H
#define DEBUG_MODE_H

#include <QMainWindow>

namespace Ui {
class debug_mode;
}

class debug_mode : public QMainWindow
{
    Q_OBJECT

public:
    explicit debug_mode(QWidget *parent = 0);
    ~debug_mode();

private slots:
    void on_back_clicked();

private:
    Ui::debug_mode *ui;
};

#endif // DEBUG_MODE_H
