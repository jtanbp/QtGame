#include "scores.h"
#include "ui_scores.h"

Scores::Scores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scores)
{
    ui->setupUi(this);

    loadScoresFromFile(); // Load the scores from the file
    showTopScores(); // Display the top score
}

Scores::~Scores()
{
    delete ui;
}

void Scores::loadScoresFromFile()
{
    QFile file("/Users/junmingjin/MSD/CS6015/QTG/QtGame/GameUI/score.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error (e.g., show an error message)
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("Name,Score")) {
            continue; // Skip header line
        }
        QStringList parts = line.split(",");
        if (parts.size() == 2) {
            QString name = parts[0].trimmed();
            int score = parts[1].trimmed().toInt();
            scoresList.append(qMakePair(name, score));
        }
    }

    file.close();
}


void Scores::showTopScores()
{
    std::sort(scoresList.begin(), scoresList.end(), [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
        return a.second > b.second;
    });

    QString topScoresText;

    for (int i = 0; i < 5 && i < scoresList.size(); ++i) {
        topScoresText += QString::number(i + 1) + ". " + scoresList[i].first + ": " + QString::number(scoresList[i].second) + "\n";
    }

    // Display the top 5 names and scores in a QLabel
    ui->topScoresLabel->setText(topScoresText);
}


void Scores::on_mainMenuScoreBtn_clicked()
{
    emit HomeClicked();
}
