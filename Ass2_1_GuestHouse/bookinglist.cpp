#include "bookinglist.h"

using namespace std;

BookingList::BookingList()
{

}

int BookingList::roomsAvailable(QDate d)
{
    /* Take the date, check the entire BookingList and count the number of rooms available on that date.
     * Count the number of booking that include that date, subtract this count from
     * the total number of rooms, remainder being total rooms available on that date.
     */
}

bool BookingList::vacancy(QDate a, QDate d)
{
    //Check if entered date is valid; eg 32/12/2011 is not valid.

    /*If arrival date precedes the departure date.

        then,   Check that at least one room is available on each of the dates from
                arrival to the day before dparture date by
                calling roomsAvailable for each of the dates.
    */

}

Booking BookingList::addBooking(Person c, QDate a, QDate d, Person g1, Person g2)
{
    /*Add a booking (addBooking).
     * Takes contact person, arrival date, departure date and pointers to one or two (Single/Sharing)
     * already constructed persons as parameters.
     * Checks for vacancy (vacancy) over period.
     * If vacancy, then constructs instance of Single or Sharing as appropriate and
     * adds pointer to this booking to the BookingList.
     * ToString can use this pointer to output the details.
     */
}

void BookingList::deleteAll()
{
    //Delete all dynamic pointers created on the Heap.
}

//end BookingList

//start class Booking implementaions

Booking::Booking()
{

}

Booking::Booking(Person c, QDate a, QDate d)
{

}

double Booking::rate()
{

}

bool Booking::booked(QDate d)
{

}

QString Booking::toString()
{

}
// end Booking

//start class Person implementations

Person::Person(QString n, QString c, QString e)
{

}

QString Person::toString()
{

}
//end Person

//start class Single implementations

Single::Single()
{

}

Single::Single(Person c, QDate a, QDate d, Person g)
{

}

QString Single::toString()
{

}

double Single::rate()
{

}

//end Single

//start class Sharing implementations

Sharing::Sharing()
{

}

Sharing::Sharing(Person c, QDate a, QDate d, Person g1, Person g2)
{

}

QString Sharing::toString()
{

}

double Sharing::rate()
{

}


//end Sharing
