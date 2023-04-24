#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "registration.h"
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Login_clicked();

    void on_reg_clicked();

    void on_password_textEdited(const QString &arg1);

    void on_radioButton_clicked(bool checked);

    void on_playAsGuest_clicked();

private:
private:
    QLabel *nameLabel;
    QLabel *profilePictureLabel;
    QLabel *dateLabel;
    Ui::MainWindow *ui;
};

#endif // LOGINPAGE_H
