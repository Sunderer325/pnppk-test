#include "application.h"
//#include "tests/tests.h"

#include <QApplication>
//#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Application w;
    w.show();
    return a.exec();
}
