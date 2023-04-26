#include "signup.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/writer.h"
#include <iostream>
#include <fstream>
#include "ui_signup.h"
#include "user.h"
#include "Utility.h"

SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    currentUser(""),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    ui->passwordTxt->setEchoMode(QLineEdit::Password);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_signInBtn_clicked()
{
    emit SignInClicked();
}


void SignUp::on_mainMenuBtn_clicked()
{
    emit HomeClicked();
}

void SignUp::clearFields() {
    ui -> firstTxt -> clear();
    ui -> lastTxt -> clear();
    ui -> usernameTxt -> clear();
    ui -> passwordTxt -> clear();
    ui -> ageTxt -> clear();
}

void SignUp::on_signUpBtn_clicked()
{
    ui -> errorNote -> clear();
    std::string firstName = ui -> firstTxt -> text().toStdString();
    std::string lastName = ui -> lastTxt -> text().toStdString();
    std::string userName = ui -> usernameTxt -> text().toStdString();
    std::string password = ui -> passwordTxt -> text().toStdString();
    std::string dob = ui -> ageTxt -> date().toString().toStdString();

    //first name check
    if (firstName.empty()) {
        ui -> errorNote -> setText("Please enter first name to proceed further");
        return;
    }
    if (std::any_of(firstName.begin(), firstName.end(), ::isdigit)) {
        ui -> errorNote -> setText("Please enter correct first name without number proceed further");
        return;
    }

    //last name check
    if (lastName.empty()) {
        ui -> errorNote -> setText("Please enter last name to proceed further");
        return;
    }
    if (std::any_of(lastName.begin(), lastName.end(), ::isdigit)) {
        ui -> errorNote -> setText("Please enter correct last name without number proceed further");
        return;
    }

    //username check
    if (userName.empty()) {
        ui -> errorNote -> setText("Please enter username to proceed further");
        return;
    }

    //password check
    if (password.empty()) {
        ui -> errorNote -> setText("Please enter password to proceed further");
        return;
    }

    //date of birst check
    if (dob.empty()) {
        ui -> errorNote -> setText("Please enter date of birth to proceed further");
        return;
    }
    //age check
    if (QDate::currentDate() < ui -> ageTxt -> date().addYears(12)) {
        ui -> errorNote -> setText("You should be above 12 to play this game");
        return;
    }

    User user = User(firstName, lastName, userName, dob);
    if (Utility::AddUser(user, password)) {
        currentUser = user;
        emit WelcomeWindowClicked();
    }
    else {
        ui -> errorNote ->setText("This username is already taken, please enter a different username");
    }
}

