#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include "mainwindow.h"


class GameLogic
{

private:

    const std::vector<int> &taken;
    int winArr[3][3];

public:

    GameLogic(MainWindow* mainWindow);
    int checkWinCondition();

};

#endif //GAMELOGIC_H
