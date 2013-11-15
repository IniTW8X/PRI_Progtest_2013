#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

double binom(double x){
	double vys = x;
	if (x == 0){
		return 1;
	}
	for (int i = vys - 1; i > 0; i--){
		vys = vys * i;
	}
	return vys;
}

int main(){
	double n = 0, k = 0;
	cout << "Zadejte n a k:" << endl;

	cin >> n;
	cin >> k;

	if (n < 0 || k < 0 || cin.fail() || n < k) {
		cout << "Nespravny vstup." << endl;
		#ifndef __PROGTEST__
			system("pause"); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
		return 0;
	}

	double fn = binom(n);
	double fk = binom(k);
	double fnk = binom(n - k);

	cout << "C = " << fn / (fk * fnk) << endl;

#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}