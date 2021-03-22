#include <iostream>
#include <climits>

/* Having fun with integer overflows
 * 
g++ -Wall -o long_int_comp.o long_int_comp.cpp 
 */
 
using namespace std;
 
int main()
{
	// cout << ULLONG_MAX << endl;
	// 2^64-1 = 18446744073709551615 …
	// √ULLONG_MAX = 4294967296
	unsigned long large  = 4294967290;
	unsigned long larger = 4294967295;
	
	int small = 43;
	
//	if ( small > large*larger ) // → warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
	if ( small > static_cast<int>(large*larger) )
	{
		cout << "small is sooooo large!" << endl;
	}
	 	
	return 0;
}
