#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

int main(){
	string heslo;
	static int pismeno, cislo, znak;

	cin >> heslo;
	if (cin.fail()){
		cout << "Heslo nesplnuje pozadavky." << endl;
		return 0;
	}

	if (heslo.size() < 5){
		cout << "Heslo nesplnuje pozadavky." << endl;
		return 0;
	}

	for (unsigned int i = 0; i < heslo.size(); i++){
		if (isalpha(heslo[i])){
			pismeno++;
		}
		else if (isdigit(heslo[i])){
			cislo++;
		}
		else { znak++; }
	} //for()

	if ((pismeno == 0) || (cislo == 0) || (znak == 0)){
		cout << "Heslo nesplnuje pozadavky." << endl;
		return 0;
	}
	else {
		cout << "Heslo splnuje pozadavky." << endl;
	}

#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}

