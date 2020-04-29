#ifndef START_H
#define START_H
#include <QtSql>
#include<start.h>
#include<QDebug>
#include <QFileInfo>
#include <QDialog>

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();
public:
   QSqlDatabase mydb;
    void connclose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connopen(){
        QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Diou/Documents/thelast - Copy/New folder/aa.db");

        if(!mydb.open()){
            qDebug()<<("failed");
        return false;
        }
        else{
           qDebug()<<("connected");
    return true;
        }
    }

private slots:
    void timer_timeout();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();
    void callme();






private:
    Ui::start *ui;
};

#endif // START_H



