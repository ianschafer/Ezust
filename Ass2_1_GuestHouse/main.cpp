/*
 Program Name: GuestHouse
 Program description: Recording bookings at a guest house.
 Version: 0.01
 Author: Ian Schafer
 Date: March 2018
*/
#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H
#include <QCoreApplication>
#include <QString>
#include <QDate>
#include "bookinglist.h"

enum mainMenu {ADD=1, ListAll, QUIT};

QTextStream cout(stdout);
QTextStream cin(stdin);

mainMenu nextTask() {
   int choice;
   QString response;
   do {
      cout << ADD << ". Add Booking.\n"
           << ListAll << ". List all Bookings.\n"
           << QUIT << ". QUIT.\n"
           << "Your choice: " << flush;
     response = cin.readLine();
     choice = response.toInt();

     if (choice < ADD or choice > QUIT){
         cout << "Incorrect selection. Try again ...\n" << endl;
     }

   } while(choice < ADD or choice > QUIT);

   return static_cast<mainMenu>(choice);
}
QStringList getContactPerson() {

    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QString responseName, responseContactNum, responseEmail;

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

    return qslcP;
}
QDate getArrDate(){

    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QDate arrDate;
    QString outDate, day, month, year;

    //get Arrival date
    bool dateValid = false;
    bool ok;
    while (!dateValid) {

      cout << "\nEnter Arrival Day (dd): " << flush;
      day = cin.readLine();
      int intDay = day.toInt(&ok);

      cout << "Month (mmd): " << flush;
      month = cin.readLine();
      int intMonth = month.toInt(&ok);

      cout << "Year (yyyy): " << flush;
      year = cin.readLine();
      int intYear = year.toInt(&ok);

      if (QDate::isValid(intYear, intMonth, intDay)){
          arrDate = QDate(intYear, intMonth, intDay);
          outDate = year + "/" + month + "/" + day;
          dateValid = true;
      } else {
          cout << "\nInvalid Arrival date. Try again..\n" << endl;
      }
   } //end while

    cout << "Arrival Date: " << outDate << endl;
    return arrDate;

}
QDate getDepDate(){

    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QDate depDate;
    QString outDate, day, month, year;

    //get Departure date
    bool dateValid = false;
    bool ok;
    while (!dateValid) {

      cout << "\nEnter Departure Day (dd): " << flush;
      day = cin.readLine();
      int intDay = day.toInt(&ok);

      cout << "Month (mmd): " << flush;
      month = cin.readLine();
      int intMonth = month.toInt(&ok);

      cout << "Year (yyyy): " << flush;
      year = cin.readLine();
      int intYear = year.toInt(&ok);

      if (QDate::isValid(intYear, intMonth, intDay)){
          depDate = QDate(intYear, intMonth, intDay);
          outDate = year + "/" + month + "/" + day;
          dateValid = true;
      } else {
          cout << "\nInvalid Departure date. Try again..\n" << endl;
      }
   } //end while

    cout << "Departure Date: " << outDate << "\n" << endl;
    return depDate;
}

//START
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Create the Bookings List
    BookingList BL;
    cout << "BL created ... \n" << endl;

    Booking *booking = new Booking;
    Booking *newBooking = new Booking;
    Person *contactPerson = new Person;
    Person  guest1;
    Person  guest2;
    QStringList qslContact; // holds Name, Conact Number and Email
    QStringList qslBooking; // holds Name, Conact Number and Email
    QDate arrivalDate;
    QDate departureDate;

    bool programRun = true;
    while(programRun) {
       switch(nextTask()) {
       case 1:
               cout << "\nAdding a Contact Person.." << endl;
               qslContact = getContactPerson(); // bool guest; true=guest or false=contact person
               contactPerson = new Person(qslContact);
               cout << "contactPerson toString.. " << contactPerson->toString() << endl;
               arrivalDate = getArrDate();
               departureDate = getDepDate();
               //qslBooking << contactPerson << arrivalDate << departureDate;
               //booking  = new Booking(contactPerson, arrivalDate, departureDate);
               cout << "booking toString.. " << booking->toString() << "\n" << endl;
               //newBooking = BookingList::addBooking(booking, guest1, guest2);
               break;

       case 2: cout << "\nList all bookings..\n" << endl;
           break;

       case 3: programRun = false;   //QUIT
           break;

       default:
          break;
       }
    }
    cout << "\nProgram ended ... BYE" << endl;

    delete booking;
    delete contactPerson;

    return a.exec();
}
//END
#endif // BOOKINGLIST_H
