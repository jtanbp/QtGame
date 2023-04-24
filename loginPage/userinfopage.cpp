#include "userinfopage.h"
#include <QVBoxLayout>
#include <QDate>
#include <QPixmap>

UserInfoPage::UserInfoPage(QWidget *parent) :
    QWidget(parent),
    userNameLabel(new QLabel(this)),
    profilePictureLabel(new QLabel(this)),
    currentDateLabel(new QLabel(this)),
    greetingLabel(new QLabel(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(userNameLabel);
    layout->addWidget(profilePictureLabel);
    layout->addWidget(currentDateLabel);
    layout->addWidget(greetingLabel);

    currentDateLabel->setText(QDate::currentDate().toString());
}

void UserInfoPage::setUserName(const QString &name)
{
    userNameLabel->setText(name);
    checkBirthday();
}

void UserInfoPage::setProfilePicture(const QString &path)
{
    QPixmap profilePicture(path);

 profilePictureLabel->setPixmap(profilePicture.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void UserInfoPage::checkBirthday()
{
    // Check if it's the user's birthday and display a greeting if it is
    // For this example, we will use a fixed date for the user's birthday
    QDate userBirthday(1990, 4, 20);
    QDate currentDate = QDate::currentDate();

    if (userBirthday.day() == currentDate.day() && userBirthday.month() == currentDate.month())
    {
        greetingLabel->setText("Happy Birthday!");
    }
    else
    {
        greetingLabel->clear();
    }
}
