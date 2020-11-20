#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
//#include <limits.h>

// 'x%'/'percent' = x, x*'percent' = 'x%'
#define percent 100.

/* (C) Philipp Bielefeldt, 2020
 * Kleine Beispielrechnung zum Abschreiben eines Kredits.
 * Zum Kompilieren nutzen Sie:
g++ -Wall --pedantic -std=gnu++17 -o zinszahlung.exec zinszahlung.cpp
 *
 * Available under the conditions of the Mozilla Public License 2.0
 */
 
using namespace std;

void fill_book(vector<double>& b, double summe, const double beitrag, const double zins)
{
	while (summe>=beitrag)
	{
		const double zinskosten = summe*zins;
		const double abzahlung = beitrag-zinskosten;
		summe = summe-abzahlung;
		b.push_back(zinskosten);
	}
	// letzer monat
	const double zinskosten = summe*zins;
	const double abzahlung = summe-zinskosten;
	summe = summe-abzahlung; // = 0
	b.push_back(zinskosten);
}


vector<double> annual(vector<double>& b)
{
	vector<double> re;
	double jahreskosten = 0;
	
	for (size_t m=0; m<b.size(); m++)
	{
		jahreskosten += b.at(m);
		if (m%12==0)
		{
			re.push_back(jahreskosten);
			jahreskosten = 0;
		}
	}
	// letzes Jahr
	re.push_back(jahreskosten);
	
	return re;
}


int main()
{
	double kreditsumme, beitrag_monat, zins_eff_jahr;
	cout << "Geben Sie die Kreditsumme an: "; 
	cin  >> kreditsumme;
	cout << "Geben Sie den monatlichen Beitrag an: ";
	cin  >> beitrag_monat;
	cout << "Geben Sie den effektiven Jahreszins an: "; 
	cin  >> zins_eff_jahr;
	zins_eff_jahr = zins_eff_jahr/percent; 
	
	const double zins_eff_monat = pow(1.+zins_eff_jahr, 1./12.)-1.;
	cout << "Der effektive monatliche Zins betraegt " << zins_eff_monat*percent << "%." << endl;
	
	vector<double> buch;
	fill_book(buch, kreditsumme, beitrag_monat, zins_eff_monat);
	
	unsigned int n = 1; // alles wird besser, wenn man von eins zaehlt ;-)
	for (auto& m : buch)
	{
		cout << n++ << ". Monat: Zinskosten\t" << setprecision(3) << m << fixed << endl; 
	}
	
	vector<double> jahr = annual(buch);
	n = 1; // alles wird besser, wenn man von eins zaehlt ;-)
	for (auto& m : jahr)
	{
		cout << n++ << ". Jahr: Zinskosten\t" << setprecision(3) << m << fixed << endl; 
	}
	return 0; 	
}


