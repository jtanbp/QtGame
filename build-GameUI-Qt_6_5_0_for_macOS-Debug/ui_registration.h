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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QCalendarWidget *calendarWidget;
    QLineEdit *lineEdit;

    void setupUi(QWidget *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(479, 474);
        label = new QLabel(registration);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 241, 71));
        lineEdit_2 = new QLineEdit(registration);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(20, 110, 113, 21));
        lineEdit_3 = new QLineEdit(registration);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 160, 113, 21));
        lineEdit_4 = new QLineEdit(registration);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(20, 220, 113, 21));
        lineEdit_5 = new QLineEdit(registration);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(20, 260, 113, 21));
        label_2 = new QLabel(registration);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 81, 16));
        label_3 = new QLabel(registration);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 140, 81, 16));
        label_4 = new QLabel(registration);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 240, 58, 16));
        label_5 = new QLabel(registration);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 190, 91, 16));
        label_6 = new QLabel(registration);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 290, 251, 16));
        label_7 = new QLabel(registration);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 80, 58, 16));
        calendarWidget = new QCalendarWidget(registration);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(160, 110, 304, 173));
        lineEdit = new QLineEdit(registration);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(22, 320, 111, 21));

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QWidget *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Form", nullptr));
        label->setText(QCoreApplication::translate("registration", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700;\">Registration </span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("registration", "FirstName", nullptr));
        label_3->setText(QCoreApplication::translate("registration", "LastName", nullptr));
        label_4->setText(QCoreApplication::translate("registration", "password", nullptr));
        label_5->setText(QCoreApplication::translate("registration", "Username ", nullptr));
        label_6->setText(QCoreApplication::translate("registration", "Gander (97 choice you can have in US)", nullptr));
        label_7->setText(QCoreApplication::translate("registration", "birthday", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
