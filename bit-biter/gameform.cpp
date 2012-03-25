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
        QPushButton *test = new QPushButton(this);
        QRect qr(snakesegs->value(i) *= 20, qz);
        test->setGeometry(qr);
        test->show();
    }

    QRect foodLoc(g->getFood() * 20, qz);
    QPushButton *food = new QPushButton(this);
    food->setGeometry(foodLoc);
    food->show();

}

void GameForm::focusOutEvent(QFocusEvent *)
{
    l->setText("PAUSED");
    l->show();
}

void GameForm::focusInEvent(QFocusEvent *)
{
    l->hide();
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
