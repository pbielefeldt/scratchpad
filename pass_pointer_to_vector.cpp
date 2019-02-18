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

int main()
{
    my_class* o = new my_class();
    vector<int> my_vector;
    
    // pass by reference
    my_vector = o->get_vector(6);
    
    // test
    for (auto& it : my_vector) cout << it << " ";
    
    delete o;
    return 0;
}
