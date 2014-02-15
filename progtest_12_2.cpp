#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

const double pi = 3.14159265358979323846;

typedef struct
{
	double x;
	double y;
	double fi;
	double v;
	double delta;
	double omega;
}vstup;

int main()
{
	int opakovani = 0;
	vstup param;

	cin >> opakovani;
	if (cin.fail() || opakovani <= 0)
	{
		cout << "Nespravny vstup." << endl;
		return 1;
	}
	cin >> param.x >> param.y >> param.fi >> param.delta >> param.v >> param.omega;
	if (cin.fail())
	{
		cout << "Nespravny vstup." << endl;
		return 1;
	}

	for (int i = 0; i < opakovani; i++)
	{
		param.x = param.x + param.v * param.delta * cos(param.fi);
		param.y = param.y + param.v * param.delta * sin(param.fi);
		param.fi = param.fi + (param.delta * param.omega);

		while (param.fi > 2 * pi)
		{
			param.fi -= 2 * pi;
		}

		cout << fixed << setprecision(2) << "x: " << param.x << ", y: " << param.y << ", fi: " << param.fi << endl;
	}

#ifndef __PROGTEST__
	system("pause"); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
	return 0;
}
