#include "titlepage.h"
#include <QGridLayout>
#include <QLabel>

TitlePage::TitlePage(QWidget *parent) :
    QWidget(parent),
    username(new QLineEdit(this)),
    password(new QLineEdit(this)),
    LogInB(new QPushButton("Log In", this)),
    SignUpB(new QPushButton("Sign Up", this))
{
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(new QLabel("Username:", this), 0, 0);
    layout->addWidget(username, 0, 1);
    layout->addWidget(new QLabel("Password:", this), 1, 0);
    layout->addWidget(password, 1, 1);
    layout->addWidget(LogInB, 2, 0);
    layout->addWidget(SignUpB, 2, 1);

    password->setEchoMode(QLineEdit::Password);

    connect(LogInB, &QPushButton::clicked, this, &TitlePage::Login);
    connect(SignUpB, &QPushButton::clicked, this, &TitlePage::SignUp);
}

void TitlePage::Login()
{
    // Perform login operations here
}

void TitlePage::SignUp()
{
    // Perform sign-up operations here
}
