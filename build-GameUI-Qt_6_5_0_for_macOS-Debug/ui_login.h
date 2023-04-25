/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *line;
    QFrame *line_4;
    QTextEdit *usrNmTxt;
    QPushButton *signInBtn;
    QPushButton *signUpBtn;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QFrame *line_3;
    QFrame *line_2;
    QTextEdit *passTxt;
    QPushButton *mainMenuBtn;
    QLabel *label_4;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(1012, 1166);
        line = new QFrame(Login);
        line->setObjectName("line");
        line->setGeometry(QRect(210, 380, 31, 581));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Login);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(230, 950, 551, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        usrNmTxt = new QTextEdit(Login);
        usrNmTxt->setObjectName("usrNmTxt");
        usrNmTxt->setGeometry(QRect(520, 470, 221, 51));
        usrNmTxt->setStyleSheet(QString::fromUtf8("background-color: rgba(82, 217, 255, 128);\n"
"border: 5px solid grey;"));
        signInBtn = new QPushButton(Login);
        signInBtn->setObjectName("signInBtn");
        signInBtn->setGeometry(QRect(400, 710, 211, 71));
        signInBtn->setCursor(QCursor(Qt::PointingHandCursor));
        signInBtn->setFocusPolicy(Qt::StrongFocus);
        signInBtn->setAutoFillBackground(false);
        signInBtn->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgba(107, 176, 255, 179);"));
        signUpBtn = new QPushButton(Login);
        signUpBtn->setObjectName("signUpBtn");
        signUpBtn->setGeometry(QRect(400, 810, 211, 71));
        signUpBtn->setCursor(QCursor(Qt::PointingHandCursor));
        signUpBtn->setFocusPolicy(Qt::StrongFocus);
        signUpBtn->setAutoFillBackground(false);
        signUpBtn->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgba(107, 176, 255, 179);"));
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 470, 221, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setLineWidth(10);
        label_2->setTextFormat(Qt::RichText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(10);
        label_2->setIndent(5);
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 200, 561, 81));
        label->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setLineWidth(10);
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(10);
        label->setIndent(5);
        label_3 = new QLabel(Login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 600, 221, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setLineWidth(10);
        label_3->setTextFormat(Qt::RichText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(10);
        label_3->setIndent(5);
        line_3 = new QFrame(Login);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(220, 370, 561, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Login);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(770, 380, 20, 581));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        passTxt = new QTextEdit(Login);
        passTxt->setObjectName("passTxt");
        passTxt->setGeometry(QRect(520, 600, 221, 51));
        passTxt->setStyleSheet(QString::fromUtf8("background-color: rgba(82, 217, 255, 128);\n"
"border: 5px solid grey;"));
        mainMenuBtn = new QPushButton(Login);
        mainMenuBtn->setObjectName("mainMenuBtn");
        mainMenuBtn->setGeometry(QRect(670, 920, 100, 32));
        label_4 = new QLabel(Login);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 840, 71, 20));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        signInBtn->setText(QCoreApplication::translate("Login", "SIGN IN", nullptr));
        signUpBtn->setText(QCoreApplication::translate("Login", "SIGN UP", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Username", nullptr));
        label->setText(QCoreApplication::translate("Login", "SIGN IN PAGE", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "Password", nullptr));
        mainMenuBtn->setText(QCoreApplication::translate("Login", "Main Menu", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "New user?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
