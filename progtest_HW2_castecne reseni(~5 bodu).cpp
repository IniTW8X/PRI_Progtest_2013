/**
\file main.cpp
\brief Hlavni soubor programu obsahujici vsechny uzite funkce
*/
#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#define EASTER_OK                0
#define EASTER_INVALID_FILENAME  1
#define EASTER_INVALID_YEARS     2
#define EASTER_IO_ERROR          3


#endif /* __PROGTEST__ */
/**
\brief Hlavicka a paticka vystupniho html souboru
*/
const char *hlavicka =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n<html>\n"
"<head>\n"
"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n<title>C++</title>\n"
"</head>\n"
"<body>\n"
"<table width=\"300\">\n"
"<tr><th width=\"99\">den</th><th width=\"99\">mesic</th><th width=\"99\">rok</th></tr>\n";

const char *paticka =
"</table>\n"
"</body>\n"
"</html>\n";

/**
\brief Globalni promenne pro obe funkce
*/
int den;
string mesic;
/**
\brief Funkce pro vypocet data a mesice velikonoc, tyto hodnoty ulozi do globalni promenne
\param rok je rok, pro ktery se hleda datum velikonoc
\return Vraci EASTER_OK  = 0
*/
int vypocetVelikonoc(int rok)
{
	int A = rok % 19;
	int B = rok / 100;
	int C = rok % 100;
	int D = B / 4;
	int E = B % 4;
	int F = (B + 8) / 25;
	int G = (B - F + 1) / 3;
	int H = (19 * A + B - D - G + 15) % 30;
	int I = C / 4;
	int K = C % 4;
	int L = (32 + 2 * E + 2 * I - H - K) % 7;
	int M = (A + 11 * H + 22 * L) / 451;
	int N = (H + L - 7 * M + 114) / 31;
	int P = (H + L - 7 * M + 114) % 31;
	den = P + 1;

	if (N == 3)
	{
		mesic = "brezen";
	}
	else
	{
		mesic = "duben";
	}

	return EASTER_OK;
}

int zkontrolujFilename(const char *outFileName)
{
	char *ptr = strrchr((char *)outFileName, '.');

	if (strlen(outFileName) < 6 || strcmp(ptr, ".html") != 0) {
		return EASTER_INVALID_FILENAME;
	}

	for (unsigned int i = 0; i < strlen(outFileName); i++) {
		if (!isalnum(outFileName[i]) && outFileName[i] != '.' && outFileName[i] != '/' && outFileName[i] != '\\') {
			return EASTER_INVALID_FILENAME;
		}
	}

	return EASTER_OK;
}

