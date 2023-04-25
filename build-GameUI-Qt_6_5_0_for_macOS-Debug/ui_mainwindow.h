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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *playBtn;
    QLabel *label_2;
    QPushButton *quitBtn;
    QPushButton *signInBtn;
    QPushButton *scoresBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1722, 1123);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(410, 20, 891, 1001));
        page = new QWidget();
        page->setObjectName("page");
        playBtn = new QPushButton(page);
        playBtn->setObjectName("playBtn");
        playBtn->setGeometry(QRect(300, 320, 301, 111));
        playBtn->setCursor(QCursor(Qt::PointingHandCursor));
        playBtn->setFocusPolicy(Qt::StrongFocus);
        playBtn->setAutoFillBackground(false);
        playBtn->setStyleSheet(QString::fromUtf8("font: 25pt \"Arial Rounded MT Bold\";\n"
"background-color: rgba(255, 201, 55, 153);"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("emblem-system");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        playBtn->setIcon(icon);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 80, 701, 191));
        label_2->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setLineWidth(10);
        label_2->setTextFormat(Qt::RichText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(10);
        label_2->setIndent(5);
        quitBtn = new QPushButton(page);
        quitBtn->setObjectName("quitBtn");
        quitBtn->setGeometry(QRect(300, 780, 301, 111));
        quitBtn->setCursor(QCursor(Qt::PointingHandCursor));
        quitBtn->setFocusPolicy(Qt::StrongFocus);
        quitBtn->setAutoFillBackground(false);
        quitBtn->setStyleSheet(QString::fromUtf8("font: 25pt \"Arial Rounded MT Bold\";\n"
"background-color: rgba(255, 201, 55, 153);"));
        quitBtn->setIcon(icon);
        signInBtn = new QPushButton(page);
        signInBtn->setObjectName("signInBtn");
        signInBtn->setGeometry(QRect(300, 620, 301, 111));
        signInBtn->setCursor(QCursor(Qt::PointingHandCursor));
        signInBtn->setFocusPolicy(Qt::StrongFocus);
        signInBtn->setAutoFillBackground(false);
        signInBtn->setStyleSheet(QString::fromUtf8("font: 25pt \"Arial Rounded MT Bold\";\n"
"background-color: rgba(255, 201, 55, 153);"));
        signInBtn->setIcon(icon);
        scoresBtn = new QPushButton(page);
        scoresBtn->setObjectName("scoresBtn");
        scoresBtn->setGeometry(QRect(300, 470, 301, 111));
        scoresBtn->setCursor(QCursor(Qt::PointingHandCursor));
        scoresBtn->setFocusPolicy(Qt::StrongFocus);
        scoresBtn->setAutoFillBackground(false);
        scoresBtn->setStyleSheet(QString::fromUtf8("font: 25pt \"Arial Rounded MT Bold\";\n"
"background-color: rgba(255, 201, 55, 153);"));
        scoresBtn->setIcon(icon);
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1722, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playBtn->setText(QCoreApplication::translate("MainWindow", "PLAY", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "QT Bullet Dodge", nullptr));
        quitBtn->setText(QCoreApplication::translate("MainWindow", "QUIT", nullptr));
        signInBtn->setText(QCoreApplication::translate("MainWindow", "SIGN IN", nullptr));
        scoresBtn->setText(QCoreApplication::translate("MainWindow", "SCORES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
