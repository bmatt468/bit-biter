#include "gameform.h"
#include "mainwindow.h"
#include "ui_gameform.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{
    inter = 1000;
    ui->setupUi(this);
    QTimer *t = new QTimer(this);
    t->setInterval(inter);
    //connect(t, SIGNAL(timeout()), this,) *need to get slot to get snake*
    t->start();
}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::closeEvent(QCloseEvent *event)
{
    emit(closed());
}
