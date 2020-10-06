#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDebug>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator tr;
    tr.load(":/translations/qt10_lab5_" + QLocale::system().name() + ".qm");
    a.installTranslator(&tr);

    // Переводчик текста в диалоговых окнах
    QTranslator tr2;
    tr2.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&tr2);

    MainWindow w;
    w.show();

    return a.exec();
}
