#include "snake.h"
#include <stdlib.h>

Snake::Snake(GameBoard *board, QPoint headLoc, int length, Direction dir) :
	QObject(NULL),
	bodySegments(NULL),
	isDead(false),
	direction(dir),
	board(board)
{
	bodySegments = new QList<QPoint>();
	bodySegments->push_back(headLoc);

	// create body segments after head
	QPoint bodySegment = headLoc;

	QPoint transformPoint;
	switch (dir){
	case UP:
                transformPoint = QPoint(0,1);
                break;
	case DOWN:
                transformPoint = QPoint(0,-1);
                break;
	case LEFT:
                transformPoint = QPoint(1,0);
                break;
	case RIGHT:
                transformPoint = QPoint(-1,0);
                break;
	default:
		transformPoint = QPoint(0,0);
	}

	for (int i = 0; i < length - 1; i++){
		bodySegment += transformPoint;
		bodySegments->push_back(bodySegment);
	}
}

QList<QPoint> *Snake::getBodySegments(){
	return bodySegments;
}

bool Snake::checkIsDead(){
	return isDead;
}

void Snake::changeDirection(Snake::Direction newDir){
	if (abs(newDir - direction) != 2){ // ensure newDir is not opposite of current direction
		direction = newDir;
	}
}

void Snake::move(){
	QPoint transformPoint;
	switch (direction){
	case UP:
		transformPoint = QPoint(0,-1);
                break;
	case DOWN:
		transformPoint = QPoint(0,1);
                break;
	case LEFT:
		transformPoint = QPoint(-1,0);
                break;
	case RIGHT:
		transformPoint = QPoint(1,0);
                break;
	default:
		transformPoint = QPoint(0,0);
	}

	QPoint newHead = bodySegments->first() + transformPoint;

	// handle wrapping
	if (newHead.x() == board->getWidth()){
		newHead.setX(0);
	}
	if (newHead.x() == -1){
		newHead.setX(board->getWidth() - 1);
	}
	if (newHead.y() == board->getHeight()){
		newHead.setY(0);
	}
	if (newHead.y() == -1){
		newHead.setY(board->getHeight() - 1);
	}

	if (newHead == board->getFood()){
		eatFood();
	}

	bodySegments->push_front(newHead);
	bodySegments->removeLast();
}

void Snake::eatFood(){
	QPoint transformPoint;
	switch (direction){
	case UP:
				transformPoint = QPoint(0,1);
				break;
	case DOWN:
				transformPoint = QPoint(0,-1);
				break;
	case LEFT:
				transformPoint = QPoint(1,0);
				break;
	case RIGHT:
				transformPoint = QPoint(-1,0);
				break;
	default:
		transformPoint = QPoint(0,0);
	}

	QPoint newSegment = bodySegments->last() + transformPoint;
	bodySegments->push_back(newSegment);

	board->foodWasEaten();
}

