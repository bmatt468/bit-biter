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

};

#endif // GAMEFORM_H
