#include "gamecontroller.h"


GameController::GameController(MainWindow &mainWindow) : game(mainWindow)

{}


void GameController::GameStart()
{
  game.show();
}
