#include <iostream>


/*
g++ -Wall -o strings.o test_strings.cpp 
*/

int main()
{
	std::string str_a;
	str_a = "";
	
//	std::string str_b;
//	str_b = nullptr; 	// → causes a seg vault, see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3690.pdf#subsection.21.4.2
	
	std::string str_c = "";
	std::string str_d;
	
	//---- ----//
	if (str_a.empty()) std::cout << "no a" << std::endl;
//	if (str_b.empty()) std::cout << "no b" << std::endl;
	if (str_c.empty()) std::cout << "no c" << std::endl;
	if (str_d.empty()) std::cout << "no d" << std::endl;
}
