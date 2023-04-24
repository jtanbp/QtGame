#include <QApplication>
#include <QStackedWidget>
#include "titlepage.h"
#include "signuppage.h"
#include "userinfopage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStackedWidget *stackedWidget = new QStackedWidget;
    TitlePage *titlePage = new TitlePage;
    SignUpPage *signUpPage = new SignUpPage;
    UserInfoPage *userInfoPage = new UserInfoPage;

    stackedWidget->addWidget(titlePage);
    stackedWidget->addWidget(signUpPage);
    stackedWidget->addWidget(userInfoPage);

    QObject::connect(titlePage->getSignUpButton(), &QPushButton::clicked, [=]() {
        // Add your signUp() action implementation here
        stackedWidget->setCurrentWidget(signUpPage);
    });

    // Connect the "Log In" button signal to change the stacked widget's current index
    QObject::connect(titlePage->getLogInButton(), &QPushButton::clicked, [=]() {
        // Add your logIn() action implementation here
        // Perform authentication and retrieve user information
        // For now, we'll just switch to the UserInfoPage without validation
        stackedWidget->setCurrentWidget(userInfoPage);
        userInfoPage->setUserName("John Doe");
        userInfoPage->setProfilePicture("path/to/profile/picture");
    });
    QObject::connect(titlePage->getGuestLogInButton(), &QPushButton::clicked, [=]() {
        // Perform actions for guest login and retrieve guest information
        // For now, we'll just switch to the UserInfoPage without validation
        stackedWidget->setCurrentWidget(userInfoPage);
        userInfoPage->setUserName("Guest");
        userInfoPage->setProfilePicture("path/to/default/profile/picture");
    });

    stackedWidget->show();

    return app.exec();
}
