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

    void setupUi(QWidget *Scores)
    {
        if (Scores->objectName().isEmpty())
            Scores->setObjectName("Scores");
        Scores->resize(853, 909);
        label = new QLabel(Scores);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 60, 461, 91));
        label->setStyleSheet(QString::fromUtf8("font: 35pt \"Academy Engraved LET\";\n"
"background-color: rgb(182, 75, 28);"));
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
        topScoresLabel->setGeometry(QRect(290, 220, 311, 361));
        topScoresLabel->setMaximumSize(QSize(16777215, 361));

        retranslateUi(Scores);

        QMetaObject::connectSlotsByName(Scores);
    } // setupUi

    void retranslateUi(QWidget *Scores)
    {
        Scores->setWindowTitle(QCoreApplication::translate("Scores", "Form", nullptr));
        label->setText(QCoreApplication::translate("Scores", "Leaderboard", nullptr));
        mainMenuScoreBtn->setText(QCoreApplication::translate("Scores", "Main Menu", nullptr));
        topScoresLabel->setText(QCoreApplication::translate("Scores", "<html><head/><body><p><span style=\" font-size:64pt; font-weight:700; font-style:italic;\">TextLabel</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scores: public Ui_Scores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORES_H
