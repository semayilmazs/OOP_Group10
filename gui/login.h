#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QLineEdit>
#include "Customer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btnlogin_clicked();
    void openMainWindow();
    void on_result_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::login *ui;
};
#endif // LOGIN_H
