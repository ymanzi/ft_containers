#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
#include "vector.hpp"
#include <string>
#include "map.hpp"
#include <map>

#define P(x) std::cout << std::boolalpha << x << std::endl
#define A(x, y) std::cout << std::boolalpha << x << y << std::endl

template< class T>
void	show_list(T& l)
{
	std::cout << "List =( ";
	for (typename T::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << ", ";
	std::cout << ")" << std::endl;
}


int main(void)
{
	ft::map<int, int> lol;
	for (int i = 0; i < 5; i++)
		lol[i] = i;

	ft::map<int, int>::reverse_iterator it = lol.rbegin();
	lol[4] = 18;
	for ( ; it != lol.rend(); it++)
		std::cout << it->first << " " << (*it).second << std::endl;
}


