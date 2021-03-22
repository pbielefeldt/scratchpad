#include <iostream>
#include <vector>

/* Fill a vector of vectors with a number
 * 
g++ -Wall -o fill_vector.o fill_vector.cpp 
 */
 
 using namespace std;
 
template<typename T, typename A>
void fill_the_vector(std::vector< std::vector<T,A> >& vec, double start=1, double inc=1)
{	
	for (auto& elem : vec)
	{
//		fill(elem.begin(), elem.end(), static_cast<T>(start));
		double x = start;
		for (auto& i : elem)
		{
			i = static_cast<T>(x);
			x += inc;
		}
	}
} 


int main()
{
//	vector< vector<double> > my_vector;
	vector< vector<int> >    my_vector;
	 	
//	my_vector.resize(5, vector<double>(6));
	my_vector.resize(4, vector<int>(11));
	
	fill_the_vector(my_vector, 3.1, 0.3);
	
	for (const auto& it : my_vector)
	{
		cout << "\n" << endl;
		int i = 0;
		for (const auto& l : it)
		{
			cout << i++ << ": " << l << endl;
		}
	}
	 	
	return 0;
}
