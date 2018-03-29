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

/*TO DO:
 1. Are there any rooms available (roomsAvailable) on QDate?
 * Returns number of rooms available on that QDate.
 * Goes thro the entire list of bookings and counts how many include QDate.
 * Subtract count from total number of rooms, remaining are available.

 2. Add a booking (addBooking).
*/

QTextStream cout(stdout);
QTextStream cin(stdin);
bool saved(false);

//start id=lclmenu
int nextTask() {
   int choice;
   bool isSharing = false;
   bool bookingInProgress = true;
   QString response;
   do {
      cout << 1 << ". Add Booking.\n"
           << 2 << ". List all Bookings.\n"
           << 3 << ". QUIT.\n"
           << "Your choice: " << flush;
     response = cin.readLine();
     choice = response.toInt();

     if (choice !=1 && choice != 2 && choice!=3){
         cout << "Incorrect selection. Try again ...\n" << endl;
     }

   } while(choice !=1 && choice != 2 && choice!=3);

   return choice;
}

//START
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Create the Bookings List
    BookingList BL;
    cout << "BL created ... \n" << endl;


    bool programRun = true;
    while(programRun) {
       switch(nextTask()) {
       case 1: BL.addBooking();//(Person c, QDate a, QDate d, Person *g1, Person *g2);  //Add a booking
           cout << "//repeat booking details to confirm. toString\n" << endl;
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
