#include <QApplication>
#include "gamewindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GameWindow *main_window = new GameWindow;
    main_window->show();
    return a.exec();
}
