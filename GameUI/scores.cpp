#include "scores.h"
#include "ui_scores.h"
#include <vector>

Scores::Scores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scores)
{
    ui->setupUi(this);
}

Scores::~Scores()
{
    delete ui;
}

void Scores::clearFields() {
    ui -> scoreLst -> clear();
}

void Scores::loadScoresFromFile()
{
    QString topScores;
    QFile file("/Users/avishekchoudhury/Desktop/Project/QtGame/GameUI/leaderboard.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error (e.g., show an error message)
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("UserName,HighScore,Ranking,Score0,Score1,Score2,Score3,Score4")) {
            continue; // Skip header line
        }
        QStringList parts = line.split(",");
        topScores += "\n";
        if (parts.size() == 7) {
            topScores += "\t" + parts[2] + "\t" + parts[0] + "\t\t" + parts[1] + "\n\n";
        }
    }
    file.close();
    ui -> scoreLst -> setText(topScores);
}

void Scores::on_mainMenuScoreBtn_clicked()
{
    emit HomeClicked();
}
