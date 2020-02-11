#include <iostream>
#include <array>

/* compile with
g++ -Wall --pedantic -std=gnu++11 -o access_array.o access_array.cpp
*/

using namespace std;

class my_class
{
private:
    
public: 
    double d;
    int i;
    
    // some constructor
    my_class(double a_double, int a_int)
    {
        d = a_double;
        i = a_int;
    }
    
    // defaults (with values)
    my_class()
    {
        d = 2.5;
        i = 10;
    }
    
    ~my_class(){;}
    
    void setd(double x) { d=x; }
    void seti(int x) { i=x; }
    
    void print()
    {
        cout << "d: " << d << ", i: " << i << endl;
    }
};

int main() 
{
    array<my_class, 5> a1;
    
    a1[0].setd(1.1);
    a1[0].seti(2);
    
    // a1[1] left with defaults
    
    my_class c2 = a1[2]; // COPY
    c2.setd(4.2); // won't work!
    c2.seti(84);  // won't work!
    
    my_class* c3 = &a1[3];
    c3->setd(42.42);
    c3->seti(8484);
    
    a1.at(4).setd(0);
    a1.at(4).seti(0);
    
    for (auto& c : a1)
    {
        c.print();
    }
    
    return 0;
}
