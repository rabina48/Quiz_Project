#include "finish.h"
#include "ui_finish.h"
#include"start.h"


finish::finish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);



    ui->label->setText("Game over");



}

finish::~finish()
{
    delete ui;
}


