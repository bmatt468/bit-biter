#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_body_clicked()
{
    QColorDialog *qc = new QColorDialog();
    qc->show();

}
