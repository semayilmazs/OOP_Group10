#include "login.h"
#include "ui_login.h"
#include "Customer.h"
#include "mainwindow.h"
#include <QTimer>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>

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

void login::on_btnlogin_clicked() {
    // Retrieve input from the text fields
    QString name = ui->txtname->text();
    QString pwd = ui->txtpwd->text();
    QString email = ui->txtmail->text();

    // Create a User object
    Customer customer(name, pwd);

    // Check if the user exists based on the email
    if (!customer.doesExist(email)) {
        QMessageBox::warning(this, "Login Failed", "User does not exist. Please check your email or sign up.");
        return;
    }

    // Verify the user's credentials
    if (customer.verification(name, pwd, email)) {
        // Open the main window
        openMainWindow();
    } else {
        // Show a warning message if verification fails
        QMessageBox::warning(this, "Login Failed", "Incorrect name or password. Please try again.");
    }
}

void login::on_btnsignup_clicked() {
    // Get input values from the text fields
    QString name = ui->txtname->text();
    QString pwd = ui->txtpwd->text();
    QString email = ui->txtmail->text();

    // Create a User object to perform verification
    Customer customer(name, pwd);

    // Check if the user already exists
    if (customer.doesExist(email)) {
        // Display a message box if the email is already used
        QMessageBox::warning(this, "Signup Failed", "This email is already used.");
        return;
    }

    // If user does not exist, write the new user details to the file
    QFile file(QDir::currentPath() + "/customer.txt");
    qDebug() << "Writing to file path:" << file.fileName();
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Unable to open customer.txt for writing!" << file.errorString();
        return;
    }

    QTextStream out(&file);

    // User ID generation logic
    QRandomGenerator generator;
    int userId = generator.bounded(1000, 10000); // Example: Use timestamp for unique ID

    qDebug() << "Writing to file: " << name << "," << pwd << "," << email << "," << userId;

    // Write user information to the file
    out << name << "," << pwd << "," << email << "," << userId << ",\n";
    out.flush();
    file.close();

    // Show a success message
    QMessageBox::information(this, "Signup Successful", "Your account has been created!");

    // Optionally, clear the input fields
    ui->txtname->clear();
    ui->txtpwd->clear();
    ui->txtmail->clear();
}
