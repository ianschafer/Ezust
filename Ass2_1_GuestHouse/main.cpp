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
#include <QTextStream>
#include <QDebug>
#include "bookinglist.h"

//using namespace std;

/*TO DO:
 1. Are there any rooms available (roomsAvailable) on QDate?
 * Returns number of rooms available on that QDate.
 * Goes thro the entire list of bookings and counts how many include QDate.
 * Subtract count from total number of rooms, remaining are available.

 2. Add a booking (addBooking).
*/

QTextStream cout(stdout);
QTextStream cin(stdin);
enum Selections {Availability=1, AddBooking, QUIT};
bool saved(false);

//start id=lclmenu
Selections nextTask() {
   int choice;
   QString response;
   do {
      cout << 1 << ". Check rooms availability.\n"
           << 2 << ". Add a booking.\n"
           << 3 << ". QUIT.\n"
           << "Your choice: " << flush;
     response = cin.readLine();
     choice = response.toInt();

     if (choice !=1 && choice != 2 && choice!=3){
         cout << "Incorrect selection. Try again ...\n" << endl;
     }

   } while(choice !=1 && choice != 2 && choice!=3);

   return static_cast<Selections>(choice);
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
       case 1: BL.roomsAvailable();//BL.roomsAvailable(QDate d)   //Check rooms availability
           break;

       case 2: BL.addBooking();/*BL.addBooking(Booking*& booking)*/  //Add a booking
           //cout << Booking.toString() << endl;
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
