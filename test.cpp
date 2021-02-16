#include "main_header.hpp"
#include <typeinfo>

int main(void)
{
	ft::is_not_iterator<ft::map<int, int>::iterator> lol;
	// ft::is_not_iterator< std::map<int, int>::iterator > lol;
	std::cout << ft::is_not_iterator< std::map<int, int>::iterator >::value() << std::endl;
}