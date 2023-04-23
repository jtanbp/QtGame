#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow *main_window = new MainWindow;
    main_window->show();
    return a.exec();
}
