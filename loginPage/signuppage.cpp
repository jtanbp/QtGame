#include "signuppage.h"
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

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
    layout->addWidget(UploadPFPB, 6, 0);
    layout->addWidget(Reset, 7, 0);
    layout->addWidget(SignUpB, 7, 1);

    password->setEchoMode(QLineEdit::Password);

    passwordTipLabel = new QLabel("Password must have at least 8 characters, 1 uppercase, 1 lowercase, and 1 number", this);
    layout->addWidget(passwordTipLabel, 8, 0, 1, 2);
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

void SignUpPage::onSignUpClicked()
{
    QString usernameText = username->text();
    QString passwordText = password->text();
    QString firstNameText = firstName->text();
    QString lastNameText = lastName->text();
    QString dateOfBirthText = dateOfBirth->text();
    QString genderText = gender->text();

    if (isPasswordValid(passwordText) && !usernameText.isEmpty() &&
        !firstNameText.isEmpty() && !lastNameText.isEmpty() && !dateOfBirthText.isEmpty())
    {
        if (databaseManager->addUser(usernameText, passwordText, firstNameText,lastNameText, dateOfBirthText, genderText))
        {
            QMessageBox::information(this, "Success", "Account created successfully");
            // You can also emit a signal here, for example to switch to the main page after signing up
        }
        else
        {
            QMessageBox::warning(this, "Error", "Unable to create account. Username may already be taken.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Please make sure all required fields are filled and the password meets the criteria.");
    }
}

bool SignUpPage::isPasswordValid(const QString &password)
{
    if (password.length() < 8)
        return false;

    bool hasUpper = false, hasLower = false, hasDigit = false;

    for (const QChar &ch : password)
    {
        if (ch.isUpper())
            hasUpper = true;
        else if (ch.isLower())
            hasLower = true;
        else if (ch.isDigit())
            hasDigit = true;

        if (hasUpper && hasLower && hasDigit)
            return true;
    }

    return false;
}
