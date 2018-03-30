#include <QList>
#include <QString>
#include <QStringList>
#include <QDate>
#include <QTextStream>

class   Person; //forward class declaration
//start id=baseclassdef
class Booking {
friend QTextStream& operator<<(QTextStream&, const Booking &);

public:
    Booking(){}
    Booking (Person, QDate, QDate); //"class" ... could put Forward decl. here
    Booking(const Booking&);
    Booking(QStringList&);
    const Booking& operator=(const Booking&);
    virtual ~Booking();
    virtual double rate();
    virtual QString toString(QString sep="[,]") const;
    bool booked(QDate d);
    static const double SINGLE_PPPN;
    static const double  SHARING_PPPN;

private:
    Person*  m_Contact;
    QDate   m_ArrivalDate;
    QDate   m_DepartureDate;
};
//end

//start id=derivedclassdefs
class Person : public Booking {

public:
    Person();
    Person (QString, QString, QString);
    Person(const Person& person);
    Person(QStringList& bookinglist);
    virtual QString toString(QString sep=",") const;

private:
   QString m_Name;
   QString m_ContactNo;
   QString m_Email;
};

class Single : public Person {

public:
    Single(Person c, QDate a, QDate d, Person g);// : m_Guest(g) {}
    Single(const Single& single);
    Single(QStringList& bookinglist);
    QString toString(QString sep="[,]") const;
    double rate();

private:
    Person  m_Guest;
};

class Sharing : public Person {

public:
    Sharing(Person c, QDate a, QDate d, class Person g1, class Person g2);// : m_Guest1(g1), m_Guest2(g2) {}
    Sharing(const Sharing& sharing);
    Sharing(QStringList& bookinglist);
    QString toString(QString sep="[,]") const;
    double rate();

private:
   Person  m_Guest1;
   Person  m_Guest2;
};
//end

//start id=QListdef
class BookingList : public QList<Booking*> {
public:
   static const int NO_OF_ROOMS = 10;    //Set fixed number of rooms

   BookingList();
   ~BookingList();                             /* A container of pointers must have a destructor! */
   int roomsAvailable();
   bool vacancy(QDate a, QDate d);
   void addBooking();
   //Booking* addBooking(Person c, QDate a, QDate d, Person *g1, Person *g2);
   void listBookings(); //List all Bookings.
   void deleteAll(); //Call at end of client pgm to prevent mem leaks

private:
   BookingList(const BookingList&);
   BookingList& operator=(const BookingList&);
};
//end
