#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() {
	static double a, b, c, s;
	printf("Zadejte delky stran trojuhelniku:\n");

	scanf("%lf %lf %lf", &a, &b, &c);

	if (a <= 0 || b <= 0 ||c <= 0){
		printf("Nespravny vstup.\n");
		#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
		return 0;
	}

	s = ((a+b+c)/2)*(((a+b+c)/2)-a)*(((a+b+c)/2)-b)*(((a+b+c)/2)-c);

	if (s <= 0){
		printf("Strany netvori trojuhelnik.\n");
	} else {
	s = sqrt(s);
	//cout.setf(ios::fixed);
	//cout.precision(4);
	cout << "Trojuhelnik existuje, obsah je: " << s << endl;
	//	printf("Trojuhelnik existuje, obsah je: %.4lf\n", s);
	}

	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
} //main ()