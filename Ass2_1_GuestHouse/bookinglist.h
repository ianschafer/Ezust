#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H

#include <QList>
#include <QString>
#include <QStringList>
#include <QDate>


using namespace std;
//define Global parameters

//start id=ABSTRACTbaseclassdef
class Booking {
public:
//    Booking(){}
    Booking(Person c, QDate a, QDate d) : m_Contact(c), m_Arrivaldate(a), m_DepartureDate(d) {}
    Booking(const Booking&);
    Booking& operator=(const Booking&);
    virtual ~Booking();
    virtual double rate();
    bool booked(QDate d);
    double  SINGLE_PPPN = 489.00;
    double  SHARING_PPPN = 439.00;
    virtual QString toString() const;

private:
    Person   m_Contact;
    QDate    m_Arrivaldate;
    QDate    m_DepartureDate;
};
//end

//start id=derivedclassdefs
class Person : public Booking {
public:
    Person(QString n, QString c, QString e);
    Person(const Person&);
    virtual QString toString() const;

private:
   QString m_Name;
   QString m_ContactNo;
   QString m_Email;
};

class Single : public Person {
public:
    Single();
    Single(Person c, QDate a, QDate d, Person g);
    Single(const Single&);
    QString toString() const;
    double rate();

private:
    Person  m_Guest;
};

class Sharing : public Person {
public:
    Sharing();
    Sharing(Person c, QDate a, QDate d, Person g1, Person g2);
    Sharing(const Sharing&);
    QString toString() const;
    double rate();

private:
   Person  m_Guest1;
   Person  m_Guest2;
};
//end

//start id=QListdef
class BookingList : public QList<Booking*> {
public:
   int NO_OF_ROOMS = 3;    //Set fixed number of rooms

   BookingList() {}
   ~BookingList();                             /* A container of pointers must have a destructor! */
   int roomsAvailable(QDate d);
   bool vacancy(QDate a, QDate d);
   Booking* addBooking(Person c, QDate a, QDate d, Person g1, Person g2);
   void deleteAll(); //Call at end of client pgm to prevent mem leaks

private:
   BookingList(const BookingList&);
   BookingList& operator=(const BookingList&);
};
//end

#endif // BOOKINGLIST_H
