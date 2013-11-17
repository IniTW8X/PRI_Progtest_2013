#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() 
{ 
static int sum, i;
char b[64]; 
cout << "Zadej cislo ve dvojkove soustave:" << endl; 
cin >> b; 
 

while (i<64 && b[i] != (char)0) {
	sum <<= 1;

	if (b[i] == '1') sum++; 
	else if (b[i] == '0') ; 
	else{ 
		cout << "Nespravny vstup." << endl; 
		#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
		return 0;
	} 
	i++; 
} 

cout << "Desitkove cislo je: " << sum << endl; 
     	#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
 return 0;
}