
//PROGRAM DESCRIPTION: Use rules below to write a GUI program to generate a username and
//an initial password given the full name of the user.
//Author: Ian Schafer
//Student Number: 7110871
//Date: 26.02.2018
//Version: 1.00

//Rules: INPUT to QInputDialog
//  user will input single string, each name (word) separated by spaces.
//  Assume >=2 words separated by spaces
//  No input validation required.
//  First name is first word, Surname is last word.
//
//Rules: Required OUTPUTS to QMessageBox
//  1. Username no spaces
//      - 5x lowercase letters; First 4x char from firstName + first 1x char from lastName
//      - if firstName has <4, take more from lastName to make up 5 chars.
//      - if qty chars in (firstName + lastName) < 5, append zeros to make up 5 chars.
//  2. Initial pw no spaces
//      - Combine 5x chars randomly selected from userFullName.
//      - output pw in lowercase.

#include <QtWidgets>
#include <QString>
#include <cstdlib>
#include <ctime>

int main (int argc, char* argv[]) {                 /* Start of function "main" which returns int. */
    QApplication app(argc, argv);                   /* Start of every Qt GUI application. */
    QTextStream cout(stdout);                       /* Create a QTextStream to standard output. */
    QTextStream cin(stdin);                       /* Create a QTextStream to standard output. */

    // Declarations of variables
    unsigned long int seed;
    QString UserFullName; //User Full Name used at output only
    QString tempFullName; //working ver of userFullName
    QString firstName;
    QString lastName;
    QString userName; //Username for output
    QString initpw; // Initial password for output

    int answer = 0; /* Defined outside do loop; used in the condition outside the do block. */

    //get pseudo-random seed for rand() function.
    seed = time(NULL);
    srand(seed);

    do {
        // local variables to the loop:
        bool ok;

        //get full name from user ("raw" input string incl spaces).
        UserFullName = QInputDialog::getText(0, "UNPW Generator",
                                         "Enter full names:", QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
        tempFullName = UserFullName; //write to working copy

       if (ok && !tempFullName.isEmpty()){
//MAKE USERNAME
                //Get first and last names from the raw user input
                  int numOfSpaces, lengthOfFullName, lengthOfName;
                  int charsNeeded = 5; //For username

                  lengthOfFullName = tempFullName.length();
                  numOfSpaces = tempFullName.count(" ");

                  int locOfSpaces[numOfSpaces];
                  int locLastSpace;
                  int j = 0;
                  while (j <= numOfSpaces-1) {
                    for(int i = 0; i <= lengthOfFullName-1; ++i){
                      if (tempFullName[i] == " ") {
                        locOfSpaces[j] = i;
                        j += 1;
                        locLastSpace = i;
                      }
                    }
                  }

                  //Get first name.
                  firstName = tempFullName.left(locOfSpaces[0]);

                  //Get last name.
                  lastName = tempFullName.remove(0, locLastSpace+1);

                  // Making of username begins.
                  lengthOfName = firstName.length();
                  if (lengthOfName >= 4) {
                      userName = firstName.left(4);
                      charsNeeded -= 4;
                   }
                   else { //lengthOfName < 4
                      userName = firstName;
                      charsNeeded -= lengthOfName;
                   } // First part of userName done.

                  lengthOfName = lastName.length();
                  if (lengthOfName >= charsNeeded) {
                      userName = userName + lastName.left(charsNeeded);
                  }
                  else { // lengthOfName < charsNeeded: append zeros.
                      userName = userName + lastName;
                      charsNeeded -= lengthOfName;

                      for (int i = 0; i <= charsNeeded-1; ++i){
                          userName = userName + "0";
                      }
                  }
                  userName = userName.toLower(); // Completed for output.

//MAKE INITIAL PASSWORD
                  //strip spaces from userFullname.
                  tempFullName = UserFullName; //refresh working copy

                  for (int i = lengthOfFullName; i-- > 0; ){
                      if (tempFullName[i] == " "){
                          tempFullName.remove(i, 1);
                      }
                  }

                  lengthOfFullName = tempFullName.length();
                  int tempArray[5]; // Pseudo-random sequence begins.
                  for(int i=0; i <= 4; i++){
                      tempArray[i] = rand() % lengthOfFullName;
                  } // End sequence.

                  // Extracting randomly characters begins.
                  for(int i=0; i <= 4; i++){
                      initpw[i] = tempFullName.at(tempArray[i]);
                  }// End sequence.
                  initpw = initpw.toLower(); // Random password for output.
                }
            else {
               return EXIT_SUCCESS;
            }

//OUTPUT RESULT
           QString response = QString("User full name: %1\n\n UserName: %2\n Initial Password: %3\n")
                .arg(UserFullName) .arg(userName) .arg(initpw);

           answer = QMessageBox::information(0, "OUTPUT", response, QMessageBox::Yes|QMessageBox::No);

    } while (answer == QMessageBox::Yes);
// END
    return EXIT_SUCCESS;
}
