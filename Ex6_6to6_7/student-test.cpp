#include <QTextStream> 
#include "student.h"

static QTextStream cout(stdout); 

void finish(Student* student) {
    cout << "\nThe following "
         << student->getClassName()
         << " has applied for graduation.\n "
         << student->toString() << "\n";
}

int main() {
    Undergrad us("Frodo Baggins", 5562, "Ring Theory", 4, 1220);
    GradStudent gs("Bilbo Baggins", 3029, "History", 6, 
     GradStudent::fellowship);
    cout << "Here is the data for the two students:\n";
    cout << gs.toString() << endl;
    cout << us.toString() << endl;
    cout << "\nHere is what happens when they finish their studies:\n";
    finish(&us);
    finish(&gs);
    return 0;
}

/*

PROGRAM OUTPUT with virtual functions in base class Student.
Here is the data for the two students:
[GradStudent] name: Bilbo Baggins; Id: 3029; Year: gradual student;
Major: History  [Support: fellowship ]

[Undergrad] name: Frodo Baggins; Id: 5562; Year: senior;
Major: Ring Theory  [SAT: 1220 ]


Here is what happens when they finish their studies:

The following Undergrad has applied for graduation.
 [Undergrad] name: Frodo Baggins; Id: 5562; Year: senior;
Major: Ring Theory  [SAT: 1220 ]


The following GradStudent has applied for graduation.
 [GradStudent] name: Bilbo Baggins; Id: 3029; Year: gradual student;
Major: History  [Support: fellowship ]

*/
