#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include <QTimer>
#include <QPoint>
#include "snake.h"

class GameBoard : public QObject
{
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = 0);
    int getScore();
    QList<QPoint> *getFood();
    Snake *getSnake();
    void start();
    void pause();
    bool checkIsGameOver();

signals:
    void needsUpdate();

public slots:

private:
    QTimer *timer;
    int score;
    QList<QPoint> *food;
    Snake *snake;

    void tick();

};

#endif // GAMEBOARD_H
