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

void t_stack(void)
{
	ft::stack<int>	s;
	ft::stack<int>	s2;

	P("-------------- STACK ------------------");
	P("---------> empty <----");
	
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---------> push (5) <----");
	s.push(5);
	A("top = ", s.top());
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---------> pop <----");
	s.pop();
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("------------------> S(42) and S2(42, 18) <-------------");
	s2.push(42);
	s2.push(18);
	s.push(42);


	P("---------> operator == <----");
	A("operator '==' : ", (s == s2));

	P("---------> operator != <----");
	A("operator '!=' : ", (s != s2));

	P("---------> operator < <----");
	A("operator '<' : ", (s < s2));

	P("---------> operator <= <----");
	A("operator '<=' : ", (s <= s2));

	P("---------> operator > <----");
	A("operator '>' : ", (s > s2));

	P("---------> operator >= <----");
	A("operator '>=' : ", (s >= s2));
}
void t_queue(void)
{
	ft::queue<int>	s;
	ft::queue<int>	s2;

	P("-------------- QUEUE ------------------");
	P("---------> empty <----");
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---------> push (5) (-7) <----");
	s.push(5);
	s.push(-7);
	A("empty ? ", s.empty());
	A("size = ", s.size());
	A("front = ", s.front());
	A("back = ", s.back());

	P("---------> pop <----");
	s.pop();
	A("empty ? ", s.empty());
	A("size = ", s.size());
	A("front = ", s.front());
	A("back = ", s.back());

	P("------------------> S(42) and S2(42, 18) <-------------");
	s2.push(42);
	s2.push(18);
	s.push(42);


	P("---------> operator == <----");
	A("operator '==' : ", (s == s2));

	P("---------> operator != <----");
	A("operator '!=' : ", (s != s2));

	P("---------> operator < <----");
	A("operator '<' : ", (s < s2));

	P("---------> operator <= <----");
	A("operator '<=' : ", (s <= s2));

	P("---------> operator > <----");
	A("operator '>' : ", (s > s2));

	P("---------> operator >= <----");
	A("operator '>=' : ", (s >= s2));
}
void t_list(void)
{
	ft::list<int>	s, s2;
	
	P("-------------- LIST ------------------");
	P("---------> empty <----");
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---------> push_front (42) (10) <----");
	s.push_front(10);
	s.push_front(42);
	show_list(s);
	A("empty ? ", s.empty());
	A("size = ", s.size());
	A("front = ", s.front());
	A("back = ", s.back());

	P("---------> push_back (42) (10) (5) (20) <----");
	
	s.push_back(5);
	s.push_back(20);
	s2 = s;
	show_list(s);
	A("size = ", s.size());

	P("---------> pop_front  (10) (5) (20) <----");
	s.pop_front();
	show_list(s);

	P("---------> pop_back  (10) (5) <----");
	s.pop_back();
	show_list(s);
	A("front = ", s.front());
	A("back = ", s.back());

	P("---------> remove (5) <----");
	s.remove(5);
	show_list(s);
	A("size = ", s.size());

	P("---------> resize (10) <----");
	s.resize(10);
	A("size = ", s.size());

	P("---------> resize (0) <----");
	s.resize(0);
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---------> sort-merge (5) (10) (20) (42) <----");
	s2.sort();
	s.merge(s2);
	show_list(s);
	
	P("---------> erase (10) and (20) : (5) (42) <----");
	ft::list<int>::iterator it, it2;
	it = s.begin();
	it++;
	it2 = it;
	it2++;
	++it2;
	s.erase(it, it2);
	show_list(s);

	P("---------> reverse (42) (5) <----");
	s.reverse();
	show_list(s);

	P("---------> splice (42) (5) (10) <----");
	s.splice(s.end(), s2, ++(s2.begin()));
	show_list(s);

	P("---------> swap (5) (10) (20) (42) <----");
	s.swap(s2);
	show_list(s);
	A("size = ", s.size());

	P("---------> insert (5) (10) (20) (20)  (10) (42) (42) <----");
	it = s.begin();
	it++;
	it++;
	s.insert(it, 20);
	it++;
	s.insert(it, 10);
	s.insert(it, 42);
	show_list(s);
	
	P("---------> unique (5) (10) (20) (10) (42) <----");
	s.unique();
	show_list(s);

	P("---------> reverse_iterator (42) (10) (20) (10) (5) <----");
	std::cout << "List =[ ";
	for (ft::list<int>::reverse_iterator it3 = s.rbegin(); it3 != s.rend(); it3++)
		std::cout << *it3 <<  " ";
	std::cout << "]" << std::endl;

	P("---------> clear <----");
	show_list(s);
	show_list(s2);
	s2.clear();
	s.clear();
	A("empty ? ", s.empty());
	A("size = ", s2.size());

	P("------------------> S(42) and S2(18, 42) <-------------");
	s2.push_back(42);
	s2.push_front(18);
	s.push_front(42);

	P("---------> operator == <----");
	A("operator '==' : ", (s == s2));

	P("---------> operator != <----");
	A("operator '!=' : ", (s != s2));

	P("---------> operator < <----");
	A("operator '<' : ", (s < s2));

	P("---------> operator <= <----");
	A("operator '<=' : ", (s <= s2));

	P("---------> operator > <----");
	A("operator '>' : ", (s > s2));

	P("---------> operator >= <----");
	A("operator '>=' : ", (s >= s2));
}
void t_vector(void)
{
	ft::vector<int>	s, s2;
	
	P("-------------- VECTOR ------------------");
	P("---------> empty <----");
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---------> push_back (42) (10) (5) (20) <----");
	
	s.push_back(5);
	s.push_back(20);
	s2 = s;
	show_list(s);
	A("size = ", s.size());

	P("---------> pop_front  (10) (5) (20) <----");
	s.pop_front();
	show_list(s);

	P("---------> pop_back  (10) (5) <----");
	s.pop_back();
	show_list(s);
	A("front = ", s.front());
	A("back = ", s.back());

	P("---------> resize (10) <----");
	s.resize(10);
	A("size = ", s.size());

	P("---------> resize (0) <----");
	s.resize(0);
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---------> erase (10) and (20) : (5) (42) <----");
	ft::vector<int>::iterator it, it2;
	it = s.begin();
	it++;
	it2 = it;
	it2++;
	++it2;
	s.erase(it, it2);
	show_list(s);

	P("---------> swap (5) (10) (20) (42) <----");
	s.swap(s2);
	show_list(s);
	A("size = ", s.size());

	P("---------> insert (5) (10) (20) (20)  (10) (42) (42) <----");
	it = s.begin();
	it++;
	it++;
	s.insert(it, 20);
	it++;
	s.insert(it, 10);
	s.insert(it, 42);
	show_list(s);
	
	P("---------> at <----");
	show_list(s);
	for (size_t i = 0; i < s.size(); i++)
		std::cout << "[" << i << "] = " << s.at(i) << " ";
	std::cout << std::endl;

	P("---------> reverse_iterator (42) (10) (20) (10) (5) <----");
	std::cout << "List =[ ";
	for (ft::vector<int>::reverse_iterator it3 = s.rbegin(); it3 != s.rend(); it3++)
		std::cout << *it3 <<  " ";
	std::cout << "]" << std::endl;

	P("---------> clear <----");
	show_list(s);
	show_list(s2);
	s2.clear();
	s.clear();
	A("empty ? ", s.empty());
	A("size = ", s2.size());
	A("max_size = ", s2.max_size());

	P("------------------> S(42) and S2(18, 42) <-------------");
	s2.push_back(42);
	s2.push_back(18);
	s.push_back(42);

	P("---------> operator == <----");
	A("operator '==' : ", (s == s2));

	P("---------> operator != <----");
	A("operator '!=' : ", (s != s2));

	P("---------> operator < <----");
	A("operator '<' : ", (s < s2));

	P("---------> operator <= <----");
	A("operator '<=' : ", (s <= s2));

	P("---------> operator > <----");
	A("operator '>' : ", (s > s2));

	P("---------> operator >= <----");
	A("operator '>=' : ", (s >= s2));
}

int main(void)
{
	//t_stack();
	//t_queue();
	//t_list();
	t_vector();
	return (0);
}