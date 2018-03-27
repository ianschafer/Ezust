#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H

#include "bookinglist.h"

//Start class BookingList implementations
BookingList::BookingList()
{
    QTextStream cout(stdout);
    cout << "Default constructor for BookingList BL" << endl;
}

BookingList::~BookingList()
{
    QTextStream cout(stdout);
    cout << "Destructor for BookingList BL" << endl;
}

//int BookingList::roomsAvailable(QDate d)
int BookingList::roomsAvailable()
{
    QTextStream cout(stdout);
    cout << "\nRooms available = 10\n" << endl;
}

//{

//    /* Take the date, check the entire BookingList and count the number of rooms available on that date.
//     * Count the number of booking that include that date, subtract this count from
//     * the total number of rooms, remainder being total rooms available on that date.
//     */

//}

bool BookingList::vacancy(QDate a, QDate d)
{
    QTextStream cout(stdout);
    cout << "Running function BookingList::vacancy .." << endl;
}
//{
//    //Check if entered date is valid; eg 32/12/2011 is not valid.

//    /*If arrival date precedes the departure date.

//        then,   Check that at least one room is available on each of the dates from
//                arrival to the day before dparture date by
//                calling roomsAvailable for each of the dates.
//    */

//}

void BookingList::addBooking()
//void BookingList::addBooking(Booking *&booking)
{
    QTextStream cout(stdout);
    cout << "\nBooking added.\n" << endl;
}

//BookingList::addBooking(Person c, QDate a, QDate d, Person g1, Person g2)
//{
//    /*Add a booking (addBooking).
//     * Takes contact person, arrival date, departure date and pointers to one or two (Single/Sharing)
//     * already constructed persons as parameters.
//     * Checks for vacancy (vacancy) over period.
//     * If vacancy, then constructs instance of Single or Sharing as appropriate and
//     * adds pointer to this booking to the BookingList.
//     * ToString can use this pointer to output the details.
//     */
//}

void BookingList::deleteAll()
{
    //Delete all dynamic pointers created on the Heap.
}

//end BookingList

//start class Booking implementaions
Booking::~Booking()
{
    //cout << "Default destructor for BookingList BL" << endl;
}

double Booking::rate()
{

}

QString Booking::toString() const
{
    //cout << "Arrival date, Arrival date, Departure date " << endl;

//    return QString("%1 %2 %3")
//            .arg(Booking::m_ArrivalDate)
//            .arg(Booking::m_ArrivalDate)
//            .arg(Booking::m_DepartureDate);
}

bool Booking::booked(QDate d)
{

}

//Booking::Booking(class Person c, QDate a, QDate d)
//{

//}
// end Booking

//start class Person implementations
//Person::Person(QString *n, QString *c, QString *e)
//{

//}

//QString Person::toString() const
//{

//}
//end Person

//start class Single implementations
//Single::Single(class Person* c, QDate a, QDate d, class Person* g)
//{

//}

//QString Single::toString() const
//{

//}

//double Single::rate()
//{

//}

//end Single

//start class Sharing implementations
//Sharing::Sharing(class Person* c, QDate a, QDate d, class Person* g1, class Person* g2)
//{

//}

//QString Sharing::toString() const
//{

//}

//double Sharing::rate()
//{

//}


//end Sharing

#endif // BOOKINGLIST_H
