#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GameForm *g = new GameForm(0, bodyColor, foodColor, deadColor);
    connect(g, SIGNAL(closed()), this, SLOT(show()));
    g->setFocus();
    g->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
   Options *o = new Options(this);
   o->show();
}

void MainWindow::setBodyColor(QColor qc)
{    
    bodyColor = qc.toRgb().name();
}

void MainWindow::setFoodColor(QColor qc)
{
    foodColor = qc.toRgb().name();
}

void MainWindow::setDeadColor(QColor qc)
{
    deadColor = qc.toRgb().name();
}
