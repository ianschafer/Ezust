#include "bookinglist.h"

enum sORsh {SINGLE=1, SHARING};

const double Booking::SINGLE_PPPN = 490.00;
const double  Booking::SHARING_PPPN = 390.00;

//start GENERAL functions
QStringList getGuestDetails(bool guest) {
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString responseName, responseContactNum, responseEmail;
    bool isGuest = guest;

    if (isGuest) {
    //get Guest's details
    cout << "\nEnter Guest name: " << flush;
    responseName = cin.readLine();

    //get Guest's contact number
    cout << "Enter Guest Tel/Mobile number: " << flush;
    responseContactNum = cin.readLine();

    //get Guest's Email
    cout << "Enter Guest Email: " << flush;
    responseEmail = cin.readLine();

    QStringList qslgP;
    qslgP << responseName << responseContactNum << responseEmail;

//    QString str_qslgP = qslgP.join(", ");
//    cout << "qslgP joined.. " << str_qslgP << "\n" << endl;

    return qslgP;
    } else {
        //get Contact Person details
        cout << "\nEnter Contact Person name: " << flush;
        responseName = cin.readLine();

        //get Contact telephone number
        cout << "Enter Contact Person Tel/Mobile number: " << flush;
        responseContactNum = cin.readLine();

        //get Contact Person's Email
        cout << "Enter Contact Person's Email: " << flush;
        responseEmail = cin.readLine();

        QStringList qslcP;
        qslcP << responseName << responseContactNum << responseEmail;

//        QString str_qslcP = qslcP.join(", ");
//        cout << "qslgP joined.. " << str_qslcP << "\n" << endl;

        return qslcP;
      }// end if
}
bool isSharing() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    bool    inBool;
    int     choice;
    QString response;
   do {
        cout << "Type of booking?\n"
             << SINGLE << ". Single.\n"
             << SHARING << ". Sharing.\n"
             << "Enter selection (1or2): " << flush;

        response = cin.readLine();
        choice = response.toInt();

        if (choice < SINGLE or choice > SHARING){
            cout << "Incorrect selection. Try again ...\n" << endl;
        }

   } while(choice < SINGLE or choice > SHARING);

   //return static_cast<sORsh>(choice);

   switch (static_cast<sORsh>(choice)){
       case SINGLE: inBool=false;
                    break;
       case SHARING: inBool=true;
                    break;
   default:
               cout << "Default break .. " << endl;
               break;
   }   //end switch

   return inBool;
}
//  end GENERAL

//Start BookingList class implementations
BookingList::BookingList(){}
BookingList::~BookingList(){}
int BookingList::roomsAvailable(){

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
bool BookingList::vacancy(QDate a, QDate d){

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
Booking BookingList::addBooking(Person c, QDate a, QDate d, Person *g1, Person *g2 ){

    QTextStream cout(stdout);

    QStringList qslPerson;
    Person *contactPerson;
    Person *g1 = new Person;
    Person *g2 = new Person;
    QDate arrDate, depDate;

    bool dateValidity = false;
    cout << "\naddBooking initiated ..\n" << endl;
    //booking = new Booking(c, a, d);

    //TEST: Confirm Arrival date before Departure date.
    if (arrDate.daysTo(depDate)>0){
        dateValidity = true;
        cout << "Period of stay: " << arrDate.daysTo(depDate) << " days\n" << endl;
    }
    else {  //ERROR: arrival date is before the departure date.
        cout << "\nError; Arrival date before Daparture date!\n"
             << "Review the dates then restart the booking."
             << endl;
    }

    //Confirm whether there is a vacancy
    if (BookingList::vacancy(a, d)){
        cout << "\nWe have a suitable vacancy, continue booking .." << endl;
    }   else    {
        cout << "\nNO ROOMS AVAILABLE ... \n" << endl;
    }

    //Single or Sharing booking?
    if (isSharing()) {  //Create two guests
        cout << "Adding a SHARING booking" << endl;
        qslPerson = getGuestDetails(true); // bool guest; true=guest or false=contact person
        g1 = new Person(qslPerson);
        cout << "g1 toString.. " << g1->toString() << "\n" << endl;
        qslPerson = getGuestDetails(true); // bool guest; true=guest or false=contact person
        g2 = new Person(qslPerson);
        cout << "g2 toString.. " << g2->toString() << "\n" << endl;

    } else {    //Create the single guest
        cout << "Adding a SINGLE booking" << endl;
        qslPerson = getGuestDetails(true); // bool guest; true=guest or false=contact person
        g1 = new Person(qslPerson);
        cout << "g1 toString.. " << g1->toString() << "\n" << endl;
    } //end if

    cout
    << "//now addBooking in QList\n"
    << "//set bool booked for each day of stay except the departure day\n"
    << "//repeat booking details to confirm. toString\n" << endl;
}
void BookingList::listBookings(){

    QTextStream cout(stdout);
    cout << "\nList all bookings ..\n" << endl;
}
void BookingList::deleteAll(){

    //Delete all dynamic pointers created on the Heap.
}
Booking::Booking(Person c, QDate a, QDate d) : m_Contact(&c), m_ArrivalDate(a), m_DepartureDate(d){

}
Booking::Booking(const Booking &){

}
Booking::Booking(QStringList& qslBooking){

}
QTextStream& operator<<(QTextStream &s, const Booking &b){

//    s << b.m_ArrivalDate << "/n" << b.m_DepartureDate << endl;
    s << "HELLO WORLD" << endl;
    return s;
}
Booking::~Booking(){

    //cout << "Default destructor for BookingList BL" << endl;
}
double Booking::rate(){

}
QString Booking::toString(QString sep) const {

    //cout << "Arrival date, Arrival date, Departure date " << endl;
    //return  QString("%1%2%3%4%5").arg(m_Contact).arg(sep).arg(m_ArrivalDate).arg(sep).arg(m_DepartureDate);

}
bool Booking::booked(QDate d){

}
// end Booking

//start Person class implementations
Person::Person() {}
Person::Person(QString n, QString c, QString e) : m_Name(n), m_ContactNo(c), m_Email(e) {}
Person::Person(QStringList &qsL) : m_Name(qsL.takeFirst()), m_ContactNo(qsL.takeFirst()), m_Email(qsL.takeFirst()){}
QString Person::toString(QString sep) const {

    return  QString("%1%2%3%4%5").arg(m_Name).arg(sep).arg(m_ContactNo).arg(sep).arg(m_Email);
}
//  end Person

//start Single class implementations
Single::Single(Person c, QDate a, QDate d, class Person g){

}
QString Single::toString(QString sep) const {

}
double Single::rate() {

}
//  end Single

//start Sharing class implementations
Sharing::Sharing(Person c, QDate a, QDate d, class Person g1, class Person g2){

}
QString Sharing::toString(QString sep) const {

}
double Sharing::rate() {

}
//end Sharing
