#include "mainwindow.h"
#include "gamelogic.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    gameLogic(new GameLogic(this)),
    currentPlayer(0),
    taken(9,0),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    this->setFixedSize(QSize(600, 623));



    setUnplayable();

    ui->winnerX->setStyleSheet("QLabel { color : #ee6c4d; }");
    ui->winnerO->setStyleSheet("QLabel { color : #ee6c4d; }");
    ui->drawLabel->setStyleSheet("QLabel { color : #ee6c4d; }");

    ui->winnerX->setVisible(false);
    ui->winnerO->setVisible(false);
    ui->drawLabel->setVisible(false);

    ui->background->setPixmap(background_image);
    ui->playButton->setVisible(true);
    ui->playAgainButton->setVisible(false);


    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::setStartGame);
    connect(ui->playAgainButton, &QPushButton::clicked, this, &MainWindow::setPlayable);
    connect(ui->actionAbout, &QAction::triggered, aboutDialog, &QDialog::show);



    for (int i = 0; i < 9; ++i)
    {
        //labeli su nazvani gamelabel1, gamelabel2, etc...
        //Mapiranje labela koje želim koristiti za crtanje polja na temelju imena,
        //nema restrikcija oko broja Qlabela u formi

        QString labelName = "gamelabel" + QString::number(i+1);
        QLabel* label = ui->centralwidget->findChild<QLabel*>(labelName);
        if (label != nullptr) {
            fields.insert(i, label);
            gameLogic->checkWinCondition();
        }
    }

}


//nacrtaj igraca X
void MainWindow::setPlayerImage_X(QLabel &label)
{
    label.setPixmap(playerX_image);
}

//nacrtaj igraca O
void MainWindow::setPlayerImage_O(QLabel &label)
{

    label.setPixmap(playerO_image);
}


void MainWindow::mousePressEvent(QMouseEvent* click)
{

    if (currentPlayer % 2 == 0 && (click->button()==Qt::LeftButton || click->button()==Qt::RightButton))
    {
        for (int i = 0; i < fields.size(); i++)
        {
            if (fields.value(i)->underMouse() && fields.value(i)->isEnabled() && i < taken.size() && taken[i] == 0)
            {
                setPlayerImage_X(*fields.value(i));
                taken[i] = 1;
                int result = gameLogic->checkWinCondition();
                if (result == 4)
                {
                    setUnplayable();
                    ui->winnerX->setVisible(true);
                    ui->playAgainButton->setVisible(true);
                }
                else if (result == 13)
                {
                    setUnplayable();
                    ui->playAgainButton->setVisible(true);
                    ui->drawLabel->setVisible(true);
                }
                currentPlayer++;
                break;
            }
        }
    }
    else if (click->button()==Qt::LeftButton || click->button()==Qt::RightButton)
    {
        for (int i = 0; i < fields.size(); i++)
        {
            if (fields.value(i)->underMouse() && fields.value(i)->isEnabled() && i < taken.size() && taken[i] == 0)
            {
                setPlayerImage_O(*fields.value(i));
                taken[i] = 2;
                int result = gameLogic->checkWinCondition();
                if (result == 6)
                {
                    setUnplayable();
                    ui->winnerO->setVisible(true);
                    ui->playAgainButton->setVisible(true);
                }
                else if (result == 13)
                {
                    setUnplayable();
                    ui->drawLabel->setVisible(true);
                    ui->playAgainButton->setVisible(true);

                }
                currentPlayer++;
                break;
            }
        }
    }




    //ovo sve iznad je prilagodena logika za QMainWindow::mousePressEvent, a ispod poziv ostatka funkcije frameworka
    QMainWindow::mousePressEvent(click);
}


const std::vector<int>& MainWindow::getTaken()
{
    return taken;
}

void MainWindow::setUnplayable()
{
    QList<QLabel*> allLabels = this->findChildren<QLabel*>();
    for(QLabel* label : allLabels)
    {
        if(label->objectName().startsWith("gamelabel"))
        {
            label->setEnabled(false);
        }
    }
}

void MainWindow::setStartGame()
{
    QList<QLabel*> allLabels = this->findChildren<QLabel*>();
    for(QLabel* label : allLabels)
    {
        if(label->objectName().startsWith("gamelabel"))
        {
            label->setEnabled(true);
        }
    }
    ui->playButton->setVisible(false);
}

void MainWindow::setPlayable()
{
    QList<QLabel*> allLabels = this->findChildren<QLabel*>();
    for(QLabel* label : allLabels)
    {
        if(label->objectName().startsWith("gamelabel"))
        {
            label->setEnabled(true);
        }
    }

    ui->playAgainButton->setVisible(false);
    ui->winnerX->setVisible(false);
    ui->winnerO->setVisible(false);
    ui->drawLabel->setVisible(false);

    for (int i = 0; i < fields.size(); i++)
    {
        fields.value(i)->clear();
        taken[i] = 0;
    }

    currentPlayer = 0;
}


MainWindow::~MainWindow()
{
    delete ui;
}


