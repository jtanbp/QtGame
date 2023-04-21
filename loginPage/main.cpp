#include <QApplication>
#include <QStackedWidget>
#include "TitlePage.h"
#include "SignUpPage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStackedWidget *stackedWidget = new QStackedWidget;
    TitlePage *titlePage = new TitlePage;
    SignUpPage *signUpPage = new SignUpPage;

    stackedWidget->addWidget(titlePage);
    stackedWidget->addWidget(signUpPage);

    // Connect the "Sign Up" button signal to change the stacked widget's current index
    QObject::connect(titlePage->getSignUpButton(), &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(signUpPage);
    });

    stackedWidget->show();

    return app.exec();
}
