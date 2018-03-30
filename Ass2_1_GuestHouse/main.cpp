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
enum sORsh {SINGLE=1, SHARING};

QTextStream cout(stdout);
QTextStream cin(stdin);

//start id=lclmenu
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
} //end lclmenu

//start getGuestDetails
QString getGuestDetails(bool guest) {
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString responseName, responseContactNum, responseEmail;
    QString strGuest;
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

    Person *gP = new Person(responseName, responseContactNum, responseEmail);

    cout << "return from getGuestDetails() gP: " << gP->toString() << "\n" << endl;
    strGuest = gP->toString();

    delete gP;
    return strGuest;

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

        Person *cP = new Person(responseName, responseContactNum, responseEmail);

        cout << "return from getGuestDetails() cP: " << cP->toString() << "\n" << endl;
        strGuest = cP->toString();

        delete cP;

        return strGuest;
      }// end if
}   //end getGuestDetails

//start getArrDate()
QString getArrDate()
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QDate arrDate;
    QString outDate, day, month, year;

    //get Arrival date
    bool dateValid = false;
    bool ok;
    while (!dateValid) {

      cout << "Enter Arrival Day (dd): " << flush;
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
    return outDate;

}   //end getArrDate

//start gertDepDate()
QString getDepDate()
{
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
    return outDate;

}   //end getDepDate

//start id=singleORsharing?
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
}   //end isSharing


//START
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Create the Bookings List
    BookingList BL;
    cout << "BL created ... \n" << endl;

    QString strArrDepDates;
    bool programRun = true;
    while(programRun) {
       switch(nextTask()) {
       case 1: getGuestDetails(true); // bool guest; true=guest or false=contact person
               getArrDate();
               getDepDate();
            if (isSharing()) {
                cout << "Adding a SHARING booking" << endl;
                BL.addBooking();//(Person c, QDate a, QDate d, Person *g1, Person *g2);  //Add a single booking
            } else {
                cout << "Adding a SINGLE booking" << endl;
                BL.addBooking();//(Person c, QDate a, QDate d, Person *g1, Person *g2);  //Add a sharing booking
            }
           break;

       case 2: BL.listBookings();
           break;

       case 3: programRun = false;   //QUIT
           break;

       default:
          break;
       }
    }
    cout << "\nProgram ended ... BYE" << endl;

    return a.exec();
}

#endif // BOOKINGLIST_H
