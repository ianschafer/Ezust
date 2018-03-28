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

//start roomsAvailable
/* Take the date, check the entire BookingList and count the number of rooms available on that date.
* Count the number of booking that include that date, subtract this count from
* the total number of rooms, remainder being total rooms available on that date.
*/

//int BookingList::roomsAvailable(QDate d)
int BookingList::roomsAvailable()
{
    int numRoomsBooked = 2;
    //prompt for date
    //count no, of rooms booked on that date
    //subtract from total rooms
    //return

    return NO_OF_ROOMS - numRoomsBooked;
}

//{


//}

bool BookingList::vacancy(QDate a, QDate d)
{
    QTextStream cout(stdout);
    cout << "\nRunning function BookingList::vacancy .." << endl;
    cout << "Dates received: \n" << endl;
    //cout << QString("\nDate received: %1").arg(QDate::toString(this->getBookingDate() &YYYY.mm.dd)
    //cout << QString("\nDate received: %1").arg(QDate::toString(this->getBookingDate().toString("yyyy.MM.dd"));


    //cout << "Input date a: " << inDate_a << endl;
    //cout << "Input date d: " << d << endl;

    cout << "\nTests:" << endl;
    cout << "QDate::isValid(2018,16,35) is " << QDate::isValid(2018,16,35) << endl;
    cout << "QDate::isValid(2018,04,07) is " << QDate::isValid(2018,04,07) << endl;
    cout << "QDate::isValid(2018,06,10) is " << QDate::isValid(2018,06,10) << endl;

//    if (true) {
//             cout << "Dates valid .." << endl;
//            return true;
//    }
//    else {
//             cout << "Invalid dates .." << endl;
//            return false;
//    }


//prompt for the two dates

//Check dates validity
//1. if entered dates are valid; eg 32/12/2011 is not valid.
//2. check that arrival date precedes the departure date.

//Confirm room availability
//Check that at least one room is available on each of the dates from
//arrival to the day before dparture date by
//call function roomsAvailable for each of the dates.

}
//end vacancy

//start addBooking
/*Add a booking (addBooking).
* Checks for vacancy (vacancy) over period.
* Takes contact person, arrival date, departure date and pointers to one or two (Single/Sharing)
* already constructed persons as parameters.
* If vacancy, then constructs instance of Single or Sharing as appropriate and
* adds pointer to this booking to the BookingList.
* ToString can use this pointer to output the details.
*/

void BookingList::addBooking() //(Person c, QDate a, QDate d, Person g1, Person g2)
{
    //Confirm there is a vacancy
    QDate a(2018,04,07);
    QDate d(2018,06,10);


//    if (BookingList::vacancy(a, d)) {
//            QTextStream cout(stdout);
//            cout << "\nBooking added.\n" << endl;
//    }
//    else {
//            QTextStream cout(stdout);
//            cout << "\nNO VACANCY\n" << endl;
//            exit;
//    }

            //check for vacancy
    //if vacancy, continue to book
    //else break;

//instantiate contact person
//Prompt for contact person's details
//prompt sharing?

//If Single
    //instantiate person
    //prompt person details; add single booking
//else
    //instantiate person
    //instantiate person
    //prompt two persons details; add Sharing booking

}
// end addBooking

void BookingList::deleteAll()
{
    //Delete all dynamic pointers created on the Heap.
}

//end BookingList

//start class Booking implementaions
//QTextStream& operator<<(QTextStream& s, Booking &b)
//{
//    s << b.m_ArrivalDate << "/n" << b.m_DepartureDate << endl;
//    return s;
//}

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
