#include "gameform.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{    
    ui->setupUi(this);
    g = new GameBoard();
    connect(g, SIGNAL(needsUpdate()), this, SLOT(refreshBoard())); // update snake position
    g->start();
    l = new QLabel(this);
}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::closeEvent(QCloseEvent *event)
{
    emit(closed());
}

void GameForm::refreshBoard()
{
    s = g->getSnake();
}

void GameForm::focusOutEvent(QFocusEvent *)
{
    l->setText("PAUSED");
    l->show();
}

void GameForm::focusInEvent(QFocusEvent *)
{
    l->hide();
}
