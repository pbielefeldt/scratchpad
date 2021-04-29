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

In general, Steiner's theorem says that for the sum *S* of least squares,
```math
	S = \sum_{i=0}^{N} \left( v^{i} - \mu \right)^2 = \left( \sum_{i} (v_{i})^2  \right) - \frac{1}{N} \left( \sum_{i} v_{i} \right)^2
```
holds.
Here, *v* is the value of each contriution (i.e. the position of a hit), and µ is the mean value (i.e. centre of gravity). 
The two sums can be written as *q1* and *q2*. 
For the sample variance, one can write
```math
	\sigma^2 = \frac{1}{N-1} S = \frac{1}{N-1} \left( q_2 - \frac{1}{N}(q_1)^2 \right) ,
```
with 
```math
	q_1 = \sum_{i=0}^N v^i
```
and
```math
	q_2 = \sum_{i=0}^N (v^i)^2 .
```
<!-- 
This part is identical to 
https://de.wikipedia.org/wiki/Verschiebungssatz_(Statistik)#Erl%C3%A4uterung_am_Fall_einer_endlichen_Folge_von_Zahlen:_Das_Stichprobenmittel
-->

For *weighted* values *w·v*, where the centre of gravity is calculated as
```math
	\mu = \frac{\sum_{i}^{N} w^{i} v^{i}}{\sum_{i}^{N} w^{i}}
```
the sums must be weighted as well.
A weighting factor *p* can be introduced that is the weight of the value *i* relative to the average weight of the other values:
```math
	p^{N+1} = \frac{w^{N+1}}{\frac{\sum_{i=0}^{N} w^{i}}{N}}
```

This allows a continuous approximation to the sample variance to be determined:
```math
	q_{1}^{N+1} = q_{1}^{N} + \frac{w^{N+1} \cdot v^{N+1}}{\frac{\sum_{i=0}^{N} w^{i} v^{i}}{N}}
	= q_{1}^{N} + p^{N+1} \cdot v^{N+1} \\
	q_{2}^{N+1} = q_{2}^{N} + \left( p^{N+1} \cdot v^{N+1} \right)^2 \\
	S^{N+1} = q_{2} - \frac{1}{N+1} (q_{1})^2
```

For the standard deviation of a cluster with *N* hist associated, the estimator is
```math
	\sigma^2 = \frac{1}{N-1} \left( q_2 - \frac{1}{N}(q_1)^2 \right)
```

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
		// this weight / average amplitude
		const float avgamp = amp/(float)(n);
		const float p = weight/avgamp;
		
		// formula for q1
		// q_{1}^{N+1} = q_{1}^{N} + \frac{w^{N+1} \cdot v^{N+1}}{\frac{\sum_{i=0}^{N} w^{i} v^{i}}{N}}
		if (q1==0) 
			q1 = value;
		else
			q1 = q1 + value*p;
		
		if (q2==0)
			q2 = value*value;
		else
			q2 = q2 + value*value*p*p;
		
		// not needed for the variance, but a value you might be familiar with
		cog = (cog*amp + value*weight) / (amp+weight);
		
		amp = amp + weight;
		n++;
		
		// variance (sq is just the sum in brackets)
		// \sigma^2 = \frac{1}{N-1} \left( q_2 - \frac{1}{N}(q_1)^2 \right)
		const float sq = q2 - q1*q1/n;
		
		cout << "added hit " << n << 
//		        ", p = " << p << ", q1 = " << q1 << ", q2 = " << q2 << 
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
