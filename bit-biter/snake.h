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

class Snake : public QObject
{
    Q_OBJECT
public:
	enum Direction {UP, DOWN, LEFT, RIGHT};

    explicit Snake(QObject *parent = 0);

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


signals:

public slots:

};

#endif // SNAKE_H
