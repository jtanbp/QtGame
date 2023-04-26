#include "mainwindow.h"
#include <QStackedWidget>
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd = QPixmap(":/images/gameBkg.jpg").scaled(this -> size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui -> stackedWidget -> insertWidget(1, &loginWidget);
    ui -> stackedWidget -> insertWidget(2, &scoresWidget);
    ui -> stackedWidget -> insertWidget(3, &signupWidget);
    ui -> stackedWidget -> insertWidget(4, &gameWindowWidget);
    ui -> stackedWidget -> insertWidget(5, &welcomeWindowWidget);

    connect(&loginWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&scoresWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&loginWidget, SIGNAL(SignUpClicked()), this, SLOT(moveSignup()));
    connect(&signupWidget, SIGNAL(SignInClicked()), this, SLOT(on_signInBtn_clicked()));
    connect(&signupWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&gameWindowWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
//    connect(&signupWidget, SIGNAL(GameWindowClicked()), this, SLOT(on_playBtn_clicked()));
    connect(&signupWidget, SIGNAL(WelcomeWindowClicked()), this, SLOT(moveWelcomeFromSignUp()));
    connect(&loginWidget, SIGNAL(GameWindowClicked()), this, SLOT(on_playBtn_clicked()));
    connect(&welcomeWindowWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&welcomeWindowWidget, SIGNAL(GameWindowClicked()), this, SLOT(playBtnFromWelcome()));
    connect(&loginWidget, SIGNAL(WelcomeWindowClicked()), this, SLOT(moveWelcomeFromSignIn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitBtn_clicked()
{
    this -> close();
}

void MainWindow::on_signInBtn_clicked()
{
    loginWidget.clearFields();
    ui -> stackedWidget -> setCurrentIndex(1);
}

void MainWindow::on_scoresBtn_clicked()
{
    scoresWidget.clearFields();
    scoresWidget.loadScoresFromFile();
    ui -> stackedWidget -> setCurrentIndex(2);
}
//void MainWindow::on_signUpBtn_clicked()
//{
//    ui -> stackedWidget -> setCurrentIndex(3);
//}

void MainWindow::moveHome()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}

void MainWindow::moveSignup()
{
    signupWidget.clearFields();
    ui -> stackedWidget -> setCurrentIndex(3);
}

void MainWindow::on_playBtn_clicked()
{
    User user("Guest");
    gameWindowWidget.setupPlayer(user);
    ui -> stackedWidget -> setCurrentIndex(4);
}

void MainWindow::playBtnFromWelcome()
{
    gameWindowWidget.setupPlayer(welcomeWindowWidget.currentUser);
    ui -> stackedWidget -> setCurrentIndex(4);
}

void MainWindow::moveWelcomeFromSignUp() {
    welcomeWindowWidget.clearFields();
    welcomeWindowWidget.populateFields(signupWidget.currentUser);
    ui -> stackedWidget -> setCurrentIndex(5);
}

void MainWindow::moveWelcomeFromSignIn() {
    welcomeWindowWidget.clearFields();
    welcomeWindowWidget.populateFields(loginWidget.currentUser);
    ui -> stackedWidget -> setCurrentIndex(5);
}

