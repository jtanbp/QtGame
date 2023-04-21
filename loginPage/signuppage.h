#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class SignUpPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);

private:
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *dateOfBirth;
    QLineEdit *gender;
    QPushButton *UploadPFPB;
    QPushButton *Reset;
    QPushButton *SignUpB;

private slots:
    void reset();
    void signUp();
};

#endif // SIGNUPPAGE_H

