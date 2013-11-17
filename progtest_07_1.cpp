#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
	char hexa[128];
	int j = 0, por = 0, cislo = 0;

	cout << "Zadejte hexadecimalni cislo:" << endl;
	gets(hexa);

	while (hexa[j] != '\0'){
		if ((hexa[j] >= '0' && hexa[j] <= '9') || (hexa[j] >= 'A' && hexa[j] <= 'F') || (hexa[j] >= 'a' && hexa[j] <= 'f')){
			por++;
		}
		else{
			cout << "Nespravny vstup." << endl;
			#ifndef __PROGTEST__
				system("pause"); /* toto progtest "nevidi" */
			#endif /* __PROGTEST__ */
			return 0;
		}
		j++;
	} //while()

	por = por - 1;
	
	for (int i = 0; i < j; i++){
		if (hexa[i] >= '0' && hexa[i] <= '9'){
			cislo = cislo + (hexa[i] - 48) * pow(16, por);
			por = por - 1;
		}
		else if (hexa[i] >= 'A' && hexa[i] <= 'F'){
			cislo = cislo + (hexa[i] - 55) * pow(16, por);
			por = por - 1;
		}
		else if (hexa[i] >= 'a' && hexa[i] <= 'f'){
			cislo = cislo + (hexa[i] - 87) * pow(16, por);
			por = por - 1;
		}
	} //for()

	cout << "Desitkove: " << cislo << endl;

	#ifndef __PROGTEST__
		system("pause"); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
	return 0;
} //main()