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
#include <QFile>
#include <QDebug>
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
    } else {
        //get Contact Person's details
        cout << "Enter Contact Person name: " << flush;
        responseName = cin.readLine();

        //get Contact's telephone number
        cout << "Enter Contact Person's telephone number: " << flush;
        responseContactNum = cin.readLine();

        //get Contact Person's Email
        cout << "Enter Contact Person's Email: " << flush;
        responseEmail = cin.readLine();

        strGuest = responseName
                + "," + responseContactNum
                + "," + responseEmail;

        //cout << "\nGuest details: " << strGuest << endl;

        return strGuest;

    }// end if isGuest
}   //end getGuestDetails

QString getDates()
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QString strArrDate, strDepDate, strDates;

    //get Arrival date
    cout << "\nEnter Arrival Date (yyyy,mm,dd): " << flush;
    strArrDate = cin.readLine();

    //get Departure date
    cout << "Enter Departure Date (yyyy,mm,dd): " << flush;
    strDepDate = cin.readLine();

    strDates = strArrDate + " , " + strDepDate;

    return strDates;

}   //end getDates

//start id=singleORsharing?
bool isSharing() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    int choice;
    QString response;
   do {
        cout << SINGLE << ". Single.\n"
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
       case SINGLE: return false;
                    break;
       case SHARING: return true;
                    break;
   default:
               cout << "Default break .. " << endl;
               break;
   }   //end switch

}   //end isSharing


//START
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Create the Bookings List
    BookingList BL;
    cout << "BL created ... \n" << endl;


    QString strContactPerson;
    QString strArrDepDates;
    bool programRun = true;
    while(programRun) {
       switch(nextTask()) {
       case 1: strContactPerson = getGuestDetails(false); // bool guest; true=guest or false=contact person
            cout << "Contact Person details: " << strContactPerson << endl;
            strArrDepDates = getDates();
            cout << "Date string: " << strArrDepDates << "\n" <<  endl;
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
