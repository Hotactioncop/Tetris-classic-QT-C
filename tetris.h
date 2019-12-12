#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>
#include <QTime>

namespace Ui {
class TETRIS;
}

class TETRIS : public QMainWindow
{
    Q_OBJECT

public:
    explicit TETRIS(QWidget *parent = nullptr);
    ~TETRIS();

private:
    Ui::TETRIS *ui;
public slots:
    void changePauseButton();
};

#endif // TETRIS_H
