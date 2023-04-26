#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>
#include "user.h"

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

    User currentUser;
    void populateFields(User user);
    void clearFields();

private slots:
    void on_mainMenuBtn_clicked();

    void on_playBtn_clicked();

private:
    Ui::WelcomeWindow *ui;

signals:
    void HomeClicked();
    void GameWindowClicked();
};

#endif // WELCOMEWINDOW_H
