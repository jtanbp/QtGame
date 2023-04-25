/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLabel *label_3;
    QFrame *line_3;
    QFrame *line_2;
    QPushButton *signInBtn;
    QFrame *line;
    QPushButton *mainMenuBtn;
    QFrame *line_4;
    QLabel *label_2;
    QPushButton *signUpBtn;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *passwordTxt;
    QLabel *label_6;
    QDateEdit *ageTxt;
    QLabel *label_7;
    QLineEdit *firstTxt;
    QLineEdit *lastTxt;
    QLineEdit *usernameTxt;
    QLineEdit *errorNote;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(819, 929);
        label_3 = new QLabel(SignUp);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 380, 221, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setLineWidth(10);
        label_3->setTextFormat(Qt::RichText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(10);
        label_3->setIndent(5);
        line_3 = new QFrame(SignUp);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(130, 260, 561, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(SignUp);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(680, 270, 20, 641));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        signInBtn = new QPushButton(SignUp);
        signInBtn->setObjectName("signInBtn");
        signInBtn->setGeometry(QRect(310, 820, 211, 61));
        signInBtn->setCursor(QCursor(Qt::PointingHandCursor));
        signInBtn->setFocusPolicy(Qt::StrongFocus);
        signInBtn->setAutoFillBackground(false);
        signInBtn->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgba(107, 176, 255, 179);"));
        line = new QFrame(SignUp);
        line->setObjectName("line");
        line->setGeometry(QRect(120, 270, 31, 641));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        mainMenuBtn = new QPushButton(SignUp);
        mainMenuBtn->setObjectName("mainMenuBtn");
        mainMenuBtn->setGeometry(QRect(580, 870, 100, 32));
        line_4 = new QFrame(SignUp);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(130, 900, 561, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(SignUp);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 310, 221, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setLineWidth(10);
        label_2->setTextFormat(Qt::RichText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(10);
        label_2->setIndent(5);
        signUpBtn = new QPushButton(SignUp);
        signUpBtn->setObjectName("signUpBtn");
        signUpBtn->setGeometry(QRect(310, 740, 211, 61));
        signUpBtn->setCursor(QCursor(Qt::PointingHandCursor));
        signUpBtn->setFocusPolicy(Qt::StrongFocus);
        signUpBtn->setAutoFillBackground(false);
        signUpBtn->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgba(107, 176, 255, 179);"));
        label = new QLabel(SignUp);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 90, 561, 81));
        label->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setLineWidth(10);
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(10);
        label->setIndent(5);
        label_4 = new QLabel(SignUp);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 460, 221, 51));
        label_4->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_4->setFrameShape(QFrame::StyledPanel);
        label_4->setLineWidth(10);
        label_4->setTextFormat(Qt::RichText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(10);
        label_4->setIndent(5);
        label_5 = new QLabel(SignUp);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 540, 221, 51));
        label_5->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_5->setFrameShape(QFrame::StyledPanel);
        label_5->setLineWidth(10);
        label_5->setTextFormat(Qt::RichText);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setMargin(10);
        label_5->setIndent(5);
        passwordTxt = new QLineEdit(SignUp);
        passwordTxt->setObjectName("passwordTxt");
        passwordTxt->setGeometry(QRect(430, 540, 221, 51));
        passwordTxt->setStyleSheet(QString::fromUtf8("background-color: rgba(82, 217, 255, 128);\n"
"border: 5px solid grey;"));
        label_6 = new QLabel(SignUp);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(170, 630, 221, 51));
        label_6->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_6->setFrameShape(QFrame::StyledPanel);
        label_6->setLineWidth(10);
        label_6->setTextFormat(Qt::RichText);
        label_6->setScaledContents(false);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setMargin(10);
        label_6->setIndent(5);
        ageTxt = new QDateEdit(SignUp);
        ageTxt->setObjectName("ageTxt");
        ageTxt->setGeometry(QRect(429, 631, 231, 51));
        ageTxt->setStyleSheet(QString::fromUtf8("background-color: rgba(82, 217, 255, 128);\n"
"border: 5px solid grey;"));
        label_7 = new QLabel(SignUp);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(200, 840, 101, 16));
        firstTxt = new QLineEdit(SignUp);
        firstTxt->setObjectName("firstTxt");
        firstTxt->setGeometry(QRect(430, 310, 221, 51));
        firstTxt->setStyleSheet(QString::fromUtf8("background-color: rgba(82, 217, 255, 128);\n"
"border: 5px solid grey;"));
        lastTxt = new QLineEdit(SignUp);
        lastTxt->setObjectName("lastTxt");
        lastTxt->setGeometry(QRect(430, 380, 221, 51));
        lastTxt->setStyleSheet(QString::fromUtf8("background-color: rgba(82, 217, 255, 128);\n"
"border: 5px solid grey;"));
        usernameTxt = new QLineEdit(SignUp);
        usernameTxt->setObjectName("usernameTxt");
        usernameTxt->setGeometry(QRect(430, 460, 221, 51));
        usernameTxt->setStyleSheet(QString::fromUtf8("background-color: rgba(82, 217, 255, 128);\n"
"border: 5px solid grey;"));
        errorNote = new QLineEdit(SignUp);
        errorNote->setObjectName("errorNote");
        errorNote->setGeometry(QRect(140, 220, 551, 21));
        errorNote->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: red;"));
        errorNote->setReadOnly(true);

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("SignUp", "Last Name", nullptr));
        signInBtn->setText(QCoreApplication::translate("SignUp", "SIGN IN", nullptr));
        mainMenuBtn->setText(QCoreApplication::translate("SignUp", "Main Menu", nullptr));
        label_2->setText(QCoreApplication::translate("SignUp", "First Name", nullptr));
        signUpBtn->setText(QCoreApplication::translate("SignUp", "SIGN UP", nullptr));
        label->setText(QCoreApplication::translate("SignUp", "REGISTER", nullptr));
        label_4->setText(QCoreApplication::translate("SignUp", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("SignUp", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("SignUp", "Date Of Birth", nullptr));
        label_7->setText(QCoreApplication::translate("SignUp", "Already a user?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
