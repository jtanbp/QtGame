#ifndef TITLEPAGE_H
#define TITLEPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class TitlePage : public QWidget
{
    Q_OBJECT

public:
    explicit TitlePage(QWidget *parent = nullptr);

private:
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *LogInB;
    QPushButton *SignUpB;

private slots:
    void Login();
    void SignUp();
};

#endif // TITLEPAGE_H
