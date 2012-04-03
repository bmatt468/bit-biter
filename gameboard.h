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
#include <QDataStream>
#include "snake.h"

class Snake;

class GameBoard : public QObject
{
    Q_OBJECT
public:
	enum DifficultyLevel {NONE, EASY, MEDIUM, HARD};

	//--------------------------------------------------------------
	// explicit GameBoard(QObject *parent, DifficultyLevel level))
	// Purpose: Constructs a new GameBoard object with the difficulty
	// level specified by level. If no difficulty level is set, the
	// gameboard size is unchanged throughout gameplay. Otherwise the
	// gameboard shrinks at regular intervals with higher difficulty
	// correponding to shorter intervals.
	// Limitations: none
	// Assumptions: none
	// Return: a pointer to a new GameBoard object
	//--------------------------------------------------------------

	explicit GameBoard(QObject *parent = 0, DifficultyLevel level = NONE);

	//--------------------------------------------------------------
	// GameBoard(QObject *parent, QDataStream *saveData)
	// Purpose: Constructs a gameboard from the data contained in the
	// datastream saveData.
	// Limitations: none
	// Assumptions: the datastream saveData was created by the GameBoard.SaveGame()
	// method
	// Return: a pointer to a new GameBoard object
	//--------------------------------------------------------------

	GameBoard(QObject *parent, QDataStream *saveData);

	~GameBoard();

	//--------------------------------------------------------------
	// void SaveGame(QDataStream *saveData)
	// Purpose: saves the state of the gameboard to the datastream saveData
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void SaveGame(QDataStream *saveData);

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
	// int getCountDown()
	// Purpose: Retrieves the amount of time remaining until gameplay
	// ends. As the countdown runs down, the gameboard size shrinks at
	// regulary intervals determined by the difficulty level.
	// Limitations: none
	// Assumptions: none
	// Return: an integer representing the gameplay time remaining
	//--------------------------------------------------------------

	int getCountdown();

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
	// QPoint getCountdownReload()
	// Purpose: retrieves a point describing the location
	// of the next countdown reload pill on the gameboard
	// Limitations: none
	// Assumptions: none
	// Return: a QPoint representing the location of the next countdown
	// reload pill in terms of the gameboard's coordinate system
	//--------------------------------------------------------------

	QPoint getCountdownReload();

	//--------------------------------------------------------------
	// Snake *getSnake()
	// Purpose: retrieves the gameboard's snake object
	// Limitations: none
	// Assumptions: none
	// Return: a pointer to a Snake object
	//------------------------------------------------------------

    Snake *getSnake();

	//--------------------------------------------------------------
	// DifficultyLevel getDifficultyLevel()
	// Purpose: retrieves the gameboard's difficulty level
	// Limitations: none
	// Assumptions: none
	// Return: a DifficultyLevel specifying the gameboard's difficulty
	// level
	//------------------------------------------------------------

	DifficultyLevel getDifficultyLevel();

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

	//--------------------------------------------------------------
	// void countdownReloadWasEaten()
	// Purpose: Indicates to the gameboard that the countdown reload
	// pill was eaten.
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void countdownReloadWasEaten();

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
	int score, countdown;
	int width, height;
	QPoint food;
	QPoint countdownReload;
    Snake *snake;
	bool isGameOver;
	DifficultyLevel level;

	//--------------------------------------------------------------
	// void generateFood()
	// Purpose: Places a new piece of food on the gameboard at a
	// random location.
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void generateFood();

	//--------------------------------------------------------------
	// void generateCountdownReload()
	// Purpose: Places a new countdown reload pill on the gameboard
	// at a random location.
	// Limitations: none
	// Assumptions: none
	// Return: nothing
	//--------------------------------------------------------------

	void generateCountdownReload();

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
