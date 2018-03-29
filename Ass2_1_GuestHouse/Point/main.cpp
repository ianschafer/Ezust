#ifndef POINT_H
#define POINT_H
#include <QCoreApplication>
#include <iostream>
#include "point.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Point e(2,4,6);
    cout << "Point e: " << e << endl;

    return a.exec();
}
#endif
