#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_finish_clicked();

private:
    Ui::Registration *ui;
    bool isPasswordValid(const QString &password);
};

#endif // REGISTRATION_H
