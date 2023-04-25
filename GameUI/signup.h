#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_signInBtn_clicked();

    void on_mainMenuBtn_clicked();

    void on_signUpBtn_clicked();

private:
    Ui::SignUp *ui;

signals:
    void SignInClicked();
    void HomeClicked();
};

#endif // SIGNUP_H
