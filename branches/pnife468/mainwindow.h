//--------------------------------------------------------------
// Program: Bit Biter
// Course: Computer Science II (Cps 111)
// Name: Benjamin Matthews (bmatt468)
// Date: 3/22/12
// Description: Presents interface for user to either start a new game
// with a specified difficulty or load a previously saved game
// from disk.
//--------------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFontDatabase>
#include <options.h>
#include <QString>
#include "gameform.h"
#include <QSound>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    QString bodyColor;
    QString foodColor;
    QString deadColor;
    QSound *title;
    bool muted;

private slots:
    void on_pushButton_3_clicked();
    void on_mute_button_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void setBodyColor(QColor qc);
    void setFoodColor(QColor qc);
    void setDeadColor(QColor qc);

};

#endif // MAINWINDOW_H


