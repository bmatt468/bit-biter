//--------------------------------------------------------------
// Program: Bit Biter
// Course: Computer Science II (Cps 111)
// Name: Nathaniel Palmer (NPALM479)
// Date: 3/12/12
// Description: Presents game state to user and handles user input
// including game controls.
//--------------------------------------------------------------

#ifndef GAMEFORM_H
#define GAMEFORM_H

#include <QWidget>

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

signals:
    void closed();

private slots:

};

#endif // GAMEFORM_H
