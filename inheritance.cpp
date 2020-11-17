#include <iostream>
//#include <math.h>

/* (C) Philipp Bielefeldt, 2020
 * Small example programme to test out things with inheritance. 
 * Compile with:
g++ -Wall --pedantic -o inheritance_cpp.o inheritance.cpp
 *
 * Available under the conditions of the Mozilla Public License 2.0
 */
 
 using namespace std;

class MyBaseClass
{
private:
	virtual void print_private(int a)
	{
		cout << __func__ << ": " << a << endl;
	}
	
public:
	virtual void print_public(int a)
	{
		cout << __func__ << ": " << a << endl;
	}
};


class MyDerivedClass : public MyBaseClass
{
public:
	void lame(double b)
	{
		int beee = int(b);
		print_public(beee);
	}
	
	void badass(double b)
	{
		int beee = int(b);
		//print_private(beee);
	}
};


int main()
{
	MyBaseClass original;
	original.print_public(19);
	
	MyDerivedClass derived;
	derived.print_public(21);
	derived.lame(42.3);

	return 0; 	
}
