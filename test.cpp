#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
#include "vector.hpp"
#include <string>
#include "map.hpp"
#include <list>
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
	ft::list<int> lol;
	ft::list<int>::iterator it = lol.begin();
	//for (int i = 1; i < 5; i++)
		lol.insert(it, 5, 2);
	lol.insert(it, lol.begin(), lol.end());
	// ft::list<int>::iterator it = lol.begin();
	
	// for (int i = 0; i < 10; i++)
	// 	P(*it++);
	// P("NXT");
	// for (int i = 0; i < 10; i++)
	// 	P(*it--);
	// for (int i = 0; i < 3; i++)
	// 	P(*it--);	
	P("size: " << lol.size() );
	// show_list(lol);
}


