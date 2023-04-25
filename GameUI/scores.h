#ifndef SCORES_H
#define SCORES_H

#include <QWidget>
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Scores;
}

class Scores : public QWidget
{
    Q_OBJECT

public:
    explicit Scores(QWidget *parent = nullptr);
    ~Scores();

    void showTopScores();
    void loadScoresFromFile();

private slots:
    void on_mainMenuScoreBtn_clicked();

private:
    Ui::Scores *ui;

    QVector<QPair<QString, int>> scoresList;
    QString topScore;

signals:
    void HomeClicked();
};

#endif // SCORES_H
