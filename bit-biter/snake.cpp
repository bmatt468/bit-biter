#include "snake.h"
#include <stdlib.h>

Snake::Snake(QObject *parent, QPoint headLoc, int length, Direction dir) :
	QObject(parent),
	bodySegments(NULL),
	isDead(false),
	direction(dir)
{
	bodySegments = new QList<QPoint>();
	bodySegments->push_back(headLoc);

	// create body segments after head
	QPoint bodySegment = headLoc;

	QPoint transformPoint;
	switch (dir){
	case UP:
		transformPoint = QPoint(0,-1);
	case DOWN:
		transformPoint = QPoint(0,1);
	case LEFT:
		transformPoint = QPoint(-1,0);
	case RIGHT:
		transformPoint = QPoint(1,0);
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

