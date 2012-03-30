#include "mainwindow.h"
#include "gameform.h"
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
    GameForm *g = new GameForm();
    connect(g, SIGNAL(closed()), this, SLOT(show()));
    g->setFocus();
    g->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
   Options *o = new Options();
   o->show();
}
