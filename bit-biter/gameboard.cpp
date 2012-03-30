#include "gameboard.h"
#include "stdlib.h"
#include "time.h"

#define INIT_SNAKE_LENGTH 5
#define INIT_BOARD_SIZE 20
#define TIMER_INTERVAL 150

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

GameBoard::GameBoard(QObject *parent, QDataStream *saveData) :
		QObject(parent)
{
	int interval;
	*saveData >> interval;
	timer = new QTimer();
	timer->setInterval(interval);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

	*saveData >> score;
	*saveData >> width;
	*saveData >> height;
	*saveData >> food;
	*saveData >> isGameOver;
	snake = new Snake(this, saveData);

	// position snake in center of board
	int headX = (width / 2) - (INIT_SNAKE_LENGTH / 2);
	int headY = height / 2;
	snake = new Snake(this, QPoint(headX, headY), INIT_SNAKE_LENGTH, Snake::LEFT);
}

GameBoard::~GameBoard(){
	delete timer;
	delete snake;
}

void GameBoard::SaveGame(QDataStream *saveData){
	*saveData << timer->interval();
	*saveData << score;
	*saveData << width;
	*saveData << height;
	*saveData << food;
	*saveData << isGameOver;
	snake->save(saveData);
}

void GameBoard::generateFood(){
	srand(time(NULL));
	int randX = rand() % width;
	int randY = rand() % height;
	food = QPoint(randX, randY);
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

void GameBoard::pause(){
	timer->stop();
}

bool GameBoard::checkIsGameOver(){
	return isGameOver;
}

void GameBoard::foodWasEaten(){
	generateFood();
	score += 1;
}

void GameBoard::tick(){
	snake->move();
	if (snake->checkIsDead()){
		isGameOver = true;
		timer->stop();
	}
	emit needsUpdate();
}
