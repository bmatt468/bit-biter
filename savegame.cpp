#include "savegame.h"
#include "ui_savegame.h"

SaveGame::SaveGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveGame)
{
    ui->setupUi(this);
    this->setFixedSize(400,114);
}

SaveGame::~SaveGame()
{
    delete ui;
}

void SaveGame::on_save_yes_clicked()
{
    emit(responseGiven(true));
    this->deleteLater();
}

void SaveGame::on_save_no_clicked()
{
    emit(responseGiven(false));
    this->deleteLater();
}
