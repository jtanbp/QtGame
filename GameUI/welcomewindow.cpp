#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "mainwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QWidget(parent),
    currentUser(""),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_mainMenuBtn_clicked()
{
    emit HomeClicked();
}

void WelcomeWindow::clearFields() {
    ui -> nameTxt -> clear();
    ui -> ageTxt -> clear();
    ui -> usernameTxt -> clear();
    ui -> highScoreTxt -> clear();
    ui -> rankingTxt -> clear();
    ui -> score1txt -> clear();
    ui -> score2txt -> clear();
    ui -> score3txt -> clear();
}


void WelcomeWindow::populateFields(User user) {
    ui -> nameTxt -> setText(QString::fromStdString(user.firstName + " " + user.lastName));
    QStringList date = QString::fromStdString(user.dateOfBirth).split(" ");

    int year = QDate::currentDate().year();
    int year1 = date[3].toInt();
    ui -> ageTxt -> setText(QString::number(year - year1));
    ui -> usernameTxt -> setText(QString::fromStdString(user.userName));
    ui -> highScoreTxt -> setText(QString::number(user.highScore));
    ui -> rankingTxt -> setText(QString::number(user.ranking));
    ui -> score1txt -> setText(QString::number(user.scoreHistory[0]));
    ui -> score2txt -> setText(QString::number(user.scoreHistory[1]));
    ui -> score3txt -> setText(QString::number(user.scoreHistory[2]));

    int month = QDate::currentDate().month();
    int dateNum = QDate::currentDate().day();
    if (date[2] == QString::number(dateNum) && ((month == 1 && date[1] == "Jan") || (month == 2 && date[1] == "Feb") ||(month == 3 && date[1] == "Mar")
                                                ||(month == 4 && date[1] == "Apr") ||(month == 5 && date[1] == "May") || (month == 6 && date[1] == "Jun") ||
                                                (month == 7 && date[1] == "Jul") ||
                                          (month == 8 && date[1] == "Aug") || (month == 9 && date[1] == "Sep") || (month == 10 && date[1] == "Oct") ||
                                                (month == 11 && date[1] == "Nov") || (month == 12 && date[1] == "Dec"))) {
        ui -> hbdMsg -> setText("Happy Birthday!");
    }
    currentUser = user;
}

void WelcomeWindow::on_playBtn_clicked()
{
    emit GameWindowClicked();
}

