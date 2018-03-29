#include <iostream>

using namespace std;     // For string usage

class Point
{
    friend ostream& operator<<(ostream& s, Point&);

public:
    Point();                                    // Default Constructor
    Point(double, double, int); // Three argument constructor
    void initialize(double, double, int);
    void shift(Point p, int keyPress);                      // Shift the first point

    void setValue(int value);
    int getValue() const;
    void setX();
    double getX() const;
    void setY();
    double getY() const;

    void AddPointValue(Point p2);             /*This function add the TWO points
    successfully reach on second true point co-ordinates*/

    void displayPoint(Point p);                     //This will use to display value
    bool checkCoordinates();
     bool checkTime();                        // Check time remaining
private:
     double x;
    double y;
    int value;

};
