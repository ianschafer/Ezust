/* Program description: UNISA Assignment 1.2 Implement classes for Product and Vendor as per UML diagram.
 * Program name: Ass1_2_Console_Product
 * Version: 1.00
 * Date: 03rd February 2018
 * Author: Ian Schafer
 * Student Number: 07110871
 *
 * Comments:
 * */

#include <QCoreApplication>
#include <QTextStream>
#include <QString>

QTextStream cout(stdout);
QTextStream cin(stdin);

using namespace std;

// Class definition Product
class Product {
    public:
    Product(QString, double);
    ~Product(){}
    void setSupplier(QString name, QString email, bool isManufacturer); //Use to enter Supplier details (Vendor details).
    QString getManufacturerName(); // Returns m_Supplier if exist, else unknown string.
    QString toString(bool);

    private:
    QString m_Name;
    double m_Price;
    QString m_Supplier;

};

// Class definition Vendor
class Vendor {

    friend class Product;

public:
    Vendor();
    ~Vendor(){}
    void setDetails(QString, QString, bool); //Used by Product class to initialise new Vendor.
    bool isManufacturer(); //Return bool true/false.
    QString getName(); //Return Vendor name;
    QString toString(); // Return all data mems; m_Name, m_Email and isManufacturer.

    private:
    QString m_Name;
    QString m_Email;
    bool m_isManufacturer;
};

Product::Product(QString name, double price){ //Initialise new Product.

    this->m_Name = name;
    this->m_Price = price;

} //End Product

// Sets Supplier details (Vendor deets).
    void Product::setSupplier(QString name, QString email, bool isManufacturer){ //Use to enter Supplier details (Vendor name).

//   Vendor.setDetails(name, email, isManufacturer);
    cout << "End setSupplier\n" << endl;
}

// Returns m_Supplier if exist, else unknown string.
QString Product::getManufacturerName(){

//        QString inString = "UNKNOWN";
//        if (V.m_isManufacturer){
//            inString = V.m_Name;
//        }

//        return inString;
        cout << "End getManufacturerName\n" << endl;
}

// QString toString() const; // Returns Product data; driven by true/false.
QString Product::toString(bool supplierDetails) {
    QString outStr;
    if (supplierDetails)
      outStr = m_Name + m_Price; //Return both Product & Suppier details
    else
      outStr = "m_Name"; //Return only Product details

    return outStr;
}

    //Used by Product class to initialise new Vendor.
   void Vendor::setDetails(QString name, QString email, bool isManufacturer){

    m_Name = name;
    m_Email = email;
    m_isManufacturer = isManufacturer;

    cout << "end setSupplier\n" << endl;

} //End setDetails

// bool isManufacturer(); //Return bool isManufacturer true/false.
//bool Vendor::isManufacturer(){
//    return Vendor::m_isManufacturer;
//}

// QString getName(); //Return m_Name;
//QString Vendor::getName(){
//    return Vendor::m_Name;
//}

// QString toString() const; // Return all data mems; m_Name, m_Email and isManufacturer.
//QString Vendor::toString() const{
//    QString tempString("unititialised");
//    return tempString;
//    //return string; all data members of Vendor
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Product P("WD40", 2.5); //Create instance of Product
    cout << "Product instance created\n" << endl;

    bool boolExit(false);
    while (!boolExit) {
    // Simple Menu to select action
    int menuNum(6);
    cout << "MENU" << endl;
    cout << "1 set Supplier details" << endl;
    cout << "2 Request manufacturer" << endl;
    cout << "3 Request product details" << endl;
    cout << "4 Request supplier name" << endl;
    cout << "5 Request supplier details" << endl;
    cout << "6 EXIT PROGRAM\n" << endl;
    cout << "Enter menu number to proceed: " << flush;

    cin >> menuNum;
    switch (menuNum) {
    case 1: // Set Supplier details
        system("cls");
        P.setSupplier("ABC", "ABC@gmail.com", false);
        cout << "End setSupplier details" << endl;
        break;
    case 2: //Request manufacturer name
        system("cls");
        //P.getManufacturerName();
        cout << "End request manufacturer name\n" << endl;
        break;
    case 3: //Request product details
        system("cls");
        cout << P.toString(false) << "\n" << endl;
        break;
    case 4: //Request Supplier name
        system("cls");
        //V.getName();
        cout << "End request Supplier name\n" << endl;
        break;
    case 5: //Request Supplier details
        system("cls");
//        if (true){
//            V.toString();
//        } else {
//            cout << "UNKNOWN" << endl;
//        }
        cout << "End Request Supplier details\n" << endl;
        break;
    case 6: //Exit Program
        cout << "\nYou selected 6; Exit Program" << endl;
        cout << "Exiting to console ... END program\n" << endl;
        boolExit = true;
        break;
    default:
        break;

    }//End switch

    //Continue or Exit?
        QString Continue;
        if (!boolExit){
            cout << "Continue? y/n: " << flush;
            cin >> Continue;
            if (Continue == "n"){
                cout << "Exiting to console ... END program\n" << endl;
                boolExit = true;
            } else if (Continue == "y") {
                system("cls");
                cout << endl;
            } else {
                cout << "Bad char ... END program\n" << endl;
                boolExit = true;
            }
    }
  }//End while

    return a.exec();

} // END main
