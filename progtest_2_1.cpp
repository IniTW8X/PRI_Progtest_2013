
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


int main()
{
    double a, b, c, disk, x1, x2;
    
    cout << "Zadejte parametry a, b, c kvadaticke rovnice:" << endl;
    cin >> a >> b >> c;

   if (a == 0) {
        cout << "Nespravny vstup.\n";
		#ifndef __PROGTEST__
			system ( "pause" ); /* toto progtest "nevidi" */
		#endif /* __PROGTEST__ */
		return 0;
    }
    
	disk = b*b - (4*a*c);

	if (disk < 0){
		cout << "Rovnice nema reseni v R.\n";
	}
    
	else{
		x1 = ((-b -sqrt(disk))/(2*a));
		x2 = ((-b +sqrt(disk))/(2*a));
		cout << fixed << setprecision(2);
		cout << "Koren 1, x1: " << x1 << endl;
		cout << "Koren 2, x2: " << x2 << endl;
	}
#ifndef __PROGTEST__
  system ( "pause" ); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
    return 0;
}