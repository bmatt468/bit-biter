#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    this->setParent(parent);
}

Options::~Options()
{
    delete ui;
}

void Options::on_body_clicked()
{
    QColorDialog *qc = new QColorDialog();
    qc->show();
    MainWindow *parentWidget = dynamic_cast<MainWindow*>(this->parent());
    connect(qc, SIGNAL(colorSelected(QColor)), parentWidget, SLOT(setBodyColor(QColor)));
}

void Options::on_food_clicked()
{
    QColorDialog *qc = new QColorDialog();
    qc->show();
    MainWindow *parentWidget = dynamic_cast<MainWindow*>(this->parent());
    connect(qc, SIGNAL(colorSelected(QColor)), parentWidget, SLOT(setFoodColor(QColor)));
}

void Options::on_death_clicked()
{
    QColorDialog *qc = new QColorDialog();
    qc->show();
    MainWindow *parentWidget = dynamic_cast<MainWindow*>(this->parent());
    connect(qc, SIGNAL(colorSelected(QColor)), parentWidget, SLOT(setDeadColor(QColor)));
}
