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

private:
    QList<QPoint> *bodySegments;
    bool isDead;

signals:

public slots:

};

#endif // SNAKE_H
