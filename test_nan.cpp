#include <iostream>
#include <math.h>

/*
g++ -Wall -o nan.o test_nan.cpp 
*/

int main()
{
	const double x1 = 4.2415926; // not a nan
	const double x2 = sqrt(-1.); // a nan
	
	const bool nan1 = isnan(x1);
	const bool nan2 = isnan(x2);
	const bool any_nan = isnan(x1) || isnan(x2);
	const bool all_nan = isnan(x1) && isnan(x2);
	
	std::cout << "1. " << nan1 << ", 2. " << nan2 << "\nany: " << any_nan << ", all: " << all_nan << std::endl; 
}
