#include "main_header.hpp"
#include <typeinfo>

int main(void)
{
	ft::pair<int, int> lol(5, 5);
	std::pair<int, int> lol2(5, 5);

	ft::map<int, int>::iterator oui;
	P(typeid(oui).name());
}