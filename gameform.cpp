#include "gameform.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{
    ui->setupUi(this);
    this->setFixedSize(399,455);
    this->setFocus();
}

GameForm::GameForm(QWidget *parent, QString snakeColor, QString foodColor, QString deadColor, bool isLoadedGame) :
    QWidget(parent),
    ui(new Ui::GameForm)
{    
    if (!isLoadedGame)
    {
        ui->setupUi(this);
        g = new GameBoard();
        this->setBodyColor(snakeColor);
        this->setFoodColor(foodColor);
        this->setDeadColor(deadColor);
        connect(g, SIGNAL(needsUpdate()), this, SLOT(refreshBoard())); // update snake position
        g->start();
        l = new QLabel(this);
        ui->game_reset->hide();
    }

    else
    {
        ui->setupUi(this);
        QFile file("savegame.terror");
        file.open(QIODevice::ReadOnly);
        QDataStream load(&file);
        load.setVersion(QDataStream::Qt_4_6);
        g = new GameBoard(0,&load);
        g->pause();
        this->setBodyColor(snakeColor);
        this->setFoodColor(foodColor);
        this->setDeadColor(deadColor);
        connect(g, SIGNAL(needsUpdate()), this, SLOT(refreshBoard())); // update snake position
        l = new QLabel(this);
        l->setStyleSheet("border-image: url(:/fonts/fonts/paused.png);");
        l->setGeometry(10,10,300,50);
        l->show();
        paused = !paused;
        ui->game_reset->hide();
        file.close();
    }
}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::closeEvent(QCloseEvent *event)
{
    g->pause();
    if (!g->checkIsGameOver())
    {
        event->ignore();
        SaveGame *sg = new SaveGame();
        connect(sg, SIGNAL(responseGiven(bool)), this, SLOT(saveResponse(bool)));
        sg->show();
    }
    else emit(closed());
}

void GameForm::refreshBoard()
{
    if (!g->checkIsGameOver())
    {
        QList<QPushButton*> oldSegments = this->findChildren<QPushButton *>("snake");
        for (int i = 0; i < oldSegments.count(); ++i)
        {
            oldSegments.value(i)->deleteLater();
        }

        QPushButton *oldFood = this->findChild<QPushButton *>("food");
        oldFood->deleteLater();

        s = g->getSnake();
        snakesegs = s->getBodySegments();

        QSize qz(20,20);
        for (int i = 0; i < snakesegs->count(); ++i)
        {
            QPushButton *snakeSeg = new QPushButton(this);
            snakeSeg->setObjectName("snake");
            QRect qr(snakesegs->value(i) *= 20, qz);
            snakeSeg->setGeometry(qr);
            snakeSeg->setStyleSheet(bodyGrad);
            snakeSeg->show();
        }

        QRect foodLoc(g->getFood() * 20, qz);
        QPushButton *food = new QPushButton(this);
        food->setGeometry(foodLoc);
        food->setObjectName("food");
        food->setStyleSheet(foodGrad);
        food->show();

        ui->score->display(g->getScore());
    }

    else
    {
        QList<QPushButton*> deadSnake = this->findChildren<QPushButton *>("snake");
        for (int i = 0; i < deadSnake.count(); ++i)
        {
            deadSnake.value(i)->hide();
            deadSnake.value(i)->setStyleSheet(deadGrad);
            deadSnake.value(i)->show();
        }

        l->setStyleSheet("border-image: url(:/fonts/fonts/gameover.png);");
        l->setGeometry(10,10,375,50);
        l->show();
        ui->game_reset->show();
    }

}

void GameForm::focusOutEvent(QFocusEvent *)
{    
    l->setStyleSheet("border-image: url(:/fonts/fonts/paused.png);");
    l->setGeometry(10,10,300,50);
    l->show();
    g->pause();
}

void GameForm::focusInEvent(QFocusEvent *)
{
    l->hide();
    g->start();
}

void GameForm::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case (Qt::Key_Up):
        {
            g->getSnake()->changeDirection(Snake::UP);
            break;
        }

        case (Qt::Key_Left):
        {
            g->getSnake()->changeDirection(Snake::LEFT);
            break;
        }

        case (Qt::Key_Right):
        {
            g->getSnake()->changeDirection(Snake::RIGHT);
            break;
        }

        case (Qt::Key_Down):
        {
            g->getSnake()->changeDirection(Snake::DOWN);
            break;
        }

    case (Qt::Key_P):
        {
            if (!paused)
            {
                g->pause();
                l->setStyleSheet("border-image: url(:/fonts/fonts/paused.png);");
                l->setGeometry(10,10,300,50);
                l->show();
                paused = !paused;
            }

            else
            {
                g->start();
                l->hide();
                paused = !paused;
            }

            break;
        }
    }
}

void GameForm::on_game_reset_clicked()
{
    g->deleteLater();
    g = new GameBoard();
    connect(g, SIGNAL(needsUpdate()), this, SLOT(refreshBoard())); // update snake position
    g->start();
    l->hide();
    ui->game_reset->hide();
}

void GameForm::setBodyColor(QString color)
{
    if (color != "")
    {
        bodyGrad = QString::fromStdString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 {BASECOLOR}, stop:1 rgba(255, 255, 255, 255));"
                                            "border-radius: 5px;");
        bodyGrad = bodyGrad.replace(QString("{BASECOLOR}"),color);
    }

    else
    {
        bodyGrad = QString::fromStdString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 127, 255), stop:1 rgba(255, 255, 255, 255));"
                                          "border-radius: 5px;");
    }
}

void GameForm::setFoodColor(QString color)
{
    if (color != "")
    {
        foodGrad = QString::fromStdString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 {BASECOLOR}, stop:1 rgba(255, 255, 255, 255));"
                                            "border-radius: 5px;");
        foodGrad = foodGrad.replace(QString("{BASECOLOR}"),color);
    }

    else
    {
        foodGrad = QString::fromStdString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 200, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                                          "border-radius: 5px;");
    }
}

void GameForm::setDeadColor(QString color)
{
    if (color != "")
    {
        deadGrad = QString::fromStdString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 {BASECOLOR}, stop:1 rgba(220, 220, 220, 255));"
                                      "border-radius: 5px;");
        deadGrad = deadGrad.replace(QString("{BASECOLOR}"),color);
    }

    else
    {
        deadGrad = QString::fromStdString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(200, 0, 0, 255), stop:1 rgba(220, 220, 220, 255));"
                                      "border-radius: 5px;");
    }
}

void GameForm::saveResponse(bool ans)
{
    if (ans)
    {
        QFile file("savegame.terror");
        file.open(QIODevice::WriteOnly);
        QDataStream save(&file);
        save.setVersion(QDataStream::Qt_4_6);
        g->SaveGame(&save);
        file.close();
        emit(closed());
    }

    if (!ans)
    {
        emit(closed());
    }

    this->deleteLater();
}
