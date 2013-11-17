#include <stdio.h>
#include <iostream>

int main()
{
    double v, w, h, chyba;
    
    printf("Zadejte hodnoty v, w a h:\n");
    
    if ((scanf("%lf %lf %lf", &v, &w, &h) != 3) || (v <= 0) || (w <= 0) || (h <= 0)){
        printf("Nespravny vstup.\n");

		#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
        return 0;
    }
    
    h = h * ((w * v) / (w * w * h));
    w = w * ((v * h) / (w * h * h));
    chyba = v - (h * w);
    
    printf("Cislo %.3f lze faktorizovat na %.3f x %.3f. Faktorizace ma chybu %.3f.\n", v, w, h, chyba);
    
	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
}

