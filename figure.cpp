#include "figure.h"

Figure::Figure()
{
    figView = static_cast<figurs>(qrand()%7);
    if (figView==0){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(80,20)};
        figCol = QColor(0, 191, 255);
    }
    else if(figView==1){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(120,20)};
        figCol = QColor(30, 144, 255);
    }
    else if(figView==2){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(100,20)};
        figCol = QColor(100, 149, 237);
    }
    else if(figView==3){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(140,0)};
        figCol = QColor(123, 104, 238);
    }
    else if(figView==4){
        myFigure=QVector<QPoint>{QPoint(80,20),QPoint(100,20),QPoint(100,00),QPoint(120,00)};
        figCol = QColor(65, 105, 225);
    }
    else if(figView==5){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(100,20),QPoint(120,20)};
        figCol = QColor(138, 43, 226);
    }
    else if(figView==6){
        myFigure=QVector<QPoint>{QPoint(100,0),QPoint(120,0),QPoint(100,20),QPoint(120,20)};
        figCol = QColor(148, 0, 211);
    }
}

void Figure::rotate()
{
    QPoint p = myFigure[1];
    if(figView!=6){
        for(int i = 0; i <myFigure.size(); i++){
            int X = myFigure[i].x()-p.x();
            int Y = myFigure[i].y()-p.y();
           myFigure[i] = QPoint(p.x()+Y,p.y()-X);
        }
    }
}

void Figure::setDown(uint W)
{
    for(auto&X:myFigure){
        X = QPoint(X.x(),X.y()+W);
    }
}

void Figure::refresh()
{
    figView = static_cast<figurs>(qrand()%7);
    if (figView==0){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(80,20)};
        figCol = QColor(0, 191, 255);
    }
    else if(figView==1){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(120,20)};
        figCol = QColor(30, 144, 255);
    }
    else if(figView==2){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(100,20)};
        figCol = QColor(100, 149, 237);
    }
    else if(figView==3){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(140,0)};
        figCol = QColor(123, 104, 238);
    }
    else if(figView==4){
        myFigure=QVector<QPoint>{QPoint(80,20),QPoint(100,20),QPoint(100,00),QPoint(120,00)};
        figCol = QColor(65, 105, 225);
    }
    else if(figView==5){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(100,20),QPoint(120,20)};
        figCol = QColor(138, 43, 226);
    }
    else if(figView==6){
        myFigure=QVector<QPoint>{QPoint(100,0),QPoint(120,0),QPoint(100,20),QPoint(120,20)};
        figCol = QColor(148, 0, 211);
    }
}

void Figure::figureMove(bool direction, uint W)
{
    if(direction){
        for(auto&X:myFigure){
            X = QPoint(X.x()+W, X.y());
        }
    }
    else{
        for(auto&X:myFigure){
            X = QPoint(X.x()-W, X.y());
        }
    }
}
