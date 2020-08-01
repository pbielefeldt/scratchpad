#include <iostream>
#include <iomanip>
#include <float.h>
#include <limits.h>
//#include <math.h>

/* (C) Philipp Bielefeldt, 2020
 * Small example programme to test out things with floats, doubles, integers, 
 * and casting between them. Compile with:
g++ -Wall --pedantic -std=gnu++17 -o fun_with_decimals.o fun_with_decimals.cpp
 *
 * Available under the conditions of the Mozilla Public License 2.0
 */
 
 using namespace std;

int main()
{
	// For random numbers, that do not have a well-defined bit pattern
	// BTW: 42 random numbers from https://www.random.org/integers/?num=14&min=100&max=999&col=2&base=10&format=html&rnd=new
	const double my_double = 71.7378897847443177366960951892377136265314;	
	const float my_float = static_cast<float>(my_double);
	cout << setprecision(42) << my_double << "\n" << my_float <<endl;
	
	
	// using the integrated macros for small numbers
	const double dbl_min = DBL_MIN;
	double small_dbl = 3.*dbl_min;
	small_dbl /= 3.;
	const float flt_min = FLT_MIN;
	float small_flt = 3.*flt_min;
	small_flt /= 3.;
	
	cout << setprecision(65) << "double" << "\n" <<
			dbl_min << "\n" << 
			small_dbl << "\n" << "float" << "\n" << 
			flt_min << "\n" <<
			small_flt << endl;

	small_dbl = 1. + (dbl_min * dbl_min);
	small_dbl = small_dbl/dbl_min - 1./dbl_min; // should now be DBL_MIN again
	cout << setprecision(65) << "re-calcutlated DBL_MIN: \n" << 
	        small_dbl << endl;
	
	
	// divide et impera ;-)
	const int three = 3.;
	const float three_half_v1 = three/2;
	const float three_half_v2 = three/2.;
	const float three_half_v3 = static_cast<float>(three)/2;
	const float three_half_v4 = static_cast<float>(three)/2.;
	
	cout << "none: 	" << three_half_v1 << "\n" <<
			"dot: 	" << three_half_v2 << "\n" << 
			"cast: 	" << three_half_v3 << "\n" <<	
			"all: 	" << three_half_v4 << "\n" << endl;	
	
	
	return 0; 
	
}

