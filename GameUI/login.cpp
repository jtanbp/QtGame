#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_mainMenuBtn_clicked()
{
    emit HomeClicked();
}

void Login::on_signUpBtn_clicked()
{
    emit SignUpClicked();
}

