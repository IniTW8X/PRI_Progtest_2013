#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

typedef struct{
	string prijmeni;
	string jmeno;
	double rodnec;
	string nemoc;
	int pojistovna;
}pacient;


int main(){
	pacient polePacientu[5];

	//nacteni do struktury
	for (int i = 0; i < 5; i++){
		cout << "Zadejte prijmeni, jmeno, rodne cislo, nemoc a zdravotni pojistovnu pacienta:" << endl;
		cin >> polePacientu[i].prijmeni;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> polePacientu[i].jmeno;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> polePacientu[i].rodnec;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> polePacientu[i].nemoc;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> polePacientu[i].pojistovna;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
	}

	for (int i = 0; i < 5; i++){
		if (polePacientu[i].nemoc == "tbc"){
			cout << "Jmeno a prijmeni pacienta s tbc:" << endl << polePacientu[i].jmeno << " " << polePacientu[i].prijmeni << endl;
		}
		if (polePacientu[i].pojistovna == 211){
			cout << "Jmeno a prijmeni pacientu s pojistovnou 211 je:" << endl << polePacientu[i].jmeno << " " << polePacientu[i].prijmeni << endl;
		}
	}
	cout << "Prijmeni vsech pacientu jsou:" << endl;
	for (int i = 0; i < 5; i++){
		cout << polePacientu[i].prijmeni << endl;
	}


#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}
