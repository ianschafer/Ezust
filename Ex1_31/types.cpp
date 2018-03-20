#include <QTextStream>

int main() {
	QTextStream cout(stdout);
	int i = 5;
	int j=6;
    int* p = &i;                             /* 1 *p: pointer to int i, value 5 */
	int& r=i;      
    int& rpr=(*p);                           /* 2 *p: rpr reference to p, value 5 */
	i = 10;
    p = &j;                                  /* 3 *p: pointer to j, value 6 */
    rpr = 7;                                 /* 4 rpr: reference to p, value now 7 */

    r = 8;
    cout << "i=" << i << " j=" << j << endl; /* 5 i: int value 8 j: int value 6 */
	return 0;
}

/*
  PROGRAM OUTPUT:
  i=8 j=6
*/
