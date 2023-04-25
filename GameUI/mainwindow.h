#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "scores.h"
#include "signup.h"
#include "gamewindow.h"
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::string currentUser;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quitBtn_clicked();

    void on_signInBtn_clicked();

    void on_scoresBtn_clicked();

    void moveHome();

    void moveSignup();

    void on_playBtn_clicked();

private:
    Ui::MainWindow *ui;
    Login loginWidget;
    Scores scoresWidget;
    SignUp signupWidget;
    GameWindow gameWindowWidget;
};
#endif // MAINWINDOW_H
