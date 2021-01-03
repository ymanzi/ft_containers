#include <iostream>
#include "list.hpp"
#include <list>
#include <string>

int main(void)
{
	ft::list<std::string> l;
	ft::list<std::string>::iterator it, it2;

	std::list<std::string> l2;
	std::list<std::string>::iterator it3, it4;


	l.push_back("10");
	l.push_back("20");

	l2.push_back("10");
	l2.push_back("20");
/*	l.push_back(3);
	l.push_back(4);
*/
	it = l.begin();
	it2 = l.begin();
	l.pop_front();

	l2.resize(10);
	std::cout << "val =" << l2.size() << std::endl;
//	l.insert(l.begin(), 5);
//	std::cout << "val =" << *(--it) << std::endl;
	// std::cout << "it =" << (it == l.begin()) << std::endl;
	// std::cout << "begin =" << *(l.end()) << std::endl;

/*
	std::list<int>::iterator it2 = l.begin();
	it2++;
	std::list<int>::reverse_iterator it3(it2);


	it = l.rbegin();
//	it -= 2;
	std::cout << "val =" << *it3 << std::endl;
	// it++;
	std::cout << "val =" << *it2 << std::endl;
*/	// it++;
	// std::cout << "val =" << *it << std::endl;
	// it++;
	// std::cout << "val =" << *it << std::endl;
	// it++;
	// std::cout << "val =" << *it << std::endl;
}
