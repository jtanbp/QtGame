#ifndef TITLEPAGE_H
#define TITLEPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class TitlePage : public QWidget
{
    Q_OBJECT

public:

    QPushButton *getLogInButton() const;
    explicit TitlePage(QWidget *parent = nullptr);
    QPushButton *getSignUpButton() const;
    QPushButton *getGuestLogInButton() const;
private:
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *LogInB;
    QPushButton *SignUpB;
    QPushButton *GuestLogInB;

private slots:
    void Login();
    void SignUp();
};

#endif // TITLEPAGE_H
