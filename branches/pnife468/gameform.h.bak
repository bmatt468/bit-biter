//--------------------------------------------------------------
// Program: Bit Biter
// Course: Computer Science II (Cps 111)
// Name: Benjamin Matthews (bmatt468)
// Date: 3/22/12
// Description: Presents game state to user and handles user input
// including game controls.
//--------------------------------------------------------------

#ifndef GAMEFORM_H
#define GAMEFORM_H

#include <QWidget>
#include <QTimer>
#include "gameform.h"
#include "mainwindow.h"
#include "ui_gameform.h"
#include "gameboard.h"
#include "snake.h"
#include <QLabel>


namespace Ui {
    class GameForm;
}

class GameForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameForm(QWidget *parent = 0);
    ~GameForm();
    GameBoard *g;
    Snake *s;


private:
    Ui::GameForm *ui;
    void closeEvent(QCloseEvent *);
    void focusOutEvent(QFocusEvent *);
    void focusInEvent(QFocusEvent *);
    int inter;
    QLabel *l;

signals:
    void closed();

private slots:
    void refreshBoard();

};

#endif // GAMEFORM_H
