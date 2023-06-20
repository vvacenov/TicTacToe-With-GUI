#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QObject>
#include <QPixmap>
#include <QLabel>
#include <QMouseEvent>
#include <vector>
#include "artclass.h"
#include "ui_mainwindow.h"
#include "about.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GameLogic;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    GameLogic* gameLogic;
    const std::vector<int> &getTaken(); //game state, prenijeti u klasu za logiku


    ~MainWindow();




private:
    QMainWindow* window;


    //--get recources--
    ArtClass player; //napravljeno kao posebna klasa, za slučaj potrebe za kasnijim izmjenama ili nadogradnjom
    QPixmap playerX_image = player.getPlayerX();
    QPixmap playerO_image = player.getPlayerO();
    QPixmap background_image = player.getBackground();
    //end get resources


    //--use resources--
    void setPlayerImage_X(QLabel &label);
    void setPlayerImage_O(QLabel &label);
    void mousePressEvent(QMouseEvent* event);
    //--end use resources--


    //--logic variables--
    int currentPlayer; //prenijeti u game state

    QMap<int, QLabel*> fields; //mapa labela u koje se može crtati slika

    std::vector<int> taken; //prenijeti u game state
    //--end logic variables--

    //mijenjanje labela na temelju stanja igre
    void setStartGame();
    void setUnplayable();
    void setPlayable();
    void playButtons();

    About *aboutDialog = new About(this);

    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
