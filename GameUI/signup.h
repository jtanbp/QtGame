#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "user.h"

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    User currentUser;
    void clearFields();

private slots:
    void on_signInBtn_clicked();

    void on_mainMenuBtn_clicked();

    void on_signUpBtn_clicked();

private:
    Ui::SignUp *ui;

signals:
    void SignInClicked();
    void HomeClicked();
    void GameWindowClicked();
    void WelcomeWindowClicked();
};

#endif // SIGNUP_H
