#include "gameboard.h"
#include "stdlib.h"
#include "time.h"

#define INIT_SNAKE_LENGTH 5
#define INIT_BOARD_SIZE 50
#define TIMER_INTERVAL 500

GameBoard::GameBoard(QObject *parent) :
	QObject(parent),
	score(0),
	width(INIT_BOARD_SIZE),
	height(INIT_BOARD_SIZE),
	food(QPoint(0,0))
{
	timer = new QTimer();
	timer->setInterval(TIMER_INTERVAL);

	generateFood();

	// position snake in center of board
	int headX = (width / 2) - (INIT_SNAKE_LENGTH / 2);
	int headY = height / 2;
	snake = new Snake(this, QPoint(headX, headY), INIT_SNAKE_LENGTH, Snake::LEFT);
}

void GameBoard::generateFood(){
	srand(time(NULL));
	int randX = rand() % (width + 1);
	int randY = rand() % (height + 1);
	food = QPoint(randX, randY);

	// TODO: Add intelligent placement of food away from snake.
}
