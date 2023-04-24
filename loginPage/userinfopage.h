#ifndef USERINFOPAGE_H
#define USERINFOPAGE_H

#include <QWidget>
#include <QLabel>

class UserInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoPage(QWidget *parent = nullptr);
    void setUserName(const QString &name);
    void setProfilePicture(const QString &path);

private:
    QLabel *userNameLabel;
    QLabel *profilePictureLabel;
    QLabel *currentDateLabel;
    QLabel *greetingLabel;

    void checkBirthday();
};

#endif // USERINFOPAGE_H

