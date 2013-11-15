#include <stdio.h>
#include <stdlib.h>

int main() {
    static double i, soucet;
    printf("Zadejte cisla:\n");
    
	while(i != 1000){
		if (scanf("%lf", &i) != 1) {
        printf("Nespravny vstup.\n");

		#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
        return 0;
		} // if()
		soucet = soucet + i;
	} // while()

	printf("Soucet cisel je: %.6f\n", soucet); 

	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
} // main()
