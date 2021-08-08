#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/* Test pushing to a vector
 * 
g++ -Wall -std=gnu++17 -o sort_and_select.o sort_and_select.cpp
./sort_and_select.o
 */
 
class MyThing
{
private:
	double value;
public:
	void set_value(const double v){value=v;}
	double get_value() const {return value;}
};

 
using namespace std;

int main()
{
	// create and fill the vector
	vector<MyThing> a_vector;
	
	for (int ii=0; ii<7; ii++)
	{
		double a_number = ii*(ii+0.5);
		if (ii % 4 == 0)
		{
			a_number = a_number / 7.;
		}
		
		MyThing a_thing;
		a_thing.set_value(a_number);
		a_vector.push_back(a_thing);
	}
	
	cout << "created vector: " << endl;
	for (const auto& it : a_vector)
	{
		cout << it.get_value() << endl;
	}
	
	// sort the vector descending
	sort(a_vector.begin(), 
         a_vector.end(), 
         [](MyThing tt1, MyThing tt2) {return (tt1.get_value() > tt2.get_value()); });

	
	// cut it
	a_vector.resize(3);

 	cout << "sorted and cut vector: " << endl;
 	for (const auto& it : a_vector)
 	{
 		cout << it.get_value() << endl;
 	}

 	return 0;
 }
