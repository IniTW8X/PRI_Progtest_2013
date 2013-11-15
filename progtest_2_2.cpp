#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    double a, b, c, d, r, xa, xb; 

    printf("Zadejte souradnice bodu A a B:\n");
    
    if (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != 4) {
        printf("Nespravny vstup.\n");
        #ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
		return 0;
    }

	xa = ((a+c)/2);
	xb = ((b+d)/2);
	printf("Stred kruznice je: S[%5f,%5f]\n", xa, xb);

	r = sqrt(c*c - 2*c*a + a*a + d*d - 2*b*d + b*b);

	printf("Polomer kruznice r ma hodnotu: %5f\n", r/2);

	#ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
  return 0;
}