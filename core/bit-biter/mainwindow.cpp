#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    title = new QSound("fonts/Game SFX/Title Loop.wav");
    title->play();
    ui->mute_button->setFlat(true);
    ui->mute_button->setStyleSheet("border-image: url(:/fonts/fonts/Sound-on-icon.png);");
    this->setFixedSize(391,304);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GameForm *g = new GameForm(0, bodyColor, foodColor, deadColor, false);
    connect(g, SIGNAL(closed()), this, SLOT(show()));
    g->setFocus();    
    g->show();
    title->stop();
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    title->stop();
}

void MainWindow::on_mute_button_clicked()
{
    if (!muted)
    {
        muted = true;
        this->ui->mute_button->hide();
        this->ui->mute_button->setStyleSheet("border-image: url(:/fonts/fonts/Sound-off-icon.png);");
        this->ui->mute_button->show();
        title->stop();
    }

    else
    {
        muted = false;
        this->ui->mute_button->hide();
        this->ui->mute_button->setStyleSheet("border-image: url(:/fonts/fonts/Sound-on-icon.png);");
        this->ui->mute_button->show();
        title->play();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    GameForm *g = new GameForm(0, bodyColor, foodColor, deadColor, true);
    connect(g, SIGNAL(closed()), this, SLOT(show()));
    g->setFocus();
    g->show();
    title->stop();
    this->hide();
}
