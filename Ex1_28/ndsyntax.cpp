#include <iostream>
using namespace std;

int main() {
 int* ip = 0;               /* null pointer */
 cout << "address stored in ip " << ip << endl;
 delete ip;                 /* has no effect at all - ip is still null. */
 if(ip) cout << "ip is non-null after delete" << endl;
 else cout << "ip is still null after delete" << endl;
 int *pp = new int;              /* allocate space for an int */
 cout << "value of pp " << pp << endl;
 ip = new int;              /* allocate space for an int */
 cout << "value of ip " << ip << endl;
 int* jp = new int(13);     /* allocate and initialize */
 cout << "value of *jp " << *jp << endl;
 cout << "value of jp " << jp << endl;
 //[...]      
 delete pp;
 delete ip;                 /* Without this, we have a memory leak. */
 delete jp;
}
