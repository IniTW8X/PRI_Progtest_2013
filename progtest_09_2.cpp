#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

string zmensi(string pom){
	for (unsigned int i = 0; i < pom.length(); i++){
		pom[i] = tolower(pom[i]);
	}
	return pom;
}

int main(){
	string str1, str2, str3, pom;
	int str2mez = 0, mezer = 0;

	cout << "Zadejte 3 slova:" << endl;
	//nacteni stringu
	cin >> str1;
	getline(cin, str2);
	str3 = str2;

	//osetreni nespravneho vstupu
	for (unsigned int i = 0; i < str2.length(); i++){
		if (isspace(str2[i]) != 0){ mezer++; }
	}
	if (mezer != 2){ cout << "Nespravny vstup." << endl; return 1; }

	//vymezeni stringu, vlozeni do variables
	if (str2[0] == ' ') {
		str2mez = str2.find(' ', 2);
		str2 = str2.substr(1, (str2mez - 1));
	}
	else{ return 1; }

	if (str3[0] == ' ') {
		str3 = str3.substr((str2mez + 1), -1);
	}
	else{ return 1; }



	//zmensi a over
	if (zmensi(str1).compare(zmensi(str2)) == 0){
		cout << "Slovo1 a slovo2 jsou stejna." << endl;
	}
	else{ cout << "Slovo1 a slovo2 nejsou stejna." << endl; }

	if (zmensi(str1).compare(zmensi(str3)) == 0){
		cout << "Slovo1 a slovo3 jsou stejna." << endl;
	}
	else{ cout << "Slovo1 a slovo3 nejsou stejna." << endl; }

	if (zmensi(str2).compare(zmensi(str3)) == 0){
		cout << "Slovo2 a slovo3 jsou stejna." << endl;
	}
	else{ cout << "Slovo2 a slovo3 nejsou stejna." << endl; }

	pom = str1; // protoze str1 ma mnohem vice znaku alokovano?!
	cout << "Pocet znaku ve slovo1 je: " << pom.length() << endl;
	cout << "Pocet znaku ve slovo2 je: " << str2.length() << endl;
	cout << "Pocet znaku ve slovo3 je: " << str3.length() << endl;

	/*debug
	cout << "1" << str1.size() << endl;
	cout << "2" << str2 << endl;
	cout << "3" << str3 << endl;
	cout << "pom " << pom.size() << endl;
	*/
#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}

