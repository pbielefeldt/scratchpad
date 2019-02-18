#include <iostream>
#include <vector>

using namespace std;

class my_class
{
private: 
    vector<int> priv_vector;

public:
    vector<int> &get_vector(unsigned int length)
    {
        priv_vector.clear();        
        for (unsigned int i=0; i<length; i++) priv_vector.push_back(3*i+1);
        return priv_vector;
    }

};

// declare here for all to see
// (would usually rather be in a header file)
vector<int> my_vector;

// some function working on my_vector
void print_function()
{
    for (auto& it : my_vector) cout << it << " ";
    cout << endl;
}

int main()
{
    my_class* o = new my_class();
    
    ///////////////////////
    // pass by reference //
    ///////////////////////
    my_vector = o->get_vector(6);  // !
    print_function();
    
    // and again
    cout << "#########" << endl; 
    my_vector = o->get_vector(4); // !
    print_function();
    
    delete o;
    return 0;
}
