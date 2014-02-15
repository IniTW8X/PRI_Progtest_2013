#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

string binSoucet(string bin1, string bin2) {
	string souc;
	string pren = "0";
	long long rozdil = (long long)bin1.size() - (long long)bin2.size();

	// po rekurzi kontrola, zda jsem na konci stringu, mozny konec fce
	if ((unsigned)bin2.find_first_of('1') == (unsigned)-1){
		if ((unsigned)bin1.find_first_of('1') == (unsigned)-1){
			return bin1; // vysledek fce pokud jsou oba stringy na konci
		}
		else{
			return bin1.substr(bin1.find_first_of('1')); // pokud ne, vypis string ze stringu (od prvni jednicky)
		}
	}
	//vyrovnani delek stringu
	rozdil = abs(rozdil);
	if (bin1.size() > bin2.size()) {
		for (int i = 0; i < rozdil; ++i)
			bin2 = '0' + bin2;
	}
	else {
		for (int i = 0; i < rozdil; ++i)
			bin1 = '0' + bin1;
	}
	//samotna adice
	for (int i = bin1.size() - 1; i >= 0; --i) {
		if ((bin1.at(i) == '1' && bin2.at(i) == '1') || (bin1.at(i) == '0' && bin2.at(i) == '0')){
			souc = '0' + souc;
		}
		else{
			souc = '1' + souc;
		}
		if (bin1.at(i) == '1' && bin2.at(i) == '1'){
			pren = '1' + pren;
		}
		else{
			pren = '0' + pren;
		}
	}
	return binSoucet(souc, pren); // rekurze
}

int main(){
	string vstup, bin1, bin2;
	long long nula1 = 0, nula2 = 0;

	cout << "Zadejte dve binarni cisla:" << endl;

	cin >> bin1;
	getline(cin, bin2);

	if (bin2[0] == ' ') {
			bin2 = bin2.substr(1, -1);
		}
		else{
			cout << "Nespravny vstup." << endl;
			return 0;
		}
	

	for (unsigned long long i = 0; i < bin1.size(); i++){
		if (bin1[i] != '0' && bin1[i] != '1') {
			cout << "Nespravny vstup." << endl;
			return 0;
		}
		if (bin1[i] == '0'){ nula1++; }
	}

	for (unsigned long long i = 0; i < bin2.size(); i++){
		if (bin2[i] != '0' && bin2[i] != '1') {
			cout << "Nespravny vstup." << endl;
			return 0;
		}
		if (bin2[i] == '0'){ nula2++; }
	}
	if ((unsigned)nula1 == bin1.size() && (unsigned)nula2 == bin2.size()){
		cout << "Soucet: 0" << endl;
		return 0;
	}

	cout << "Soucet: " << binSoucet(bin1, bin2) << endl;

#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}