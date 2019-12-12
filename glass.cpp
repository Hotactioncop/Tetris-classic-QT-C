#include "glass.h"
#include <QKeyEvent>

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    glassArray.resize(m_rows);
    for(auto&X:glassArray){
        X.resize(m_columns);
        X.fill(emptyCell);
    }
    s.setWidth(W*m_columns);
    s.setHeight(W*m_rows);
    setFixedSize(s);
    current = new Figure;
    next = new Figure;
    pix.load("Images/BlueSquare.jpg");
}

void Glass::recolorGlass()
{
    //Копируем цвет фигуры в форму. Меняем следующую и текущую фигуру и обновляем следующую фигуру. Вызываем метод проверки формы на заполненный ряд.
    for(auto&X:current->myFigure){
        glassArray[X.y()/W][X.x()/W]=current->figCol;
    }
    std::swap(next,current);
    next->refresh();
    emit sendNextFigure(next);
    refreshGlass();
    for(auto&X:current->myFigure){              // Если место появления новой фигуры уже занято, то останавливаю игру и вывожу на экран заполненную форму.
        if(glassArray[X.y()/W][X.x()/W]!=emptyCell){
                killTimer(idTimer);
                gameOn = false;
                QString str = "GAME OVER.";
                QMessageBox::information(this,"Message", str);
                return;
        }
    }
    repaint();
}

void Glass::spaceFigure()
{
    //По нажатию клавиши "SPACE" опускаем фигуру вниз, пока не встретим конец формы или другой цвет.
    //Если встретим конец формы или другой цвет на пути, то вызываем метод перерисовки фигуры в нашу форму и вызова новой фигуры в начало.
    for(auto&X:current->myFigure){
        if(X.y()==W*(m_rows-1) || glassArray[(X.y()+W)/W][X.x()/W]!=emptyCell){
            recolorGlass();
            return;
        }
    }
    current->setDown(W);
}

void Glass::refreshGlass()
{
    //Метод проверки формы на заполненный ряд. Если ряд заполнен, то очищаем его и вызываем метод опускания верхних рядов вниз(передаем очищенный ряд).
    for(int i = 0; i< m_rows; i++){
        for(int j = 0; j<m_columns; j++){
            if(glassArray[i][j]==emptyCell){
                break;
            }
            if(j==10 && glassArray[i][j]!=emptyCell){
                glassArray[i].fill(emptyCell);
                score += 10*m_columns;
                emit sendScore(score);
                move_glass(i);
            }
        }
    }
}

void Glass::move_glass(int I)
{
    //Метод опускания верхних рядов вниз.
    for(int i = I; i>0; i--){
        glassArray[i]=glassArray[i-1];
    }
    glassArray[0].fill(emptyCell); //После опускания рядов - первый ряд заполняем дефолтным цветом.
}

void Glass::gameStart()
{
    if(gameOn){                     //Если игра идет, то обнуляем результаты и очищаем форму.
        if(pause){
            pause = false;
            emit sendPauseSignal();
        }
        else {
            killTimer(idTimer);
        }
    }
    for(auto&X:glassArray){
        X.fill(emptyCell);
    }
    current->refresh();
    next->refresh();
    emit sendNextFigure(next);
    gameOn = true;
    score = 0;
    emit sendScore(score);
    emit sendNextFigure(next);
    idTimer = startTimer(300);
    this->setFocus();
}

void Glass::pausePressed()
{
    if(gameOn){
        if(pause == false){
            killTimer(idTimer);
            pause = true;
            emit sendPauseSignal();
        }
        else {
            idTimer = startTimer(300);
            pause = false;
            emit sendPauseSignal();
        }
    }
}

void Glass::stopPressed()
{
    if(gameOn){
        if (pause == true){
            pause = false;
            emit sendPauseSignal();
        }
        else {
            killTimer(idTimer);
        }
    }
    gameOn = false;
    for(auto&X:glassArray){
        X.fill(emptyCell);
    }
    current->refresh();
    next->refresh();

    repaint();
}

void Glass::timerEvent(QTimerEvent *event)
{
    if(gameOn){
        for(auto&X:current->myFigure){
            if(X.y()==W*(m_rows-1) || glassArray[(X.y()+W)/W][X.x()/W]!=emptyCell){
                recolorGlass();
                repaint();
                return;
            }
        }
        current->setDown(W);
        repaint();
    }
}

void Glass::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    for(uint i = 0; i<m_columns; i++){
        for(uint j = 0; j<m_rows; j++){
            pen.fillRect(i*W,j*W,W-1,W-1,glassArray[j][i]);
        }
    }
    if(gameOn){
        int i = 0;
        for(auto&X:current->myFigure){
                i++;
           pen.fillRect(X.x(),X.y(),W-1,W-1,current->figCol);
        }
    }
}


void Glass::keyPressEvent(QKeyEvent *event)
{
    if(gameOn){
        if(event->key()==Qt::Key_Up){
            QPoint p = current->myFigure[1];
            for(int i = 0; i < current->myFigure.size(); i++){
                int X = current->myFigure[i].x()-p.x();
                int Y = current->myFigure[i].y()-p.y();
                QPoint checkPoint = QPoint(p.x()+Y,p.y()-X);
               if(checkPoint.x()<0 || checkPoint.x()>= m_columns*W || checkPoint.y()>=m_rows*W || glassArray[checkPoint.y()/W][checkPoint.x()/W]!=emptyCell){
                   return;
                }
            }
           current->rotate();
           repaint();
        }
        else if(event->key()==Qt::Key_Left){
            for(auto&X:current->myFigure){
                if(X.x()==0*W || glassArray[X.y()/W][(X.x()-W)/W]!=emptyCell){
                    return;
                }
            }
            current->figureMove(false, W);
            repaint();
        }
        else if(event->key()==Qt::Key_Right){
            for(auto&X:current->myFigure){
                if(X.x()==(m_columns-1)*W || glassArray[X.y()/W][(X.x()+W)/W]!=emptyCell){
                    return;
                }
            }
            current->figureMove(true, W);
            repaint();
        }
        else if(event->key()==Qt::Key_Space){
            spaceFigure();
            repaint();
        }
    }
}

