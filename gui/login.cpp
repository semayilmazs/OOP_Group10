#include "login.h"
#include "ui_login.h"
#include "Customer.h"
#include "mainwindow.h"
#include <QTimer>
#include <QMessageBox>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::openMainWindow()
{
    // Create and show the MainWindow after the delay
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Close the login window
    this->close();
}

void login::on_btnlogin_clicked()
{
    QString temp_name = ui->txtname->text();
    QString temp_pwd = ui->txtpwd->text();

    // Create a Customer object and check the login credentials
    Customer customer(temp_name, temp_pwd);

    // Call the login method
    customer.login();  // This will check if the username and password are correct

    // If you want to handle the result, you could show a message box here
    if (customer.verification(temp_name, temp_pwd)) {
        qDebug() << "Login successful!";
        // Print to the result QLineEdit
        ui->txtresult->setText("Login successful!");

        // wait for 2 seconds to open new window
        QTimer::singleShot(2000, this, &login::openMainWindow);
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        // Print to the result QLineEdit
        ui->txtresult->setText("Invalid username or password!");
    }
}

void login::on_result_cursorPositionChanged(int oldPos, int newPos)
{
    // Implement functionality for when cursor position changes, if necessary
}
