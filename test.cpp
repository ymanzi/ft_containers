#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
#include "vector.hpp"
#include <string>

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
	ft::list<int> l(3, -10);

	//for (int i = 0; i < 10; i++)
	//	l.push_back(i);
	ft::list<int> l2(l.begin(), l.end());

	P("---------> operator == <----");
	A("operator '==' : ", (l == l2));
	show_list(l2);


}


