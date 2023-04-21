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
    QGroupBox *groupBox;
    QPushButton *Login;
    QPushButton *reg;
    QRadioButton *radioButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *user;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *password;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(537, 288);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 541, 291));
        groupBox->setStyleSheet(QString::fromUtf8("font-family:Arial;\n"
"color:black;\n"
"font-size:25px;\n"
"background-color:grey;"));
        Login = new QPushButton(groupBox);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(20, 170, 411, 41));
        Login->setStyleSheet(QString::fromUtf8("background-color:green;\n"
"border:4px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;"));
        reg = new QPushButton(groupBox);
        reg->setObjectName("reg");
        reg->setGeometry(QRect(20, 220, 411, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setStrikeOut(false);
        reg->setFont(font);
        reg->setStyleSheet(QString::fromUtf8("background-color:#DF593B;\n"
"border:4px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(440, 120, 95, 31));
        radioButton->setStyleSheet(QString::fromUtf8("border:4px solid black;\n"
"border-radius:7px;"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 60, 411, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        user = new QLabel(layoutWidget);
        user->setObjectName("user");

        horizontalLayout_2->addWidget(user);

        username = new QLineEdit(layoutWidget);
        username->setObjectName("username");
        username->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border:3px solid black;\n"
"border-radius:7px;"));

        horizontalLayout_2->addWidget(username);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        password = new QLineEdit(layoutWidget);
        password->setObjectName("password");
        password->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border:3px solid black;\n"
"border-radius:7px;"));

        horizontalLayout->addWidget(password);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "                        Shooting Game", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        reg->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        user->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
