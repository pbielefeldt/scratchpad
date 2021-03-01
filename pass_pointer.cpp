#include <iostream>
#include <vector>

/* Test pushing to a vector
 * 
g++ -Wall -o pass_pointer.o pass_pointer.cpp 
 */
 
 using namespace std;
 
 class my_class 
 {
 private:
 	bool b;
 	
public:
	my_class(bool a=false)
	{
		b=a;
	}
	
	void set_val(bool a)
	{
		b=a;
	}
	
	bool get_val()
	{
		return b;
	}
 };
 
 
 void set_true(my_class &c)
 {
 	c.set_val(true);
 }
 
 
 int main()
 {
 	vector<my_class*> v;
 	
 	// create the objects
 	for (int i=0; i<14; i++)
 	{
 		my_class* c = new my_class();
 		v.push_back(c);
 	}
 	
 	// modify the objects
 	for (size_t i=0; i<v.size(); i++)
 	{
 		my_class* c_ptr = dynamic_cast<my_class*>(v.at(i));
 		
 		if (i%3 == 0)
 		{
 			set_true(*c_ptr);
 		}
 	}
 	
 	// print
 	for (auto& i : v)
 	{
 		cout << i->get_val() << endl;
 	}
 	
 	return 0;
 }
