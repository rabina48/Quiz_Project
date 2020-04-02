#include "front.h"
#include "ui_front.h"
#include"start.h"
#include<QMediaPlayer>
front::front(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::front)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Diou/Documents/thelast - Copy/New folder/ready-quiz.gif");
     ui->label->setPixmap(pix);

}

front::~front()
{
    delete ui;
}

void front::on_pushButton_clicked()
{
    start kusum;
    kusum.setModal(true);
    kusum.exec();

 this->close();
}
