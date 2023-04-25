#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_mainMenuBtn_clicked();

    void on_signUpBtn_clicked();

private:
    Ui::Login *ui;

signals:
    void HomeClicked();
    void SignUpClicked();
};

#endif // LOGIN_H
