#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool prvocislo(int cislo) {
	int odm = sqrt((double)cislo);

    if (cislo < 2) return false;
    if (cislo == 2) return true;
    if (cislo % 2 == 0) return false;
 
    for (int i = 3; i <= odm; i += 2) {
        if (cislo % i == 0) {
            return false;
        }
    }
 
    return true;
}

int main(){
	static int a, b;
	cout << "Zadejte interval:" << endl;
	cin >> a >> b;

	if (!cin.good()){
	cout << "Nespravny vstup." << endl;
	
	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
	}

	if (a>b){
	cout << "Nespravny vstup." << endl;

	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
	}

	for(int i = a; i<=b; i++){
		if(prvocislo(i) == true){
		cout << i << endl;
		}
	}

	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
} //main()