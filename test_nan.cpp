#include <iostream>
#include <math.h>

/*
g++ -Wall -o nan.o test_nan.cpp 
*/

int main()
{
	const double x1 = 4.2415926; // not a nan
	const double x2 = sqrt(-1.); // a nan
	
	const bool any_nan = isnan(x1) || isnan(x2);
	const bool all_nan = isnan(x1) && isnan(x2);
	
	if (any_nan)
		std::cout << "one of the numbers was a NaN" << std::endl; 

	if (all_nan)
		std::cout << "all of the numbers were NaN" << std::endl; 
}
