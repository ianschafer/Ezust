#include <iostream>
using namespace std;

//Class definition
struct Fraction {
    int numer, denom;
    string description;

    //void printFraction(Fraction f);
    void printFraction(Fraction f);

};

int main() {  
    Fraction f1 = {4, 5, "four fifths"};
    Fraction f2 = {2, 3, "two thirds"};
    
    f1.numer = f1.numer + 2;            /* Client code can change individual data members. */
    f1.description = "six over five";
    f1.printFraction(f1);
    f2.printFraction(f2);
    return 0;
}

//void printFraction(Fraction f);
void Fraction::printFraction(Fraction f) {        /* Passing a struct by value
    could be expensive if it has large components. */
    cout << f.numer << "/" << f.denom << endl;
    cout << "  =? " << f.description << endl;
}

/*OUT
  6/5
  =? six over five
  2/3  
  =? two thirds
*/

