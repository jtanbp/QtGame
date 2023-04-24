#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "databasemanager.h"
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
    QLabel *passwordTipLabel;
    DatabaseManager *databaseManager;
    bool isPasswordValid(const QString &password);
private slots:
    void reset();
    void signUp();
    void onSignUpClicked();
};

#endif // SIGNUPPAGE_H

