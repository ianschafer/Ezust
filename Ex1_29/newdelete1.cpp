#include <QTextStream>

int main() {
    QTextStream cout(stdout);
    const char tab = '\t';
    int n = 13;
    int* ip = new int(n + 3);
    double d = 3.14;
    double* dp = new double(d + 2.3);
    char c = 'K';
    char* cp = new char(c + 5);
    cout << *ip << tab << *dp << tab << *cp << endl;
    int* ip2 = ip;
    cout << ip << tab << ip2 << endl;
    *ip2 += 6;
    cout << *ip << endl;
    delete ip;
    cout << *ip2 << endl;
    cout << ip << tab << ip2 << endl;
    return 0;
}

/* Ex 1.29 predict the output of the example:
 Line 12:16 5.44    P (NOTE K + 5 gives P not K5 concatenated)
 Line 14:0xa13b1a8   0xa13b1a8
 Line 16:22
 Line 18:22
 Line 19:0xa13b1a8  0xa13b1a8 (NOTE - Line 19 first cout ... pointer ip deleted in Line 17 still holds the address)
 */
