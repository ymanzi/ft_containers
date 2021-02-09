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

template< class T>
void	show_map(T& l)
{
	std::cout << "Map =( ";
	for (typename T::iterator it = l.begin(); it != l.end(); it++)
		std::cout << it->first << " - " << it->second << " << ";
	std::cout << ")" << std::endl;
}

int main(void)
{
	ft::map<int, int> lol;
	for (int i = 0; i < 5; i++)
		lol.insert( std::pair<int, int>(i*i, i) );
	lol.insert( std::pair<int, int>(5, 18) );

	ft::map<int, int> lol2(lol.begin(), lol.end());

	ft::map<int, int>lol3(lol2);
	ft::map<int, int>lol4(lol3);

	P("size: " << lol2.size() << lol2.end()->first);
	show_map(lol);
	show_map(lol2);
	show_map(lol3);
}


