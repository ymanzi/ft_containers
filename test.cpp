#include <iostream>
#include <list>



int main(void)
{
	std::list<int> l;
	std::list<int>::iterator it;



	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	it = l.begin();
	std::cout << "val =" << *it << std::endl;
	l.insert(l.begin(), 5);
	std::cout << "val =" << *(--it) << std::endl;
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
