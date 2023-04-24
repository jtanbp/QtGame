#include "Loginpage.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Login, SIGNAL(released()), this,SLOT(on_Login_clicked()));
    connect(ui->reg, SIGNAL(released()), this,SLOT(on_reg_clicked()));
    connect(ui->playAsGuest, SIGNAL(released()), this,SLOT(on_playAsGuest_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool login(QString username, QString password){
    QFile file("database.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "Error!", file.errorString());
    }
    QTextStream in(&file);
    QString data = username+":"+password;

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(':').at(0) == username && line.split(':').at(1) == password){
            return true;
        }
    }
    return false;
};

void MainWindow::on_Login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    bool auth = login(username, password);

    if(auth) {
        hide();
        SecondWindow *s=new SecondWindow();
        s->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Wrong username or password!");
    }
}

void MainWindow::on_reg_clicked()
{
    hide();
    Registration *r = new Registration();
    r->show();
}

void MainWindow::on_password_textEdited(const QString &arg1)
{
    ui->password->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked == true){
        ui->password->setEchoMode(QLineEdit::Normal);
    }else {
        ui->password->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_playAsGuest_clicked()
{
    hide();
    SecondWindow *s=new SecondWindow();
    s->show();
}

