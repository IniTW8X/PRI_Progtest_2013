#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(){
	int atrakce = 50;
    double navst = 0, vydelek = 0, plat = 0;
    cout << "Zadej pocet navstevniku:" << endl;
    cin >> navst;
    if (!cin.good() || navst < 0) {
		cout << "Nespravny vstup." << endl;
		#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
		return 0;
	}
 
    navst = ((navst / 100) * 7);
    vydelek = navst * atrakce;
    
	if (vydelek < 2000){
		plat = 70;
	}
    else if (vydelek < 2500){
		plat = 80;
	}
    else if (vydelek < 3000) {
		plat = 90;
	}
    else if (vydelek < 3500){
		plat = 100;
	}
	else {
		plat = 110;
	}

    cout << "Brigadnik vydela: " << 8 * floor(plat) << " Kc" << endl;
    
	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
} //main()