#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	double *vektory1, *vektory2, soucet = 0, v1 = 0, v2 = 0;
	int pocetVektoru;

	cin >> pocetVektoru;
	if (cin.fail() || pocetVektoru <= 0){
		cout << "Nespravny vstup." << endl;
		return 1;
	}

	vektory1 = new double[pocetVektoru];
	vektory2 = new double[pocetVektoru];

	for (int i = 0; i < pocetVektoru; i++){
		cin >> vektory1[i];
		if (cin.fail()){
			cout << "Nespravny vstup." << endl;
			delete(vektory1);
			delete(vektory2);
			return 1;
		}
	}
	for (int i = 0; i < pocetVektoru; i++){
		cin >> vektory2[i];
		if (cin.fail()){
			cout << "Nespravny vstup." << endl;
			delete(vektory1);
			delete(vektory2);
			return 1;
		}
	}

	for (int i = 0; i < pocetVektoru; i++) {
		soucet = (vektory1[i] * vektory2[i]) + soucet;
		v1 = vektory1[i] * vektory1[i] + v1;
		v2 = vektory2[i] * vektory2[i] + v2;
	}

	v1 = sqrt(v1);
	v2 = sqrt(v2);

	cout << "CSM: " << fixed << setprecision(3) << (soucet / (v1*v2)) << endl;
	delete(vektory1);
	delete(vektory2);
#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}