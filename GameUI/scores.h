#ifndef SCORES_H
#define SCORES_H

#include <QWidget>

namespace Ui {
class Scores;
}

class Scores : public QWidget
{
    Q_OBJECT

public:
    explicit Scores(QWidget *parent = nullptr);
    ~Scores();

private slots:
    void on_mainMenuScoreBtn_clicked();

private:
    Ui::Scores *ui;

signals:
    void HomeClicked();
};

#endif // SCORES_H
