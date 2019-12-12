#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include <QFrame>
#include <QSize>
#include <QPainter>
#include "figure.h"

class NextFigure : public QFrame
{
    Q_OBJECT
    Figure* next;
    bool gameOn = false;
    QSize s;
    friend class Figure;
public:
    explicit NextFigure(QWidget *parent = nullptr);

signals:

public slots:
    void getNext(Figure*);
    void gameStop();

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // NEXTFIGURE_H
