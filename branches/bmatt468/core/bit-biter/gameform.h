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

namespace Ui {
    class GameForm;
}

class GameForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameForm(QWidget *parent = 0);
    ~GameForm();

private:
    Ui::GameForm *ui;
    void closeEvent(QCloseEvent *);
    int inter;

signals:
    void closed();

private slots:
    void refreshBoard();

};

#endif // GAMEFORM_H
