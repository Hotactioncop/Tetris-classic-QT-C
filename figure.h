#ifndef FIGURE_H
#define FIGURE_H

#include <QVector>
#include <QColor>
#include <QPoint>

class Figure
{
public:
    QVector<QPoint> myFigure;
    enum figurs{L,J,T,I,S,Z,O} figView;
    QColor figCol;

public:
    Figure();
    void rotate();
    void setDown(uint);
    void refresh();
    void figureMove(bool, uint);
};

#endif // FIGURE_H
