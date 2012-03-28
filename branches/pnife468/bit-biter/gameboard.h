//--------------------------------------------------------------
// Program: Bit Biter
// Course: Computer Science II (Cps 111)
// Name: Nathaniel Palmer (NPALM479)
// Date: 3/12/12
// Description: Encapsulates game logic. Uses QTimer to continuously
// update state.
//--------------------------------------------------------------

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include <QTimer>
#include <QPoint>
#include "snake.h"

class Snake;

class GameBoard : public QObject
{
    Q_OBJECT
public:
	//--------------------------------------------------------------
	// explicit GameBoard(QObject *parent = 0)
	// Purpose: Constructs a new GameBoard object with dimensions of
	// 50 x 50 tiles and a gameplay speed of one move every 1/2 second.
	// Limitations: none
	// Assumptions: none
	// Return: a pointer to a new GameBoard object
	//--------------------------------------------------------------

	explicit GameBoard(QObject *parent = 0);

	~GameBoard();

	//--------------------------------------------------------------
	// int getHeight()
	// Purpose: retrieves the height of the gameboard grid
	// Limitations: none
	// Assumptions: none
	// Return: an integer representing the height of the gameboard grid
	//--------------------------------------------------------------

	int getHeight();

	//--------------------------------------------------------------
	// int getWidth()
	// Purpose: retrieves the width of the gameboard grid
	// Limitations: none
	// Assumptions: none
	// Return: an integer representing the width of the gameboard grid
	//--------------------------------------------------------------

	int getWidth();

	//--------------------------------------------------------------
	// int getScore()
	// Purpose: retrieves the player's current score as determined
	// by how much food his snake has eaten
	// Limitations: none
	// Assumptions: none
	// Return: an integer representing the score
	//--------------------------------------------------------------

	int getScore();

	//--------------------------------------------------------------
	// QPoint getFood()
	// Purpose: retrieves a point describing the location
	// of the next piece of food on the gameboard
	// Limitations: none
	// Assumptions: none
	// Return: a QPoint representing the location of the next piece
	// of food in terms of the gameboard's coordinate system
	//--------------------------------------------------------------

	QPoint getFood();

	//--------------------------------------------------------------
	// Snake *getSnake()
	// Purpose: retrieves the gameboard's snake object
	// Limitations: none
	// Assumptions: none
	// Return: a pointer to a Snake object
	//------------------------------------------------------------

    Snake *getSnake();

	//--------------------------------------------------------------
	// void start()
	// Purpose: starts gameplay if game is paused or has not yet
	// started
	// Limitations: has no effect if game is over
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

    void start();

	//--------------------------------------------------------------
	// void pause()
	// Purpose: pauses gameplay
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

    void pause();

	//--------------------------------------------------------------
	// bool checkIsGameOver()
	// Purpose: Retrieves value indicating whether game is over. Gameplay
	// ends when the snake collides with an obstacle.
	// Limitations: none
	// Assumptions: none
	// Return: true if game is over, false if it is still active
	//--------------------------------------------------------------

    bool checkIsGameOver();

	//--------------------------------------------------------------
	// void foodWasEaten()
	// Purpose: Indicates to the gameboard that the food was eaten.
	// Generates a new piece of food and increments the score.
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void foodWasEaten();

signals:

	//--------------------------------------------------------------
	// void needsUpdate()
	// Purpose: Emitted when game state has changed. Forms wishing to
	// display gameplay should listen to this signal and update when
	// it is triggered.
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

    void needsUpdate();

private:
    QTimer *timer;
    int score;
	int width, height;
	QPoint food;
    Snake *snake;
	bool isGameOver;

	//--------------------------------------------------------------
	// void generateFood()
	// Purpose: Places a new piece of food on the gameboard at a
	// random location.
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void generateFood();

public slots:
	//--------------------------------------------------------------
	// void tick()
	// Purpose: Updates game state.
	// Limitations: none
	// Assumptions: should be called by internal timer at regular intervals
	// Return: nothing
	//--------------------------------------------------------------

	void tick();
};

#endif // GAMEBOARD_H
