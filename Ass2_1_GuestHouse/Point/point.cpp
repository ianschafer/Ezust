#ifndef Point_H
#define Point_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include "point.h"

using namespace std;

Point::Point()    // Default Constructor
{
    x = 0.0;
    y = 0.0;
    value = 0;
}
Point::Point(double x1, double y1, int value1){
    x = x1;
    y = y1;
    value = value1;

}

ostream& operator<<(ostream& s, Point& p) //
{
        s << p.getX()
          << ", "
          << p.getY()
          << ", "
          << p.getValue();
        return s;
}



void Point::initialize(double init_x, double init_y, int init_value)
{
    x = init_x;
    y = init_y;
    value = init_value;
}

void Point::shift(Point p, int keyPress){
    Point maxSize;
    Point minSize;
    maxSize.x=80;
    maxSize.y=40;
    switch(keyPress)
    {
        case (VK_LEFT):     // increment the x coord
            p.x += 1;
            if(p.x < minSize.x) p.x = minSize.x;
            break;
        case (VK_RIGHT):   // decrement the x coord
            p.x -= 1;
            if(p.x > maxSize.x) p.x = maxSize.x;
            break;
        case (VK_UP):    // decrement the y coord
            p.y -= 1;
            if(p.y < minSize.y) p.y = minSize.y;
            break;
        case (VK_DOWN):    // increment the y coord
            p.y += 1;
            if(p.y > maxSize.y) p.y = maxSize.y;
            break;
    }
}

void Point::setValue(int value){
    value = 0;
}

int Point::getValue() const{
    return value;
}


void Point::setX(){
     x = 0.0;
}

double Point::getX() const{
    return x;
}

void Point::setY(){
    y = 0.0;
}
double Point::getY() const{
    return y;
}

void Point::displayPoint(Point p){
    cout << p;      // ERROR OCCURING HERE!!!
}

void Point::AddPointValue(Point p2){
}

bool Point::checkTime(){
}

#endif
