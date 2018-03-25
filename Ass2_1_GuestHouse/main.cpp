/*
 Program Name: GuestHouse
 Program description: Recording bookings at a guest house.
 Version: 0.01
 Author: Ian Schafer
 Date: March 2018
*/
#include <QCoreApplication>
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDate>
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
enum Selections {READ=1, ADD, FIND, REMOVE, SAVE, LIST, QUIT};
//enum Types {BOOK, REFERENCEBOOK, TEXTBOOK, DVD, FILM, DATADVD};
//const QStringList TYPES = (QStringList() << "BOOK" << "REFERENCEBOOK"
   //<< "TEXTBOOK" << "DVD" << "FILM" << "DATADVD");
//bool saved(false);
//end
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

   return static_cast<Selections>(choice);
}

//START
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    return a.exec();
}
