#include "Loginpage.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDateTime>
#include <QPixmap>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Login, SIGNAL(released()), this,SLOT(on_Login_clicked()));
    connect(ui->reg, SIGNAL(released()), this,SLOT(on_reg_clicked()));
    connect(ui->playAsGuest, SIGNAL(released()), this,SLOT(on_playAsGuest_clicked()));

    // Add these lines here
    nameLabel = new QLabel(this);
    profilePictureLabel = new QLabel(this);
    dateLabel = new QLabel(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool login(QString username, QString password){
    QFile file("database.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "Error!", file.errorString());
    }
    QTextStream in(&file);
    QString data = username+":"+password;

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.split(':').at(0) == username && line.split(':').at(1) == password){
            return true;
        }
    }
    return false;
};

QStringList getUserInfo(QString username) {
    QFile file("database.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "Error!", file.errorString());
    }
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.split(':').at(0) == username) {
            return line.split(':');
        }
    }
    return QStringList();
}

void MainWindow::on_Login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    bool auth = login(username, password);

    if(auth) {
        QStringList userInfo = getUserInfo(username);

        // Display user's name
        nameLabel->setText("Welcome, " + userInfo[2] + " " + userInfo[3]);
        nameLabel->setGeometry(QRect(QPoint(10, 10), QSize(300, 20)));

        // Display user's profile picture
        QPixmap profilePicturePixmap(userInfo[6]);
        profilePictureLabel->setPixmap(profilePicturePixmap.scaled(100, 100, Qt::KeepAspectRatio));
        profilePictureLabel->setGeometry(QRect(QPoint(10, 40), QSize(100, 100)));

        // Display current date
        QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        dateLabel->setText(currentDate);
        dateLabel->setGeometry(QRect(QPoint(120, 40), QSize(300, 20)));

        // Check if it's the user's birthday
        if (currentDate.mid(5, 5) == userInfo[4].mid(5, 5)) {
            QMessageBox::information(this, "Happy Birthday!", "Happy Birthday, " + userInfo[2] + " " + userInfo[3] + "!");
        }

        hide();
        SecondWindow *s=new SecondWindow();
        s->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Wrong username or password!");
    }
}

void MainWindow::on_reg_clicked()
{
    hide();
    Registration *r = new Registration();
    r->show();
}

void MainWindow::on_password_textEdited(const QString &arg1)
{
    ui->password->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked == true){
        ui->password->setEchoMode(QLineEdit::Normal);
    }else {
        ui->password->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_playAsGuest_clicked()
{
    hide();
    SecondWindow *s=new SecondWindow();
    s->show();
}

