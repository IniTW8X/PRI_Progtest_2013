#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#endif /* __PROGTEST__ */

int evenOdd ( const char * srcFileName, const char * dstFileName )
{
    FILE *f1, *f2;
    int a;

    if((f1 = fopen(srcFileName, "r")) == NULL) {
        return 0;
    }

    if((f2 = fopen(dstFileName, "w")) == NULL) {
        return 0;
    }

    while((fscanf(f1, "%d", &a)) != EOF) {
        if(a % 2 == 0) {
            fprintf(f2, "%d\n", a);
        }
    }
    rewind(f1);
    if(f1 == NULL) {
        return 0;
    }

    while((fscanf(f1, "%d", &a)) != EOF) {
        if(a % 2 != 0) {
            fprintf(f2, "%d\n", a);
        }
    }

    fclose(f1);
    fclose(f2);

    return 1;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   evenOdd("input.txt", "output.txt");
   return 0;
 }
#endif /* __PROGTEST__ */