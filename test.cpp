#include <iostream>
#include <list>

// {
// ft::queue<int>	s;
// 	ft::queue<int>	s2;

// 	P("-------------- QUEUE ------------------");
// 	P("---> empty <----");
	
// 	A("empty ? ", s.empty());
// 	A("size = ", s.size());

// 	P("---> push (5) <----");
// 	s.push(5);
// 	A("top = ", s.top());
// 	A("empty ? ", s.empty());
// 	A("size = ", s.size());

// 	P("---> pop <----");
// 	s.pop();
// 	A("empty ? ", s.empty());
// 	A("size = ", s.size());

// 	P("------------> S(42) and S2(42, 18) <-------------");
// 	s2.push(42);
// 	s2.push(18);
// 	s.push(42);


// 	P("---> operator == <----");
// 	A("operator '==' : ", (s == s2));

// 	P("---> operator != <----");
// 	A("operator '!=' : ", (s != s2));

// 	P("---> operator < <----");
// 	A("operator '<' : ", (s < s2));

// 	P("---> operator <= <----");
// 	A("operator '<=' : ", (s <= s2));

// 	P("---> operator > <----");
// 	A("operator '>' : ", (s > s2));

// 	P("---> operator >= <----");
// 	A("operator '>=' : ", (s >= s2));
// }

int main(void)
{
	std::list<int> l;
	std::list<int>::reverse_iterator it;



	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	std::list<int>::iterator it2 = l.begin();
	it2++;
	std::list<int>::reverse_iterator it3(it2);


	it = l.rbegin();
//	it -= 2;
	std::cout << "val =" << *it3 << std::endl;
	// it++;
	std::cout << "val =" << *it2 << std::endl;
	// it++;
	// std::cout << "val =" << *it << std::endl;
	// it++;
	// std::cout << "val =" << *it << std::endl;
	// it++;
	// std::cout << "val =" << *it << std::endl;
}
