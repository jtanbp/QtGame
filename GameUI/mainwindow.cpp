#include "mainwindow.h"
#include <QStackedWidget>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd = QPixmap("/Users/avishekchoudhury/Desktop/Project/QtGame/GameUI/gameBkg.jpg").scaled(this -> size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui -> stackedWidget -> insertWidget(1, &loginWidget);
    ui -> stackedWidget -> insertWidget(2, &scoresWidget);
    ui -> stackedWidget -> insertWidget(3, &signupWidget);
    ui -> stackedWidget -> insertWidget(4, &gameWindowWidget);

    connect(&loginWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&scoresWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&loginWidget, SIGNAL(SignUpClicked()), this, SLOT(moveSignup()));
    connect(&signupWidget, SIGNAL(SignInClicked()), this, SLOT(on_signInBtn_clicked()));
    connect(&signupWidget, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
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
    ui -> stackedWidget -> setCurrentIndex(1);
}


void MainWindow::on_scoresBtn_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);

}


void MainWindow::moveHome()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}

void MainWindow::moveSignup()
{
    ui -> stackedWidget -> setCurrentIndex(3);
}

void MainWindow::on_playBtn_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(4);
//    GameWindow* game  = new GameWindow();
//    game -> show();
//    this -> close();
}

