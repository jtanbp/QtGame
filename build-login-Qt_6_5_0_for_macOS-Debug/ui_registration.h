/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *finish;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *pass;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(496, 253);
        groupBox = new QGroupBox(Registration);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 451, 241));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:grey;"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 0, 281, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Stencil")});
        font.setPointSize(24);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 8pt \"Arial\";\n"
"font: 24pt \"Stencil\";"));
        finish = new QPushButton(groupBox);
        finish->setObjectName("finish");
        finish->setGeometry(QRect(60, 190, 331, 41));
        finish->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border:4px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 70, 331, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 8pt \"Arial\";\n"
"font: 16pt \"Arial\";\n"
""));

        horizontalLayout_3->addWidget(label_2);

        login = new QLineEdit(layoutWidget);
        login->setObjectName("login");
        login->setStyleSheet(QString::fromUtf8("border:3px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;\n"
"box-shadow:inset 0 0 6px;"));

        horizontalLayout_3->addWidget(login);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 8pt \"Arial\";\n"
"font: 16pt \"Arial\";"));

        horizontalLayout_2->addWidget(label_3);

        pass = new QLineEdit(layoutWidget);
        pass->setObjectName("pass");
        pass->setStyleSheet(QString::fromUtf8("border:3px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;\n"
"box-shadow:inset 0 0 6px;"));

        horizontalLayout_2->addWidget(pass);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Registration", "        Make your account", nullptr));
        finish->setText(QCoreApplication::translate("Registration", "Create", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "Login", nullptr));
        login->setText(QCoreApplication::translate("Registration", "sd", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
