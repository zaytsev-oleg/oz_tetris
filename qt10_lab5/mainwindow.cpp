#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Qt::WindowFlags wFlags = this->windowFlags() & Qt::CustomizeWindowHint;
    wFlags |= Qt::WindowCloseButtonHint;

    this->setWindowFlags(wFlags);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox qMessageBox(
        QMessageBox::Information,
        QString(tr("Information")),
        QString("dev-qt10, lab5"),
        QMessageBox::NoButton,
        this);

    // модальный вызов диалогового окна
    qMessageBox.exec();
}

void MainWindow::slot_game_over(int score)
{
    QMessageBox qMessageBox(
        QMessageBox::Information,
        QString(tr("Game over")),
        QString(tr("Your score: ")) + QString().setNum(score),
        QMessageBox::NoButton,
        this);

    // модальный вызов диалогового окна
    qMessageBox.exec();
}
