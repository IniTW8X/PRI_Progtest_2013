#include <iostream>
#include <stdio.h>
#include <stdlib.h>


 int fibofce(int i) {
    int c1 = 0, vysledek = 0;
	int c2 = 1;
    for (int j = 1; j < i; j++)
    {
        vysledek = c1 + c2;
        c1 = c2;
        c2 = vysledek;
    }

    return vysledek;
}

int main() {
    int i = 2;
    static char vstup;
    printf("Fibonacciho posloupnost zacina cisly 1,1,2\n");
    
	while(vstup != 'n') {
        if(i > 3){
            printf("Zobrazit dalsi? [cokoliv/n]\n");
            vstup = getchar();
            
			if(vstup != '\n'){
                getchar();
            }
            
			if(vstup == 'n'){
					#ifndef __PROGTEST__
						system ( "pause" ); /* toto progtest "nevidi" */
					#endif /* __PROGTEST__ */
			return 0;
			}
            printf("Dalsi cislo Fibonacciho posloupnosti je: %i\n", fibofce(i));
        } // if()
		i++;
    } // while()
	
	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
} //main ()