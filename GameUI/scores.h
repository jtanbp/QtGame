#ifndef SCORES_H
#define SCORES_H

#include <QWidget>
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QTextStream>
//#include "user.h"

namespace Ui {
class Scores;
}

class Scores : public QWidget
{
    Q_OBJECT

public:
    explicit Scores(QWidget *parent = nullptr);
    ~Scores();

//    void showTopScores();
    void loadScoresFromFile();
    void clearFields();

private slots:
    void on_mainMenuScoreBtn_clicked();

private:
    Ui::Scores *ui;

//    QVector<User> scoreList;
//    QString topScore;

signals:
    void HomeClicked();
};

#endif // SCORES_H
