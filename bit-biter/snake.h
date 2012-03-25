//--------------------------------------------------------------
// Program: Bit Biter
// Course: Computer Science II (Cps 111)
// Name: Nathaniel Palmer (NPALM479)
// Date: 3/12/12
// Description: Represents a player's snake on the game board.
// Handles the logic of snake movement and death detection.S
//--------------------------------------------------------------

#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QPoint>
#include <QList>
#include "gameboard.h"

class GameBoard;

class Snake : public QObject
{
    Q_OBJECT
public:
	enum Direction {UP, LEFT, DOWN, RIGHT};

	//--------------------------------------------------------------
	// explicit Snake(GameBoard *board, QPoint headLoc = QPoint(0,0),
	// int length = 1, Direction dir = LEFT)
	// Purpose: Constructs a new instance of the Snake class. The snake's
	// head is positioned at headLoc with the total number of body segments
	// determined by length, the initial direction of travel determined
	// by dir, and the gameboard in which the snake moves determined
	// by board.
	// Limitations: does not handle wrapping in cases where the snake's
	// body extends beyond the gameboard boundaries
	// Assumptions: none
	// Return: a newly allocated instance of the Snake class
	//--------------------------------------------------------------

	explicit Snake(GameBoard *board, QPoint headLoc = QPoint(0,0), int length = 1, Direction dir = LEFT);

	//--------------------------------------------------------------
	// QList<QPoint> *getBodySegments()
	// Purpose: retrieves a list of points describing the locations
	// of all the snake's body segments
	// Limitations: none
	// Assumptions: none
	// Return: A QList containing QPoints representing the locations
	// of all the snake's body segments in terms of the gameboard's
	// coordinate system. The snake's head segment location ssis at index 0.
	//--------------------------------------------------------------

    QList<QPoint> *getBodySegments();

	//--------------------------------------------------------------
	// bool checkIsDead()
	// Purpose: Retrieves value indicating whether or not the snake
	// has died. Death occurs on collision with any obstacle.
	// Limitations: none
	// Assumptions: none
	// Return: true if the snake is dead, false if it is still alive
	//--------------------------------------------------------------

	bool checkIsDead();

	//--------------------------------------------------------------
	// void changeDirection(Snake::Direction newDirection)
	// Purpose: Sets the snake's direction of movement.
	// Limitations: all attempts to change the direction to its opposite
	// (ie. changing LEFT to  RIGHT) are ignored
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void changeDirection(Snake::Direction newDir);

	//--------------------------------------------------------------
	// void move()
	// Purpose: Attempts to move snake one unit forward. If food is in
	// the snakes path it is eaten. If a collision occurs the snake dies.
	// Limitations: does nothing if the snake has already died
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void move();

private:
    QList<QPoint> *bodySegments;
    bool isDead;
	Direction direction;
	GameBoard *board;

	//--------------------------------------------------------------
	// void eatFood()
	// Purpose: grows the snake by one segment and notifies the game
	// board that the food was eaten
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void eatFood();

signals:

public slots:

};

#endif // SNAKE_H
