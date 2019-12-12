/********************************************************************************
** Form generated from reading UI file 'tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_TETRIS
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *StartButton;
    QPushButton *PauseButton;
    QPushButton *StopButton;
    QPushButton *ExitButton;
    QSpacerItem *verticalSpacer;
    QLabel *labelScore;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_2;
    Glass *widgetGlass;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelNextFigure;
    NextFigure *frameNextFigure;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TETRIS)
    {
        if (TETRIS->objectName().isEmpty())
            TETRIS->setObjectName(QString::fromUtf8("TETRIS"));
        TETRIS->resize(594, 477);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyImages/Images/Tetris.png"), QSize(), QIcon::Normal, QIcon::Off);
        TETRIS->setWindowIcon(icon);
        centralWidget = new QWidget(TETRIS);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        StartButton = new QPushButton(centralWidget);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartButton->sizePolicy().hasHeightForWidth());
        StartButton->setSizePolicy(sizePolicy);
        StartButton->setMinimumSize(QSize(0, 30));
        StartButton->setMaximumSize(QSize(160, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MyImages/Images/ios-8-Game-Center-icon_43822.ico"), QSize(), QIcon::Normal, QIcon::Off);
        StartButton->setIcon(icon1);

        verticalLayout->addWidget(StartButton);

        PauseButton = new QPushButton(centralWidget);
        PauseButton->setObjectName(QString::fromUtf8("PauseButton"));
        PauseButton->setMinimumSize(QSize(0, 30));
        PauseButton->setMaximumSize(QSize(160, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MyImages/Images/PauseDisabled_26933.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PauseButton->setIcon(icon2);

        verticalLayout->addWidget(PauseButton);

        StopButton = new QPushButton(centralWidget);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setMinimumSize(QSize(0, 30));
        StopButton->setMaximumSize(QSize(160, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MyImages/Images/Stop_37106.ico"), QSize(), QIcon::Normal, QIcon::Off);
        StopButton->setIcon(icon3);

        verticalLayout->addWidget(StopButton);

        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setMinimumSize(QSize(0, 30));
        ExitButton->setMaximumSize(QSize(160, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/MyImages/Images/exit_closethesession_close_6317.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ExitButton->setIcon(icon4);

        verticalLayout->addWidget(ExitButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        labelScore = new QLabel(centralWidget);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));
        labelScore->setMinimumSize(QSize(0, 30));
        labelScore->setMaximumSize(QSize(160, 30));
        labelScore->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelScore);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(0, 25));
        lcdNumber->setMaximumSize(QSize(160, 25));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(lcdNumber);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 2, 2, 1);

        widgetGlass = new Glass(centralWidget);
        widgetGlass->setObjectName(QString::fromUtf8("widgetGlass"));
        widgetGlass->setMinimumSize(QSize(220, 400));

        gridLayout->addWidget(widgetGlass, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelNextFigure = new QLabel(centralWidget);
        labelNextFigure->setObjectName(QString::fromUtf8("labelNextFigure"));
        labelNextFigure->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelNextFigure);

        frameNextFigure = new NextFigure(centralWidget);
        frameNextFigure->setObjectName(QString::fromUtf8("frameNextFigure"));
        frameNextFigure->setMinimumSize(QSize(180, 60));
        frameNextFigure->setMaximumSize(QSize(180, 60));
        frameNextFigure->setFrameShape(QFrame::StyledPanel);
        frameNextFigure->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frameNextFigure);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 2, 1);

        TETRIS->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TETRIS);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 21));
        TETRIS->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TETRIS);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TETRIS->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TETRIS);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TETRIS->setStatusBar(statusBar);

        retranslateUi(TETRIS);
        QObject::connect(ExitButton, SIGNAL(clicked()), TETRIS, SLOT(close()));
        QObject::connect(StartButton, SIGNAL(clicked()), widgetGlass, SLOT(gameStart()));
        QObject::connect(widgetGlass, SIGNAL(sendScore(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(PauseButton, SIGNAL(clicked()), widgetGlass, SLOT(pausePressed()));
        QObject::connect(StopButton, SIGNAL(clicked()), widgetGlass, SLOT(stopPressed()));
        QObject::connect(widgetGlass, SIGNAL(sendPauseSignal()), TETRIS, SLOT(changePauseButton()));
        QObject::connect(widgetGlass, SIGNAL(sendNextFigure(Figure*)), frameNextFigure, SLOT(getNext(Figure*)));
        QObject::connect(StopButton, SIGNAL(clicked()), frameNextFigure, SLOT(gameStop()));

        QMetaObject::connectSlotsByName(TETRIS);
    } // setupUi

    void retranslateUi(QMainWindow *TETRIS)
    {
        TETRIS->setWindowTitle(QApplication::translate("TETRIS", "TETRIS", nullptr));
        StartButton->setText(QApplication::translate("TETRIS", "Start", nullptr));
        PauseButton->setText(QApplication::translate("TETRIS", "Pause", nullptr));
        StopButton->setText(QApplication::translate("TETRIS", "Stop", nullptr));
        ExitButton->setText(QApplication::translate("TETRIS", "Exit", nullptr));
        labelScore->setText(QApplication::translate("TETRIS", "Score", nullptr));
        labelNextFigure->setText(QApplication::translate("TETRIS", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TETRIS: public Ui_TETRIS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
