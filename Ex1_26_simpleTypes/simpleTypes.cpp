#include <QtWidgets>

int main (int argc, char* argv[]) {                 /* Start of function "main" which returns int. */
    QApplication app(argc, argv);                   /* Start of every Qt GUI application. */
    QTextStream cout(stdout);                       /* Create a QTextStream to standard output. */

    // Declarations of variables
    double celciusValue = 0;
    double fahrenheitValue(0);
    int answer = 0; /* Must be defined outside the do loop because
                    it is used in the condition outside the do block. */

    do {
        // local variables to the loop:
        bool ok;

        celciusValue = QInputDialog::getDouble(0, "Convert",
                                        "Input Celcius value: ", 0, 0, 100, 2, &ok);
           if (ok){
                  fahrenheitValue = (celciusValue*1.8) + 32.0;
                  cout << "\n\nAnswer: C " << celciusValue << " is F " << fahrenheitValue << "\n" << endl;

                  cout << "Conversion table:"  << endl;
                  for(int i=0; i <= 100; i+=5){
                    cout << "For C = " << i << "; F = " << (i*1.8)+32.0 << endl;
                  }
                  cout << "End table\n"  << endl;

                }
            else {
               return EXIT_SUCCESS;
            }

           QString response = QString("%1 Celcius is\n %2 Fahrenheit.\n\n%3")
                .arg(celciusValue).arg(fahrenheitValue)  /* Each %n is replaced with an arg() value. */
                .arg("Convert another value?");          /* Long statements can continue on multiple lines. */



           answer = QMessageBox::question(0, "Answer", response, QMessageBox::Yes | QMessageBox::No);

    } while (answer == QMessageBox::Yes);
    return EXIT_SUCCESS;
}

