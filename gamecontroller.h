#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H


#include "mainwindow.h"



class GameController : public QPushButton
{


public:
    GameController(MainWindow &mainWindow);
    void GameStart();

private:
    MainWindow &game;

};

#endif // GAMECONTROLLER_H
