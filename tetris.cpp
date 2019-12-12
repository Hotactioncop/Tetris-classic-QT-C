#include "tetris.h"
#include "ui_tetris.h"
#include <QPalette>
#include <QPixmap>
#include <QBrush>

TETRIS::TETRIS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TETRIS)
{
    setFixedSize(640,480);
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    ui->setupUi(this);
    QPixmap pix;
    QPalette palette;
    pix.load("Images/Background3.jpg");
    palette.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(palette);
}

TETRIS::~TETRIS()
{
    delete ui;
}

void TETRIS::changePauseButton()
{
    if(ui->PauseButton->text()=="Pause"){
        ui->PauseButton->setText("Continue");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/Start_37108.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ui->PauseButton->setIcon(icon);
    }
    else {
        ui->PauseButton->setText("Pause");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/PauseDisabled_26933.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ui->PauseButton->setIcon(icon);
    }
}
