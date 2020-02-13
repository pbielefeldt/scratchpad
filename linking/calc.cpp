#include <math.h>
#include <iostream>
#include "mylib.h"
double my_sqrt(double d)
{
	double re = sqrt(d);
	std::cout << "sqrt(" << d << ") = " << re << std::endl;
	return re;
}
