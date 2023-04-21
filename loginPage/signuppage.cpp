#include "signuppage.h"
#include <QGridLayout>
#include <QLabel>

SignUpPage::SignUpPage(QWidget *parent) :
    QWidget(parent),
    username(new QLineEdit(this)),
    password(new QLineEdit(this)),
    firstName(new QLineEdit(this)),
    lastName(new QLineEdit(this)),
    dateOfBirth(new QLineEdit(this)),
    gender(new QLineEdit(this)),
    UploadPFPB(new QPushButton("Upload Profile Picture", this)),
    Reset(new QPushButton("Reset", this)),
    SignUpB(new QPushButton("Sign Up", this))
{
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(new QLabel("Username:", this), 0, 0);
    layout->addWidget(username, 0, 1);
    layout->addWidget(new QLabel("Password:", this), 1, 0);
    layout->addWidget(password, 1, 1);
    layout->addWidget(new QLabel("First Name:", this), 2, 0);
    layout->addWidget(firstName, 2, 1);
    layout->addWidget(new QLabel("Last Name:", this), 3, 0);
    layout->addWidget(lastName, 3, 1);
    layout->addWidget(new QLabel("Date of Birth:", this), 4, 0);
    layout->addWidget(dateOfBirth, 4, 1);
    layout->addWidget(new QLabel("Gender:", this), 5, 0);
    layout->addWidget(gender, 5, 1);
    layout->addWidget(UploadPFPB, 6, 0, 1, 2);
    layout->addWidget(Reset, 7, 0);
    layout->addWidget(SignUpB, 7, 1);

    password->setEchoMode(QLineEdit::Password);

    connect(Reset, &QPushButton::clicked, this, &SignUpPage::reset);
    connect(SignUpB, &QPushButton::clicked, this, &SignUpPage::signUp);
}

void SignUpPage::reset()
{
    // Reset form fields to their default values
    username->clear();
    password->clear();
    firstName->clear();
    lastName->clear();
    dateOfBirth->clear();
    gender->clear();
}

void SignUpPage::signUp()
{
    // Perform sign-up operations here
}
