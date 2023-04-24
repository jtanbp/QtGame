#include "registration.h"
#include "ui_registration.h"
#include "Loginpage.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QRegularExpression>
#include <QFileDialog>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    connect(ui->finish, SIGNAL(released()), this,SLOT(on_finish_clicked()));
}

Registration::~Registration()
{
    delete ui;
}

void reg(QString userInfo){
    QFile file("database.txt");
    if(!file.open(QIODevice::Append)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QTextStream out(&file);
    out<< userInfo << "\n";

    file.flush();
    file.close();
}

bool check(QString username){
    QFile file("database.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(':').at(0) == username){
            return false;
        }
    }
    file.close();
    return true;
}

bool Registration::isPasswordValid(const QString &password)
{
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");
    return passwordRegex.match(password).hasMatch();
}

void Registration::on_finish_clicked()
{
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString dob = ui->dob->text();
    QString gender = ui->gender->currentText();
    QString profilePicture = ui->profilePicture->text();
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (firstName.isEmpty() || lastName.isEmpty() || dob.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "NOT", "Please fill in all required fields!");
        return;
    }

    if (!isPasswordValid(password)) {
        QMessageBox::warning(this, "Invalid Password", "Password must be at least 8 characters long and contain at least one number, upper and lower case letters.");
        return;
    }

    if (check(username)) {
        QString userInfo = username + ":" + password + ":" + firstName + ":" + lastName + ":" + dob + ":" + gender + ":" + profilePicture;
        reg(userInfo);
        hide();
        MainWindow *mw=new MainWindow();
        mw->show();
    } else {
        QMessageBox::warning(this, "Username Exists", "The username already exists. Please choose a different one.");
    }
}


void Registration::on_profilePicture_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    if (!filePath.isEmpty()) {
        ui->profilePicture->setText(filePath);
    }
}

