#include "login.h"
#include "ui_login.h"
#include "Utility.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    currentUser(""),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->passTxt->setEchoMode(QLineEdit::Password);
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

void Login::clearFields() {
    ui -> usrNmTxt -> clear();
    ui -> passTxt -> clear();
}

void Login::on_signInBtn_clicked()
{
    ui -> errorLoginNote -> clear();
    std::string userName = ui -> usrNmTxt -> text().toStdString();
    std::string password = ui -> passTxt -> text().toStdString();

    //username check
    if (userName.empty()) {
        ui -> errorLoginNote -> setText("Please enter username to proceed further");
        return;
    }

    //password check
    if (password.empty()) {
        ui -> errorLoginNote -> setText("Please enter password to proceed further");
        return;
    }

    User user(userName);

    if (Utility::AuthenticateUser(user, password, false)) {
        std::vector<User> userList = Utility::getUserList();
        for (User userData: userList) {
            if (user.userName == userData.userName) {
                user.firstName = userData.firstName;
                user.lastName = userData.lastName;
                user.dateOfBirth = userData.dateOfBirth;
                break;
            }
        }
        std::vector<User> scoreList = Utility::getUserScoreList();
        for (User userData: scoreList) {
            if (user.userName == userData.userName) {
                user.highScore = userData.highScore;
                user.ranking = userData.ranking;
                user.scoreHistory = userData.scoreHistory;
                break;
            }
        }
        currentUser = user;
        emit WelcomeWindowClicked();
    }
    else {
        ui -> errorLoginNote -> setText("Username or Password is incorrect. Please try again");
    }
}

