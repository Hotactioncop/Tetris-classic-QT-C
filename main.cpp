#include "tetris.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TETRIS w;
    w.show();

    return a.exec();
}
