#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
    class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private:
    Ui::Options *ui;

private slots:
    void on_body_clicked();
};

#endif // OPTIONS_H
