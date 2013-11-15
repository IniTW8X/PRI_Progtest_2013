#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

int main(){
	string RC;
	int d, m, r, zbytek, zd;
	long long sum = 0;
	long long sum1 = 0;
	long long sum2 = 0;
	long long sum3 = 0;

	cout << "Zadejte rodne cislo:" << endl;
	cin >> RC;
	if (sscanf(RC.c_str(), "%2d%2d%2d/%4d", &r, &m, &d, &zbytek) != 4){
		cout << "Retezec neni rodnym cislem." << endl;
		return 0;
	}

	if (RC.length() != 11){
		cout << "Retezec neni rodnym cislem." << endl;
		return 0;
	}
	if (RC[6] != '/'){
		cout << "Retezec neni rodnym cislem." << endl;
		return 0;
	}

	for (int i = 0; i < 10; i++){
		if (i == 6){
			i++;
		}
		if (isdigit(RC[i]) == 0){
			cout << "Retezec neni rodnym cislem." << endl;
			return 0;
		}
	}
	sum1 = 10000 * d;
	sum2 = 1000000 * m;
	sum3 = 100000000 * (long long)r;
	sum = sum1 + sum2 + sum3 + zbytek;
	if (sum % 11 != 0){
		cout << "Retezec neni rodnym cislem." << endl;
		return 0;
	}

	if (r < 54){
		zd = r + 1900;
	}
	else{
		zd = r + 2000;
	}

	if (m > 50){
		m -= 50;
	}

	if ((m > 12) || (m < 1) || (d < 1)){
		cout << "Retezec neni rodnym cislem." << endl;
		return 0;
	}

	if (((d > 28 && m == 2) && (r % 4 != 0)) || (m > 29) || (d == 31 && m == 9)){
		cout << "Retezec neni rodnym cislem." << endl;
		return 0;
	}
	else if (d > 31 && m == 11){
		cout << "Retezec neni rodnym cislem." << endl;
		return 0;
	}

	cout << "Retezec muze byt rodnym cislem." << endl;

#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}