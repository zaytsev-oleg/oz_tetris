/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglass.h"
#include "nextfigure.h"
#include "pausebutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionPause;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_left;
    QLabel *label_next_item;
    NextFigure *next_figure;
    QSpacerItem *verticalSpacer_3;
    MyGlass *my_glass;
    QVBoxLayout *verticalLayout_right;
    QPushButton *btn_start;
    PauseButton *btn_pause;
    QPushButton *btn_exit;
    QSpacerItem *verticalSpacer_1;
    QLabel *label_score;
    QLCDNumber *lcd_num;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(571, 419);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pics/images/Tetris.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/iconNewGame.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/iconInstructions.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_left = new QVBoxLayout();
        verticalLayout_left->setObjectName(QString::fromUtf8("verticalLayout_left"));
        label_next_item = new QLabel(centralwidget);
        label_next_item->setObjectName(QString::fromUtf8("label_next_item"));
        label_next_item->setAlignment(Qt::AlignCenter);

        verticalLayout_left->addWidget(label_next_item);

        next_figure = new NextFigure(centralwidget);
        next_figure->setObjectName(QString::fromUtf8("next_figure"));
        next_figure->setProperty("rows", QVariant(8));
        next_figure->setProperty("cols", QVariant(5));

        verticalLayout_left->addWidget(next_figure);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_left->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_left);

        my_glass = new MyGlass(centralwidget);
        my_glass->setObjectName(QString::fromUtf8("my_glass"));
        my_glass->setFocusPolicy(Qt::StrongFocus);
        my_glass->setProperty("rows", QVariant(20));
        my_glass->setProperty("cols", QVariant(15));

        horizontalLayout->addWidget(my_glass);

        verticalLayout_right = new QVBoxLayout();
        verticalLayout_right->setObjectName(QString::fromUtf8("verticalLayout_right"));
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setIcon(icon1);

        verticalLayout_right->addWidget(btn_start);

        btn_pause = new PauseButton(centralwidget);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));
        btn_pause->setEnabled(false);
        btn_pause->setIcon(icon4);

        verticalLayout_right->addWidget(btn_pause);

        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setIcon(icon3);

        verticalLayout_right->addWidget(btn_exit);

        verticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_right->addItem(verticalSpacer_1);

        label_score = new QLabel(centralwidget);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setAlignment(Qt::AlignCenter);

        verticalLayout_right->addWidget(label_score);

        lcd_num = new QLCDNumber(centralwidget);
        lcd_num->setObjectName(QString::fromUtf8("lcd_num"));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(false);
        lcd_num->setFont(font);
        lcd_num->setFrameShape(QFrame::Box);

        verticalLayout_right->addWidget(lcd_num);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_right->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_right);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 571, 21));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuGame->addAction(actionStart);
        menuGame->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionStart);
        toolBar->addAction(actionPause);
        toolBar->addAction(actionAbout);
        toolBar->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionStart, SIGNAL(triggered()), my_glass, SLOT(slot_start_game()));
        QObject::connect(btn_start, SIGNAL(clicked()), actionStart, SLOT(trigger()));
        QObject::connect(my_glass, SIGNAL(signal_next_figure(MyFigure*)), next_figure, SLOT(slot_next_figure(MyFigure*)));
        QObject::connect(my_glass, SIGNAL(signal_set_score(int)), lcd_num, SLOT(display(int)));
        QObject::connect(my_glass, SIGNAL(signal_pause_btn_enabled(bool)), btn_pause, SLOT(slot_btn_enabled(bool)));
        QObject::connect(btn_pause, SIGNAL(signal_pause_game(bool)), my_glass, SLOT(slot_pause_game(bool)));
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(btn_exit, SIGNAL(clicked()), actionExit, SLOT(trigger()));
        QObject::connect(actionPause, SIGNAL(triggered()), btn_pause, SLOT(slot_toggle_state()));
        QObject::connect(btn_pause, SIGNAL(clicked()), actionPause, SLOT(trigger()));
        QObject::connect(my_glass, SIGNAL(signal_game_over(int)), MainWindow, SLOT(slot_game_over(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lab5", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#if QT_CONFIG(tooltip)
        actionPause->setToolTip(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPause->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        label_next_item->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        btn_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btn_pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btn_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_score->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        menuGame->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
