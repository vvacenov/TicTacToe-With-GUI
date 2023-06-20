#include <QApplication>
#include "gamecontroller.h"



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow mainWindow;
    GameController game(mainWindow);
    game.GameStart();

    return app.exec();
}
