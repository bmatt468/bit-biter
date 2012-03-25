#include "gameboard.h"

#define INIT_SNAKE_LENGTH 5
#define INIT_BOARD_SIZE 50
#define TIMER_INTERVAL 500

GameBoard::GameBoard(QObject *parent) :
	QObject(parent),
	score(0),
	width(INIT_BOARD_SIZE),
	height(INIT_BOARD_SIZE),
	food(NULL)
{
	timer = new QTimer();
	timer->setInterval(1000);

	generateFood();

	// position snake in center of board
	int headX = (width / 2) - (INIT_SNAKE_LENGTH / 2);
	int headY = height / 2;
	snake = new Snake(this, QPoint(headX, headY), INIT_SNAKE_LENGTH, Snake::LEFT);
}

void GameBoard::generateFood(){

}
