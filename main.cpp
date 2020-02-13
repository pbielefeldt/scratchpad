/* Run
 * 	g++ -c main.cpp 
 * 	g++ -c calc.cpp 
 * 	g++ -o main calc.o main.o
 * 	./main 
 * 
 * Link statically
 * 	ar crv libcalc.a calc.o
 * 	g++ -o main main.o -L. -lcalc -lm
 */


#include <stdio.h>
#include "mylib.h"
int main()
{
        double d = 1764;
        double s = my_sqrt(d);
        return 0;
}
