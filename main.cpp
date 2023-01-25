#include "mainwindow.h"
#include "qrcodegen.h"

#include <iostream>
#include <sstream>
#include <QApplication>

using qrcodegen::QrCode;
using qrcodegen::QrSegment;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
