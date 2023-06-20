#ifndef ARTCLASS_H
#define ARTCLASS_H

#include <QString>
#include <QDir>

class ArtClass
{
private:

    const QString playerX;
    const QString playerO;
    const QString background;

public:
    ArtClass() :
        playerX(QDir::currentPath() + "\\Images\\X.png"),
        playerO(QDir::currentPath() + "\\Images\\O.png"),
        background (QDir::currentPath() + "\\Images\\background.png")
    {}

    const QString &getPlayerX();
    const QString &getPlayerO();
    const QString &getBackground();
};

#endif // ARTCLASS_H


// F:\\c++\\TicTacToe QT\\ticTacToe
