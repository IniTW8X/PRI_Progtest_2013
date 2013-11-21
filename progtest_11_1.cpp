#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

typedef struct kniha{
	string nazev;
	string prijmeni;
	string jmeno;
	string zanr;
	int rok;
	int cena;
	int id;
}kniha;


int main(){
	kniha kniha[5];

	//nacteni do struktury
	for (int i = 0; i < 5; i++){
		cout << "Zadej nazev knihy, prijmeni autora, jmeno autora, zanr knihy, rok vydani, cenu a id:" << endl;
		cin >> kniha[i].nazev;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> kniha[i].prijmeni;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> kniha[i].jmeno;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> kniha[i].zanr;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> kniha[i].rok;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> kniha[i].cena;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
		cin >> kniha[i].id;
		if (cin.fail()){ cout << "Nespravny vstup."; return 1; }
	}

	cout << "Romany jsou:" << endl;
	for (int i = 0; i < 5; i++){
		if (kniha[i].zanr == "roman")
			cout << kniha[i].nazev << endl;
	}
	cout << endl;

	cout << "Knihy s cenou mensi nez 300,- Kc jsou:" << endl;
	for (int i = 0; i < 5; i++){
		if (kniha[i].cena < 300)
			cout << kniha[i].nazev << endl;
	}
	cout << endl;

	cout << "Prijmeni vsech autoru jsou:" << endl;
	for (int i = 0; i < 5; i++){
		cout << kniha[i].prijmeni << endl;;
	}


#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}

