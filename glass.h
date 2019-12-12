#ifndef GLASS_H
#define GLASS_H
#define emptyCell QColor(230, 230, 250)

#include <QWidget>
#include <QVector>
#include "figure.h"
#include <QPainter>
#include <QPoint>
#include <qDebug>
#include <QMessageBox>
#include <QString>

static const uint W = 20;

class Glass : public QWidget
{
    Q_OBJECT
    QVector<QVector<QColor>> glassArray; // массив ячеек стакана
    uint m_rows = 20;
    uint m_columns = 11;
    bool gameOn = false;
    uint idTimer;
    QSize s;
    Figure* current;
    Figure* next;
    uint score=0;
    QPixmap pix;
    bool pause = false;
    friend class Figure;
public:
    explicit Glass(QWidget *parent = nullptr);
    void recolorGlass();
    void spaceFigure();
    void refreshGlass();
    void move_glass(int);

signals:
    void sendScore(int);
    void sendPauseSignal();
    void sendNextFigure(Figure*);

public slots:
    void gameStart();
    void pausePressed();
    void stopPressed();

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // GLASS_H
