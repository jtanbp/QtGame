/********************************************************************************
** Form generated from reading UI file 'scores.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORES_H
#define UI_SCORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scores
{
public:
    QLabel *label;
    QPushButton *mainMenuScoreBtn;
    QFrame *line_4;
    QLabel *topScoresLabel;
    QLabel *backgroundLabel;

    void setupUi(QWidget *Scores)
    {
        if (Scores->objectName().isEmpty())
            Scores->setObjectName("Scores");
        Scores->resize(853, 733);
        label = new QLabel(Scores);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 60, 461, 91));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: \"Academy Engraved LET\";\n"
"    font-size: 35pt;\n"
"    background-color: rgb(182, 75, 28);\n"
"}"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setLineWidth(10);
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(10);
        label->setIndent(5);
        mainMenuScoreBtn = new QPushButton(Scores);
        mainMenuScoreBtn->setObjectName("mainMenuScoreBtn");
        mainMenuScoreBtn->setGeometry(QRect(660, 120, 100, 32));
        line_4 = new QFrame(Scores);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(220, 870, 551, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        topScoresLabel = new QLabel(Scores);
        topScoresLabel->setObjectName("topScoresLabel");
        topScoresLabel->setGeometry(QRect(260, 190, 311, 361));
        topScoresLabel->setMaximumSize(QSize(16777215, 361));
        topScoresLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: \"Arial\";\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"    text-align: center;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffcc00, stop: 1 #f6ad42);\n"
"    border: 2px solid #333;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 4px;\n"
"    text-shadow: 1px 1px 2px #666;\n"
"}"));
        backgroundLabel = new QLabel(Scores);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setGeometry(QRect(7, 5, 831, 831));
        backgroundLabel->setStyleSheet(QString::fromUtf8("border-image: url(/Users/junmingjin/MSD/CS6015/QTG/QtGame/GameUI/gameBkg.jpg) 0 0 0 0 stretch stretch;"));
        backgroundLabel->raise();
        label->raise();
        mainMenuScoreBtn->raise();
        line_4->raise();
        topScoresLabel->raise();

        retranslateUi(Scores);

        QMetaObject::connectSlotsByName(Scores);
    } // setupUi

    void retranslateUi(QWidget *Scores)
    {
        Scores->setWindowTitle(QCoreApplication::translate("Scores", "Form", nullptr));
        label->setText(QCoreApplication::translate("Scores", "Leaderboard", nullptr));
        mainMenuScoreBtn->setText(QCoreApplication::translate("Scores", "Main Menu", nullptr));
        topScoresLabel->setText(QCoreApplication::translate("Scores", "<html><head/><body><p><span style=\" font-size:64pt; font-weight:700; font-style:italic;\">TextLabel</span></p></body></html>", nullptr));
        backgroundLabel->setText(QCoreApplication::translate("Scores", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scores: public Ui_Scores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORES_H
