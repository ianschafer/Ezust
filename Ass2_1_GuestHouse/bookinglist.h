#include <QList>
#include <QString>
#include <QStringList>
#include <QDate>

using namespace std;

//start id=ABSTRACTbaseclassdef
class Booking {

public:
    const Booking& operator=(const Booking&);
    virtual ~Booking();
    virtual double rate();
    virtual QString toString() const;
    bool booked(QDate d);
    static const double  SINGLE_PPPN;
    static const double  SHARING_PPPN;

private:
    Booking (class Person* c, QDate a, QDate d) : m_Contact(c), m_Arrivaldate(a), m_DepartureDate(d) {}
    Booking(const Booking&);
    Booking(QStringList& bookinglist);
    Person*   m_Contact;
    QDate    m_Arrivaldate;
    QDate    m_DepartureDate;
};
//end

//start id=derivedclassdefs
class Person : public Booking {

public:
    Person(QString n, QString c, QString e);
    Person(const Person&);
    Person(QStringList& bookinglist);
    virtual QString toString() const;

private:
   QString m_Name;
   QString m_ContactNo;
   QString m_Email;
};

class Single : public Person {
public:
    Single(class Person* c, QDate a, QDate d, class Person* g) : m_Guest(g) {}
    Single(const Single&);
    Single(QStringList& bookinglist);
    QString toString() const;
    double rate();

private:
    Person*  m_Guest;
};

class Sharing : public Person {
public:
    Sharing(class Person* c, QDate a, QDate d, class Person* g1, class Person* g2) : m_Guest1(g1), m_Guest2(g2) {}
    Sharing(const Sharing&);
    Sharing(QStringList& bookinglist);
    QString toString() const;
    double rate();

private:
   Person*  m_Guest1;
   Person*  m_Guest2;
};
//end

//start id=QListdef
class BookingList : public QList<Booking*> {
public:
   static const int NO_OF_ROOMS = 3;    //Set fixed number of rooms

//   BookingList() {}
   ~BookingList();                             /* A container of pointers must have a destructor! */
   int roomsAvailable(QDate d);
   bool vacancy(QDate a, QDate d);
   //Booking* addBooking(Person c, QDate a, QDate d, Person g1, Person g2);
   void addBooking(Booking*& booking);
   void deleteAll(); //Call at end of client pgm to prevent mem leaks

private:
   BookingList(const BookingList&);
   BookingList& operator=(const BookingList&);
};
//end
