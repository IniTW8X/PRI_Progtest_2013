#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

int main(){

	double *prvekA, *prvekB, *prunik;
	int velA = 0, velB = 0, shoda = 0;


	cout << "Zadejte pocet prvku mnoziny A:" << endl;
	cin >> velA;

	if (cin.fail() || velA <= 0){
		cout << "Nespravny vstup." << endl;
		return 1;
	}

	prvekA = (double *)malloc((velA + 1)*sizeof(double));
	prunik = (double *)malloc((velA + 1)*sizeof(double));

	cout << "Zadejte prvky mnoziny A:" << endl;

	for (int i = 0; i < velA; i++){
		cin >> prvekA[i];
		if (cin.fail()){
			cout << "Nespravny vstup." << endl;
			return 1;
		}

		for (int j = 0; j < (i - 1); j++)
		if (prvekA[j] == prvekA[i]){
			cout << "Nespravny vstup." << endl;
			return 1;
		}
	}

	cout << "Zadejte pocet prvku mnoziny B:" << endl;
	cin >> velB;

	if (cin.fail() || velB <= 0){
		cout << "Nespravny vstup." << endl;
		return 1;
	}

	prvekB = (double *)malloc((velB + 1)*sizeof(double));

	cout << "Zadejte prvky mnoziny B:" << endl;

	for (int i = 0; i < velB; i++){
		cin >> prvekB[i];
		if (cin.fail()){
			cout << "Nespravny vstup." << endl;
			return 1;
		}

		for (int j = 0; j < (i - 1); j++)
		if (prvekB[j] == prvekB[i]){
			cout << "Nespravny vstup." << endl;
			return 1;
		}
	}


	for (int i = 0; i < velA; i++)
		for (int j = 0; j < velB; j++){
			if (prvekA[i] == prvekB[j]){
				prunik[shoda] = prvekA[i];
				shoda++;
		}
	}

		cout << "Prunik mnozin:" << endl << "{";
		if (shoda == 0){
			cout << "}" << endl;
		}
		else{
			for (unsigned int i = 0; i < shoda; i++){
				cout << prunik[i];
				if (i != (shoda - 1))
					cout << ", ";
				else {
					cout << "}" << endl;
				}
			}
		}

	free(prvekA);
	free(prvekB);

#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}
