#include "start.h"
#include "ui_start.h"
#include<QApplication>
#include <QMediaPlayer>
#include<QTimer>
#include"finish.h"
QString option5;
QString count;
QString counter;
QString score;

int bounty;
int counte=1;

QTimer *timer;
int cnt=172;


start::start(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::start)

{

    ui->setupUi(this);//constructor

    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/prefix1/New folder/joined.mp3"));
     music->play();


    mydb=QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("C:/Users/Diou/Documents/thelast - Copy/New folder/aa.db");

   if(!mydb.open())
       ui->rabina->setText("failed");
   else

       ui->rabina->setText("connected");


    counter='1';



  timer=new QTimer(this);
timer->setInterval(1000);
       connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
       timer->start();

callme();


   QSqlQuery query1;
 query1.exec("select count(*) from questions");



    (query1.next());
 {
       count =query1.value(0).toString();
       //ui->label_2->setText(count);



   }


//   ui->label->setText(name);
//  // QString option1=query.value(1).toString();
//   ui->pushButton->setText(option1);
//   //QString option2=query.value(2).toString();
//   ui->pushButton_2->setText(option2);
//   //QString option3=query.value(3).toString();

//   ui->pushButton_3->setText(option3);
//   //QString option4=query.value(4).toString();
//   ui->pushButton_4->setText(option4);


}
void start::timer_timeout()
{
    cnt--;
    ui->timer->setText(QString::number(cnt));
    if(cnt==0)
    {
       finish finish;
       finish.setModal(true);
       finish.exec();
       close();
    }
}

start::~start()
{
    delete ui;
}
void start::callme(){
    QSqlQuery query;





   query.exec("SELECT * from questions where id = '" +counter+"' ");





         if(query.exec()){
             ui->label->setText("finished");
         }

         while (query.next()){

             QString name= query.value(0).toString();
            ui->label->setText(name);
            QString option1=query.value(1).toString();
             ui->pushButton->setText(option1);
             QString option2=query.value(2).toString();
             ui->pushButton_2->setText(option2);
             QString option3=query.value(3).toString();

             ui->pushButton_3->setText(option3);
             QString option4=query.value(4).toString();
             ui->pushButton_4->setText(option4);

              option5=query.value(5).toString();


         }


}






void start::on_pushButton_clicked()
{
if(counte<=38)
{
    if (ui->pushButton->text() == option5 ){

        bounty=counter.toInt() + 1;
        counter = QString ("%1").arg(bounty);
        bounty=score.toInt() + 1;

        score= QString ("%1").arg(bounty);

 ui ->label_7->setText(score);

        ui->label_2->setText("    You are right");
        QMediaPlayer * music=new QMediaPlayer();
         music->setMedia(QUrl("qrc:/prefix1/New folder/clap.mp3"));
         music->play();
         counte++;
         callme();

    }


    else
    {
        ui->label_2->setText("    You are wrong");
        bounty=counter.toInt() + 1;
        counter = QString ("%1").arg(bounty);
        QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/prefix1/New folder/buzz.mp3"));
         music->play();
         counte++;
        callme();
       }
    }

else
{
    close();
    finish finish;
    finish.setModal(true);
    finish.exec();
}
}

void start::on_pushButton_2_clicked()
    {
    if(counte<=38)
    {
    if (ui->pushButton_2->text() == option5 ){


        ui->label->setText(counter);
        bounty=counter.toInt() + 1;
        counter = QString ("%1").arg(bounty);
ui->label_2->setText("    You are right");
bounty=score.toInt() + 1;
score= QString ("%1").arg(bounty);

  ui ->label_7->setText(score);

QMediaPlayer * music=new QMediaPlayer();
music->setMedia(QUrl("qrc:/prefix1/New folder/clap.mp3"));
 music->play();
 counte++;
 callme();


    }
    else
 {
         ui->label_2->setText("    You are wrong");
         bounty=counter.toInt() + 1;
         counter = QString ("%1").arg(bounty);
         QMediaPlayer * music=new QMediaPlayer();
         music->setMedia(QUrl("qrc:/prefix1/New folder/buzz.mp3"));
          music->play();
          counte++;
          callme();


    }
}
    else
    {
        close();
        finish finish;
        finish.setModal(true);
        finish.exec();
    }
}


void start::on_pushButton_3_clicked()
{
    if(counte<=38)
    {
    if (ui->pushButton_3->text() == option5 ){

        bounty=counter.toInt() + 1;
        counter = QString ("%1").arg(bounty);

        ui->label_2->setText(counter);
        ui->label_2->setText("    You are right");
        bounty=score.toInt() + 1;
        score= QString ("%1").arg(bounty);

         ui ->label_7->setText(score);

        QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/prefix1/New folder/clap.mp3"));
         music->play();
         counte++;
         callme();


    }
    else
         {

        ui->label_2->setText("    You are wrong");
        bounty=counter.toInt() + 1;
        counter = QString ("%1").arg(bounty);
        QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/prefix1/New folder/buzz.mp3"));
         music->play();
         counte++;
         callme();


}
    }
    else{

        close();
        finish finish;
        finish.setModal(true);
        finish.exec();
    }
}

void start::on_pushButton_4_clicked()
{
    if(counte<=38)
    {
    if (ui->pushButton_4->text() == option5 ){

        bounty=counter.toInt() + 1;


        counter = QString ("%1").arg(bounty);

        ui->label->setText(counter);
        ui->label_2->setText("     You are right");
        bounty=score.toInt() + 1;

        score= QString ("%1").arg(bounty);


    ui ->label_7->setText(score);

        QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/prefix1/New folder/clap.mp3"));
         music->play();
        counte++;
            callme();



    }
    else{
        ui->label_2->setText("    You are wrong");
        QMediaPlayer * music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:/prefix1/New folder/buzz.mp3"));
         music->play();
        bounty=counter.toInt() + 1;
        counter = QString ("%1").arg(bounty);
        counte++;
        callme();

    }
    }

    else
    {

        close();

        finish finish;
        finish.setModal(true);
        finish.exec();
    }
 }

