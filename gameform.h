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
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <string>
#include <QMessageBox>
#include <QGroupBox>
#include "savegame.h"
#include "ui_savegame.h"
#include <QCloseEvent>
#include <QDataStream>

namespace Ui {
    class GameForm;
}

class GameForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameForm(QWidget *parent = 0);
    GameForm(QWidget *parent, QString snakeColor, QString foodColor, QString deadColor, bool isLoadedGame);
    ~GameForm();
    GameBoard *g;
    Snake *s;
    QList<QPoint> *snakesegs;
    void keyPressEvent(QKeyEvent *event);    

private:
    Ui::GameForm *ui;
    void closeEvent(QCloseEvent *);
    void focusOutEvent(QFocusEvent *);
    void focusInEvent(QFocusEvent *);
    int inter;
    QLabel *l;
    QString bodyGrad;
    QString foodGrad;
    QString deadGrad;
    void setBodyColor(QString color);
    void setFoodColor(QString color);
    void setDeadColor(QString color);
    bool paused;

signals:
    void closed();    

private slots:
    void on_game_reset_clicked();
    void refreshBoard();
    void saveResponse(bool ans);

};

#endif // GAMEFORM_H
