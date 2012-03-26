#include "gameform.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{    
    ui->setupUi(this);
    g = new GameBoard();
    connect(g, SIGNAL(needsUpdate()), this, SLOT(refreshBoard())); // update snake position
    g->start();
    l = new QLabel(this);
}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::closeEvent(QCloseEvent *event)
{
    emit(closed());
}

void GameForm::refreshBoard()
{
    if (!g->checkIsGameOver())
    {
        QList<QPushButton*> oldSegments = this->findChildren<QPushButton *>();
        for (int i = 0; i < oldSegments.count(); ++i)
        {
            oldSegments.value(i)->deleteLater();
        }

        s = g->getSnake();
        snakesegs = s->getBodySegments();

        QSize qz(20,20);
        for (int i = 0; i < snakesegs->count(); ++i)
        {
            QPushButton *snakeSeg = new QPushButton(this);
            snakeSeg->setObjectName("snake");
            QRect qr(snakesegs->value(i) *= 20, qz);
            snakeSeg->setGeometry(qr);
            snakeSeg->setStyleSheet("background-color: rgb(0,0,255);");
            snakeSeg->show();
        }

        QRect foodLoc(g->getFood() * 20, qz);
        QPushButton *food = new QPushButton(this);
        food->setGeometry(foodLoc);
        food->setStyleSheet("background-color: rgb(0,255,0);");
        food->show();
    }

    else
    {
        QList<QPushButton*> deadSnake = this->findChildren<QPushButton *>("snake");
        for (int i = 0; i < deadSnake.count(); ++i)
        {
            deadSnake.value(i)->hide();
            deadSnake.value(i)->setStyleSheet("background-color: rgb(255,0,0)");
            deadSnake.value(i)->show();
        }

        l->setStyleSheet("border-image: url(:/fonts/fonts/gameover.png);");
        l->setGeometry(10,10,375,50);
        l->show();
    }

}

void GameForm::focusOutEvent(QFocusEvent *)
{    
    l->setStyleSheet("border-image: url(:/fonts/fonts/paused.png);");
    l->setGeometry(10,10,300,50);
    l->show();
    g->pause();
}

void GameForm::focusInEvent(QFocusEvent *)
{
    l->hide();
    g->start();
}

void GameForm::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case (Qt::Key_Up):
        {
            g->getSnake()->changeDirection(Snake::UP);
            break;
        }

        case (Qt::Key_Left):
        {
            g->getSnake()->changeDirection(Snake::LEFT);
            break;
        }

        case (Qt::Key_Right):
        {
            g->getSnake()->changeDirection(Snake::RIGHT);
            break;
        }

        case (Qt::Key_Down):
        {
            g->getSnake()->changeDirection(Snake::DOWN);
            break;
        }
    }
}
