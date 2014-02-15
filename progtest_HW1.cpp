#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main(){
	char obrazec;
	static double a,b,r,o,s;
	cout << "Zadejte rovinny obrazec, jehoz obsah a obvod chcete spocitat: a - ctverec, b - obdelnik, c - kruh" << endl;
	cin >> obrazec;

	cout.setf(ios::fixed);
    cout.precision(4);

	if(!cin.good()) {
		cout<<"Nespravny vstup."<<endl;
		#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
		return 0;
	}


	switch(obrazec)
	{
		case 'a':
			cout << "Zadejte stranu ctverce:" << endl;
			cin >> a;
			
			if(!cin.good() || a <= 0) {
					cout << "Nespravny vstup." << endl;
					#ifndef __PROGTEST__
						system ( "pause" ); /* toto progtest "nevidi" */
					#endif /* __PROGTEST__ */
					return 0;
			}
			
			o = (4 * a);
			s = (a * a);
			cout << "Obsah ctverce je: " << s << endl;
			cout << "Obvod ctverce je: " << o << endl;
			break;

		case 'b':
			cout << "Zadejte strany obdelniku:" << endl;
			cin >> a >> b;
			if(!cin.good() || a <= 0 || b <= 0) {
					cout << "Nespravny vstup." << endl;
					#ifndef __PROGTEST__
						system ( "pause" ); /* toto progtest "nevidi" */
					#endif /* __PROGTEST__ */
					return 0;
			}
			
			o = (a + b) * 2;
			s = a * b;
			cout << "Obsah obdelniku je: " << s << endl;
			cout << "Obvod obdelniku je: " << o << endl;
			break;

	         case 'c':
			cout << "Zadejte polomer kruznice:" << endl;
			cin >> r;
			if(!cin.good() || r <= 0) {
					cout << "Nespravny vstup." << endl;
					#ifndef __PROGTEST__
						system ( "pause" ); /* toto progtest "nevidi" */
					#endif /* __PROGTEST__ */
					return 0;
			}
			
			o = 2 * M_PI * r ;
			s = M_PI * (r * r);
			cout << "Obsah kruznice je: " << s << endl;
			cout << "Obvod kruznice je: " << o << endl;
			break;

	        default:           
			cout << "Nespravny vstup." << endl;
			break;
	}

	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
}