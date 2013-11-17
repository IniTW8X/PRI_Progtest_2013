#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i = 0;
	int j = 0;
    
    char *znak = (char*) malloc(81);
    char *tisk = (char*) malloc(81);
    
    scanf("%s", znak);
    
    while (znak[i] != '\0')
    {
        if (znak[i] >= 'a' && znak[i] <= 'z')
        {
            tisk[j] = znak[i] - 32;
            j++;
        }

        if (znak[i] >= 'A' && znak[i] <= 'Z')
        {
            tisk[j] = znak[i] + 32;
            j++;
        }
        
        if (znak[i] >= '0' && znak[i] <= '9')
        {
            tisk[j] = znak[i] + 49;
            j++;
        }
        
        i++;
    }
    
    tisk[j] = '\0';
    
    printf("%s\n", tisk);

    #ifndef __PROGTEST__
		system ( "pause" ); /* toto progtest "nevidi" */
	#endif /* __PROGTEST__ */
    return 0;
}