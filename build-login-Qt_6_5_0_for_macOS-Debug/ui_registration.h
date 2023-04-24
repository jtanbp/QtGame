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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *firstName;
    QLabel *label_2;
    QLineEdit *lastName;
    QLabel *label_3;
    QDateEdit *dob;
    QLabel *label_5;
    QComboBox *gender;
    QLabel *label_6;
    QPushButton *profilePicture;
    QLabel *label_8;
    QLineEdit *username;
    QLabel *label_7;
    QLineEdit *password;
    QPushButton *finish;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(626, 604);
        verticalLayout_3 = new QVBoxLayout(Registration);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(Registration);
        groupBox->setObjectName("groupBox");
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("background-color:grey;"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(572, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Stencil")});
        font.setPointSize(24);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 8pt \"Arial\";\n"
"font: 24pt \"Stencil\";"));

        verticalLayout_4->addWidget(label, 0, Qt::AlignLeft);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4, 0, Qt::AlignLeft);

        firstName = new QLineEdit(groupBox);
        firstName->setObjectName("firstName");
        firstName->setEnabled(true);
        firstName->setAutoFillBackground(true);

        verticalLayout_4->addWidget(firstName, 0, Qt::AlignLeft);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        verticalLayout_4->addWidget(label_2);

        lastName = new QLineEdit(groupBox);
        lastName->setObjectName("lastName");
        lastName->setTabletTracking(true);
        lastName->setAutoFillBackground(true);

        verticalLayout_4->addWidget(lastName, 0, Qt::AlignLeft);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        dob = new QDateEdit(groupBox);
        dob->setObjectName("dob");

        verticalLayout_4->addWidget(dob, 0, Qt::AlignLeft);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);

        gender = new QComboBox(groupBox);
        gender->addItem(QString());
        gender->addItem(QString());
        gender->addItem(QString());
        gender->addItem(QString());
        gender->setObjectName("gender");

        verticalLayout_4->addWidget(gender, 0, Qt::AlignLeft);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);

        profilePicture = new QPushButton(groupBox);
        profilePicture->setObjectName("profilePicture");

        verticalLayout_4->addWidget(profilePicture, 0, Qt::AlignLeft);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        username = new QLineEdit(groupBox);
        username->setObjectName("username");
        username->setAutoFillBackground(true);

        verticalLayout_4->addWidget(username, 0, Qt::AlignLeft);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");

        verticalLayout_4->addWidget(label_7);

        password = new QLineEdit(groupBox);
        password->setObjectName("password");
        password->setAutoFillBackground(true);

        verticalLayout_4->addWidget(password, 0, Qt::AlignLeft);

        finish = new QPushButton(groupBox);
        finish->setObjectName("finish");
        finish->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border:4px solid black;\n"
"border-radius:7px;\n"
"font-family:Arial;"));

        verticalLayout_4->addWidget(finish, 0, Qt::AlignLeft);


        verticalLayout_3->addWidget(groupBox);

#if QT_CONFIG(shortcut)
        label_4->setBuddy(label_4);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Registration", "        Make Your Account", nullptr));
        label_4->setText(QCoreApplication::translate("Registration", "FirstName", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "LastName", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "Date of Birth ", nullptr));
        label_5->setText(QCoreApplication::translate("Registration", "Gender", nullptr));
        gender->setItemText(0, QCoreApplication::translate("Registration", "gander", nullptr));
        gender->setItemText(1, QCoreApplication::translate("Registration", "Male", nullptr));
        gender->setItemText(2, QCoreApplication::translate("Registration", "Female", nullptr));
        gender->setItemText(3, QCoreApplication::translate("Registration", "other", nullptr));

        label_6->setText(QCoreApplication::translate("Registration", "ProfilePicture", nullptr));
        profilePicture->setText(QCoreApplication::translate("Registration", "Browse", nullptr));
        label_8->setText(QCoreApplication::translate("Registration", "password", nullptr));
        label_7->setText(QCoreApplication::translate("Registration", "username", nullptr));
        finish->setText(QCoreApplication::translate("Registration", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
