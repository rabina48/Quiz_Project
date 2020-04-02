#include "front.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    front w;
    w.show();

    return a.exec();
}
