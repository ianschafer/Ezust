#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H
#include "bookinglist.h"

const double Booking::SINGLE_PPPN = 490.00;
const double  Booking::SHARING_PPPN = 390.00;

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
    QTextStream cout(stdout);
    cout << "\nRunning function BookingList::roomsAvailable ..\n" << endl;
    int numRoomsBooked = 2;
    //prompt for date
    //iterator for number of rooms
    //count bool Booked
    //subtract from total rooms
    //return

    return NO_OF_ROOMS - numRoomsBooked;
}



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
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    cout << "\nBooking in progress ..\n" << endl;

//    cout << "Guest details " << getGuestDetails() << endl;
    QString strContactPerson(getGuestDetails());
    cout << "\nContact Person details: " << strContactPerson << endl;

    //Get Arrival and DepartureDates
    QString strArrDate, strDepDate, strDates;

    //get Arrival date
    cout << "\nEnter Arrival Date (yyyy,mm,dd): " << flush;
    strArrDate = cin.readLine();

    //get Departure date
    cout << "Enter Departure Date (yyyy,mm,dd): " << flush;
    strDepDate = cin.readLine();

    strDates = strArrDate + " " + strDepDate;

    cout << "\nDate string " << strDates << endl;

    //Confirm there is a vacancy

    //check for vacancy
    //if vacancy, continue to book
    //else break;

    //Check for vacancy
    if (true){
        cout << "\nWe have a suitable vacancy, continue booking ..\n" << endl;
    } else {
        cout << "\nNO VACANCY ... exiting to MENU ..\n" << endl;
        return;
    }

    //Single or Sharing
    bool Sharing = false;

    //get Sharing response; Sharing?
    int choice;
    QString response;
    do {
        cout << "\nIs it a Sharing booking? Y/N: " << flush;

        response = cin.readLine();
        choice = response.toInt();

        } while(choice !=1 && choice !=2); //end while

    switch (choice){
    case 1 : Sharing = true;
            cout << "Sharing: " << Sharing << endl;
            break;
    case 2 : Sharing = false;
            cout << "Sharing: " << Sharing << endl;
            break;
    default:
        cout << "Incorrect entry, try again Y/N: " << flush;
        break;
     }  //end switch

    //strSharing = cin.readLine();

    cout << "\nbool Sharing status: " << Sharing << endl;

//    QString singleGuest1(getGuestDetails());
//    bool Sharing = false;
//    if (Sharing){

//    }
//    Person p("IAS", "0833794795", "ianschafer@gmail.com");
//    Booking b(p*, adate, ddate);
    //cout << "ArrivalDate: " << b.m_ArrivalDate;

    cout
    << "//   is it a Sharing booking.\n"
    << "/*if isSharing then\n"
    << "instantiate class Single; get name\n"
    << "else\n"
    << "instantiate class Sharing; get names\n"
    << "*/\n"
    << "//now addBooking in QList\n"
    << "//set bool booked for each day of stay except the departure day\n" << endl;
}   // end addBooking

void BookingList::listBookings()
{
    QTextStream cout(stdout);
    cout << "\nList all bookings ..\n" << endl;
}// end listBookings

void BookingList::deleteAll()
{
    //Delete all dynamic pointers created on the Heap.
}

//start getGuestDetails
QString BookingList::getGuestDetails() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString responseName, responseContactNum, responseEmail;
    QString strGuest;

    //get Guest's details
    cout << "Enter Guest name: " << flush;
    responseName = cin.readLine();

    //get Guest's contact number
    cout << "Enter Guest telephone number: " << flush;
    responseContactNum = cin.readLine();

    //get Guest's Email
    cout << "Enter Guest's Email: " << flush;
    responseEmail = cin.readLine();

    strGuest = responseName
            + "," + responseContactNum
            + "," + responseEmail;

    //cout << "\nGuest details: " << strGuest << endl;

    return strGuest;
}   //end getGuestDetails
//end BookingList

//start class Booking implementaions
Booking::Booking(class Person c, QDate a, QDate d)
{

}

QTextStream& operator<<(QTextStream &s, const Booking &b)
{
//    s << b.m_ArrivalDate << "/n" << b.m_DepartureDate << endl;
    s << "HELLO WORLD" << endl;
    return s;
}

Booking::~Booking()
{
    //cout << "Default destructor for BookingList BL" << endl;
}

double Booking::rate()
{

}

QString Booking::toString(QString sep) const
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

// end Booking

//start class Person implementations
//Person::Person(QString *n, QString *c, QString *e)
//{

//}

QString Person::toString(QString sep) const
{
//    return QString("%1%2%3%4%5%6%7").arg(Person::toString(sep))
//                .arg(sep).arg(m_Name).arg(sep).arg(m_ContactNo)
//                .arg(sep).arg(m_Email);
}
//end Person

//start class Single implementations
//Single::Single(class Person* c, QDate a, QDate d, class Person* g)
//{

//}

//QString Single::toString(QString sep) const
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

//QString Sharing::toString(QString sep) const
//{

//}

//double Sharing::rate()
//{

//}


//end Sharing

#endif // BOOKINGLIST_H
