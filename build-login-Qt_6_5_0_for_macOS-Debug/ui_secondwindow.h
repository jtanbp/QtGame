/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QLabel *label_3;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName("SecondWindow");
        SecondWindow->resize(793, 394);
        SecondWindow->setStyleSheet(QString::fromUtf8("background-color:grey;"));
        label_3 = new QLabel(SecondWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 110, 741, 141));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QCoreApplication::translate("SecondWindow", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("SecondWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:600;\">Game should be playing here</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
