#include "nextfigure.h"

NextFigure::NextFigure(QWidget *parent) : QFrame(parent)
{
    s.setWidth(180);
    s.setHeight(80);
    setFixedSize(s);
}

void NextFigure::getNext(Figure *my_figure)
{
    next = my_figure;
    gameOn = true;
    repaint();
}

void NextFigure::gameStop()
{
    gameOn=false;
    repaint();
}


void NextFigure::paintEvent(QPaintEvent *event)
{
    if (gameOn){
        QPainter pen(this);
        for(auto&X:next->myFigure){
            pen.fillRect(X.x()-20,X.y(), 19, 19, next->figCol);
        }
    }
}
