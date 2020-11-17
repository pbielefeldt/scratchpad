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
	void print_public(int a)
	{
		cout << __func__ << ": " << a << endl;
	}
};


class MyDerivedClass : public MyBaseClass
{
public:
	void print_double(double b)
	{
		int beee = int(b);
		print_public(beee);
	}
	
	void print_private(int a)
	{
		cout << "gotcha! print_private is no longer private!" << endl;
		cout << __func__ << ": " << a << endl;
	}
};


int main()
{
	MyBaseClass original;
	original.print_public(19);
	
	MyDerivedClass derived;
	derived.print_public(21);
	derived.print_double(42.3);
	derived.print_private(64.999);

	return 0; 	
}
