#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <QDialog>

namespace Ui {
    class SaveGame;
}

class SaveGame : public QDialog
{
    Q_OBJECT

public:
    explicit SaveGame(QWidget *parent = 0);
    ~SaveGame();
    Ui::SaveGame *ui;

private:

signals:
    void responseGiven(bool ans);

private slots:
    void on_save_no_clicked();
    void on_save_yes_clicked();
};

#endif // SAVEGAME_H
