#include <iostream>
#include <vector>

/* compile with
g++ -Wall -o variance.o variance.cpp 
 * and run with
./variance.o
 * enter the numbers you want to calculate the variance from, and their 
 * respective weight factors
 * 
 * end with Ctrl+C
 */

/* Tool to use the parallel axis theorem to calculate variance of a set of
 * (weighted) objects, such as a cluster (where ‘weight’ is the amplitude or
 * energy of any hit contributing to the pad, and ‘amp’ is the total cluster
 * amplitude).
 * This is the Wikipedia article I followed: 
https://de.wikipedia.org/wiki/Verschiebungssatz_(Statistik)
 * also with the nomenclature for q1 and q2; SQ_x is called sq here.
 */
 
using namespace std;

class cluster
{
private:
	int n; // number of "hits" added to cluster
	float cog; // centre of gravity; mean value
	float amp; // weight of the cluster
	float q1;  // sum of positions
	float q2;  // sum of squares
	
	
public:
	cluster()
	{
		n = 0;
		cog = 0;
		amp = 0;
		q1 = 0;
		q2 = 0;
	}
	
	void add(float value, float weight)
	{
		// un-weighted way, as in Wikipedia
		/*
		q1 = q1 + value;
		q2 = q2 + value*value;
		*/
		
		// probability (nan for first entry!)
		const float p = weight*(float)n/(amp);
		
		if (q1==0) 
			q1 = value;
		else
			q1 = q1 + value*p;
		
		if (q2==0)
			q2 = value*value;
		else
			q2 = q2 + value*value*p;
		
		// not needed for the variance, but a value you might be familiar with
		cog = (cog*amp + value*weight) / (amp+weight);
		
		amp = amp + weight;
		n++;
		
		const float sq = q2 - q1*q1/n;
		
		cout << "added hit " << n << 
//		        ", q1 = " << q1 << ", q2 = " << q2 << 
		        ", cog = " << cog << 
		        ",\tvariance = " << sq/(n-1) << endl;
	}

};

int main()
{
	float x, w;
	cluster c;

	while (true)
	{
		cout << "\ngive x ";
		cin >> x;
		
		cout << "& give w ";
		cin >> w;
		
		c.add(x, w);
	}
}
