#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <string>

using namespace std;

Registration::Registration(QWidget *parent) :
    QDialog (parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    connect(ui->finish, SIGNAL(released()), this,SLOT(on_finish_clicked()));

}

Registration::~Registration()
{
    delete ui;
}

//use relative file path
void reg(QString username, QString password){
    QFile file("/Users/jay/Desktop/loginPage/database.txt");
    if(!file.open(QIODevice::Append)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QString data = username+":"+password;
    QTextStream out(&file);
    out<< data << "\n";

    file.flush();
    file.close();
}

//use relative file path
bool check(QString username){
    QFile file("/Users/jay/Desktop/loginPage/database.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(':').contains(username)){
            return false;
        }
    }
    file.close();
    return true;
}
void Registration::on_finish_clicked()
{
    QString username = ui->login->text();
    QString password1 = ui->pass->text();
    if(password1==""){
        QMessageBox::warning(this, "NOT", "Fill in the blank!");
        return;
    }
    else{
        reg(username, password1);
        hide();
        MainWindow *mw=new MainWindow();
        mw->show();
    }
}
