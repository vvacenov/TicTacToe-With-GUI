#include "gamelogic.h"
#include <QDebug>

GameLogic::GameLogic(MainWindow* mainWindow) :
    taken(mainWindow->getTaken())
{}

int GameLogic::checkWinCondition()
{
    int winCountX;
    int winCountO;
    int winNum = 3;


    for (int i = 0; i < winNum; i++)
    {
        for (int j = 0; j < winNum; j++)
        {
            winArr[i][j] = taken[i*winNum+j];
        }
    }

    //stupci
    for (int row = 0; row < winNum; row++)
    {
        winCountX = 0;
        winCountO = 0;

        for (int col = 0; col < winNum; col++)
        {
            if (winArr[row][col]==1)
            {
                winCountX++;
                if (winCountX == winNum)
                {

                    return 4;
                }
            }
            else if (winArr[row][col]==2)
            {
                winCountO++;
                if (winCountO == winNum)
                {

                    return 6;
                }
            }
            else
            {
                winCountX = 0;
                winCountO = 0;
            }
        }
    }
    //redovi
    for (int col = 0; col < winNum; col++)
    {
        winCountX = 0;
        winCountO = 0;

        for (int row = 0; row < winNum; row++)
        {
            if (winArr[row][col]==1)
            {
                winCountX++;
                if (winCountX == winNum)
                {

                    return 4;

                }
            }

            else if (winArr[row][col]==2)
            {
                winCountO++;
                if (winCountO == winNum)
                {

                    return 6;

                }
            }

            else
            {
                winCountX = 0;
                winCountO = 0;
            }
        }
    }

    //dijagonale
    winCountX = 0;
    winCountO = 0;

    for (int diag = 0; diag < winNum; diag++)
    {
        if (winArr[diag][diag] == 1)
        {
            winCountX++;
            if (winCountX == winNum)
            {


                return 4;
            }
        }
        else if (winArr[diag][diag] == 2)
        {
            winCountO++;
            if (winCountO == winNum)
            {


                return 6;
            }
        }
    }

    //suprotne dijagonale
    winCountX = 0;
    winCountO = 0;

    for (int diag = 0; diag < winNum; diag++)

    {
        if (winArr[diag][winNum - diag - 1] == 1)
        {
            winCountX++;
            if (winCountX == winNum)
            {

                return 4;
            }
        }
        else if (winArr[diag][winNum - diag - 1] == 2)
        {
            winCountO++;
            if (winCountO == winNum)
            {


                return 6;
            }
        }
    }

    //provjera nerijesenog
    bool isWin = false;

    if (!isWin)
    {
        bool isDraw = true;
        for (int i = 0; i < winNum; i++)
        {
            for (int j = 0; j < winNum; j++)
            {
                if (winArr[i][j] == 0)
                {
                    isDraw = false;
                    break;
                }
            }
            if(!isDraw)
            {
                break;
            }
        }

        if (isDraw)
        {

            return 13;
        }
    }

    return 0;
}
