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
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include "bookinglist.h"

using namespace std;

/*TO DO:
 1. Are there any rooms available (roomsAvailable) on QDate?
 * Returns number of rooms available on that QDate.
 * Goes thro the entire list of bookings and counts how many include QDate.
 * Subtract count from total number of rooms, remaining are available.

 2. Add a booking (addBooking).
*/

QTextStream cout(stdout);
QTextStream cin(stdin);
enum Selections {Availability=1, ADD, QUIT};
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
   } while(choice !=3);

   cout << "End Selections" << endl;
   return static_cast<Selections>(choice);
}

//START
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    nextTask();

    return a.exec();
}

#endif // BOOKINGLIST_H
