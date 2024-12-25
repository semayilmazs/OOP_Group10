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

/**
 * @class login
 * @brief Represents the login window for the application.
 *
 * This class provides functionality to handle user login,
 * including validating credentials and opening the main window.
 */
class login : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the login class.
     * @param parent The parent widget (optional).
     */
    login(QWidget *parent = nullptr);
    /**
     * @brief Destructor for the login class.
     */
    ~login();

private slots:
    /**
     * @brief Slot called when the login button is clicked.
     * Check whether the given name and password is valid or not,
     * and print the proper situation
     */
    void on_btnlogin_clicked();

    /**
     * @brief When login button is clicked it directs to the openMainWindow function.
     * Then opens the main window which is the shopping window.
     */
    void openMainWindow();
    void on_result_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::login *ui;    ///< Pointer to the UI object of the login window.
};
#endif // LOGIN_H
