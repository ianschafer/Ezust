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

QTextStream cout(stdout);
QTextStream cin(stdin);
bool saved(false);

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
