/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QFormLayout *formLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *username;
    QLabel *user;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *password;
    QRadioButton *radioButton;
    QPushButton *Login;
    QPushButton *reg;
    QPushButton *playAsGuest;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(537, 288);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("font-family:Arial;\n"
"color:black;\n"
"font-size:25px;\n"
"background-color:grey;"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName("formLayout");
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName("formLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        username = new QLineEdit(groupBox);
        username->setObjectName("username");
        username->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border:3px solid black;\n"
"border-radius:7px;"));

        gridLayout->addWidget(username, 0, 1, 1, 1);

        user = new QLabel(groupBox);
        user->setObjectName("user");

        gridLayout->addWidget(user, 0, 0, 1, 1);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        password = new QLineEdit(groupBox);
        password->setObjectName("password");
        password->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border:3px solid black;\n"
"border-radius:7px;"));

        horizontalLayout->addWidget(password);


        formLayout_2->setLayout(1, QFormLayout::LabelRole, horizontalLayout);


        formLayout->setLayout(0, QFormLayout::LabelRole, formLayout_2);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setStyleSheet(QString::fromUtf8("border:4px solid black;\n"
"border-radius:7px;"));

        formLayout->setWidget(1, QFormLayout::FieldRole, radioButton);

        Login = new QPushButton(groupBox);
        Login->setObjectName("Login");
        Login->setStyleSheet(QString::fromUtf8("background-color:green;\n"
"border:4px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, Login);

        reg = new QPushButton(groupBox);
        reg->setObjectName("reg");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setStrikeOut(false);
        reg->setFont(font);
        reg->setStyleSheet(QString::fromUtf8("background-color:#DF593B;\n"
"border:4px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, reg);

        playAsGuest = new QPushButton(groupBox);
        playAsGuest->setObjectName("playAsGuest");

        formLayout->setWidget(1, QFormLayout::LabelRole, playAsGuest);


        verticalLayout_2->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "                        Shooting Game", nullptr));
        user->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        reg->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        playAsGuest->setText(QCoreApplication::translate("MainWindow", "Play as Guest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
