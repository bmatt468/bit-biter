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
	food(QPoint(0,0)),
	isGameOver(false)
{
	timer = new QTimer();
	timer->setInterval(TIMER_INTERVAL);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

	generateFood();

	// position snake in center of board
	int headX = (width / 2) - (INIT_SNAKE_LENGTH / 2);
	int headY = height / 2;
	snake = new Snake(this, QPoint(headX, headY), INIT_SNAKE_LENGTH, Snake::LEFT);
}

GameBoard::~GameBoard(){
	delete timer;
	delete snake;
}

void GameBoard::generateFood(){
	srand(time(NULL));
	int randX = rand() % (width + 1);
	int randY = rand() % (height + 1);
	food = QPoint(randX, randY);

	// TODO: Add intelligent placement of food away from snake.
}

int GameBoard::getHeight(){
	return height;
}

int GameBoard::getWidth(){
	return width;
}

int GameBoard::getScore(){
	return score;
}

QPoint GameBoard::getFood(){
	return food;
}

Snake *GameBoard::getSnake(){
	return snake;
}

void GameBoard::start(){
	if (!isGameOver){
		timer->start();
	}
}

bool GameBoard::checkIsGameOver(){
	return isGameOver;
}

void GameBoard::tick(){
	emit needsUpdate();
}