/**
\brief Funkce pro ziskani data a mesice velikonoc, zaroven exportuje do html
\param years pole charu pro zadani let
\param outFileName pole charu pro zadani nazvu exportovaneho souboru
\return Vraci 0 pokud probehlo vse dobre, jine hodnoty pokud nastala chyba
*/
int easterReport(const char * years, const char * outFileName)
{
	int i = 0, pozice1 = 0, pozice2 = 0, pocetRoku = 0;
	int interval[5];
	int pocetIntervalu = 0;
	int pocetMezi = 0;
	string roky = years;
	string rok;
	int delkaStr = roky.length();
	int *poleRoku = new int[20];

	if (zkontrolujFilename(outFileName) != EASTER_OK) {
		return EASTER_INVALID_FILENAME;
	}
	/**
	\brief Osetreni outFileName
	*/
	if (strstr(outFileName, ".html") == NULL)
	{
		return EASTER_INVALID_FILENAME;
	}

	if (strlen(outFileName) < 6)
	{
		return EASTER_INVALID_FILENAME;
	}

	char *ukaz = strrchr((char *)outFileName, '.');
	if (strcmp(ukaz, ".html") != 0)
		return EASTER_INVALID_FILENAME;

	for (unsigned int i = 0; i<strlen(outFileName); i++)
	{
		if (isalnum(outFileName[i]) == 0)
		{
			switch (outFileName[i])
			{
			case '/':
			case '\\':
			case '.':
				break;
			default:
				return EASTER_INVALID_FILENAME;
			}
		}
	}

	for (unsigned int e = 0; e < strlen(years); e++)
	{
		if (!((years[e] > 47 && years[e] < 58) || years[e] == '-' || years[e] == ',' || years[e] == ' '))
		{
			return EASTER_INVALID_YEARS;
		}
	}
	while (i < delkaStr)
	{
		if (roky.length()==5)
		{
			return EASTER_INVALID_YEARS;
		}
		/**
		\brief Vytvori substring a priradi jej do poleRoku, pokud je delimiter carka
		*/
		if (roky[i] == ',' || i == (delkaStr - 1))
		{
			if (roky[i + 1] == '-' || roky[i + 1] == ',')
			{
				return EASTER_INVALID_YEARS;
			}
			pozice2 = i;
			rok = roky.substr(pozice1, pozice2);
			poleRoku[pocetRoku] = atoi(rok.c_str());
			pozice1 = pozice2 + 1;
			pocetRoku++;
		}
		/**
		\brief Vytvori substring a priradi jej do poleRoku, pokud je delimiter pomlcka nebo --
		*/
		else if (roky[i] == '-')
		{
			if (roky[i + 1] == '-')
			{
				return EASTER_INVALID_YEARS;
			}
			else if (roky[i + 1] == ',')
			{
				return EASTER_INVALID_YEARS;
			}
			else if (roky.length() == 5)
			{
				return EASTER_INVALID_YEARS;
			}
			else
			{
				pozice2 = i;
				rok = roky.substr(pozice1, pozice2);
				poleRoku[pocetRoku] = atoi(rok.c_str());
				interval[pocetIntervalu] = pocetRoku;
				pozice1 = pozice2 + 1;
				pocetRoku++;
				pocetIntervalu++;
			}
		}
		i++;
	}
	/**
	\brief Osetreni, aby byly roky v zadanem rozmezi
	*/
	for (int i = 0; i < pocetRoku; i++)
	{
		if (poleRoku[i] <= 1582 || poleRoku[i] >= 2220)
		{
			return EASTER_INVALID_YEARS;
		}
	}
	/**
	\brief Rozbali intervaly a priradi je do poleRoku
	*/
	if (pocetIntervalu != 0)
	{
		int j = interval[0];
		pocetMezi = pocetRoku + (poleRoku[interval[0] + 1] - poleRoku[interval[0]]);

		while (pocetRoku < pocetMezi)
		{
			poleRoku[j + 1] = poleRoku[j] + 1;
			j++;
			pocetRoku++;
		}
		pocetRoku = pocetRoku - 1;
	}

	/**
	\brief Export do html
	*/
	ofstream exportuj;
	exportuj.open((const char *)outFileName);

	if (!exportuj.is_open()){
		return EASTER_IO_ERROR;
	}
	// vloz hlavicku
	exportuj << hlavicka;

	for (int i = 0; i < pocetRoku; i++)
	{
		vypocetVelikonoc(poleRoku[i]);
		exportuj << "<tr><td>" << den << "</td><td>" << mesic << "</td><td>" << poleRoku[i] << "</td></tr>" << endl;;
	}

	// vloz paticku
	exportuj << paticka;
	exportuj.close();
	if (exportuj.fail()){ return EASTER_IO_ERROR; }

	delete[] poleRoku;
	return EASTER_OK;
}

#ifndef __PROGTEST__
/**
\brief Hlavni funkce programu, ktera vola funkci easterReport
\param argc pocet prikazu konzole
\param argv prikazy konzole
\return Vraci 0
*/
int main(int argc, char * argv[])
{
	int status;
	//easterReport("2001 , 2002  ,  2003 ,2005,2006", "out2.html");
	//easterReport("2012,2013,2015-2020", "out0.html");
	//easterReport("2000 - 2014", "out1.html");
	//easterReport("2001 , 2002  ,  2003 ,2005,2006", "out2.html");
	//easterReport("2000,2011,2010-2020", "out3.html");
	//easterReport("2000-3000", "out4.html");

	status = easterReport("2010-", "a.html"); /* return: 2 */
	printf("status: %d\n", status);

	system("pause");
	return 0;
}
#endif /* __PROGTEST__ */