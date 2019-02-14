#include <iostream>
#include <array>

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
    
    void print()
    {
        cout << "d: " << d << ", i: " << i << endl;
    }
};

int main() 
{
    array<my_class, 3> my_array;
    
    cout << "one ..." << endl;
    for (auto& o : my_array) o.print();
    
    my_array[0].d = 7.8910;
    my_array[1].i = 5;
    my_array[2].d = 5.5555;
    
    cout << "\n\ntwo ..." << endl;
    for (auto& o : my_array) o.print();
    
    //---- RESETTING THE ARRAY HERE ---//
    /////////////////////////////////////
    my_array.fill(my_class());
    /////////////////////////////////////
    
    cout << "\n\nthree ..." << endl;
    for (auto& o : my_array) o.print();
    
    return 0;
}
