#include "stack.hpp"
#include "map.hpp"
#include "queue.hpp"
#include "list.hpp"
#include "vector.hpp"
#include <list>
#include <vector>
#include <map>
#include <string>

#define P(x) std::cout << std::boolalpha << x << std::endl

template< class T>
void	show_list(T& l)
{
	std::cout << "List =( ";
	for (typename T::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " << ";
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

template <class T, class K>
bool	compare_map(T & t, K & k)
{
	typename T::iterator it = t.begin();
	typename K::iterator jt = k.begin();

	for ( ;it != t.end() && jt != k.end(); it++)
	{
		if (it->first != jt->first || it->second != jt->second)
			return (false);
		jt++;
	}
	return (true);
}

void t_stack(void)
{
	ft::stack<int>	s;
	ft::stack<int>	s2;

	P("-------------- STPCK ------------------");
	P("---------> empty <----");
	P("empty ? " << s.empty());
	P("size = " << s.size());

	P("---------> push (5) <----");
	s.push(5);
	P("top = " << s.top());
	P("empty ? " << s.empty());
	P("size = " << s.size());

	P("---------> pop <----");
	s.pop();
	P("empty ? " << s.empty());
	P("size = " << s.size());

	P("------------------> S(42) and S2(42, 18) <-------------");
	s2.push(42);
	s2.push(18);
	s.push(42);


	P("---------> operator == <----");
	P("operator '==' : " << (s == s2));

	P("---------> operator != <----");
	P("operator '!=' : " << (s != s2));

	P("---------> operator < <----");
	P("operator '<' : " << (s < s2));

	P("---------> operator <= <----");
	P("operator '<=' : " << (s <= s2));

	P("---------> operator > <----");
	P("operator '>' : " << (s > s2));

	P("---------> operator >= <----");
	P("operator '>=' : " << (s >= s2));
}
void t_queue(void)
{
	ft::queue<int>	s;
	ft::queue<int>	s2;

	P("-------------- QUEUE ------------------");
	P("---------> empty <----");
	P("empty ? " << s.empty());
	P("size = " << s.size());

	P("---------> push (5) (-7) <----");
	s.push(5);
	s.push(-7);
	P("empty ? " << s.empty());
	P("size = " << s.size());
	P("front = " << s.front());
	P("back = " << s.back());

	P("---------> pop <----");
	s.pop();
	P("empty ? " << s.empty());
	P("size = " << s.size());
	P("front = " << s.front());
	P("back = " << s.back());

	P("------------------> S(42) and S2(42, 18) <-------------");
	s2.push(42);
	s2.push(18);
	s.push(42);


	P("---------> operator == <----");
	P("operator '==' : " << (s == s2));

	P("---------> operator != <----");
	P("operator '!=' : " << (s != s2));

	P("---------> operator < <----");
	P("operator '<' : " << (s < s2));

	P("---------> operator <= <----");
	P("operator '<=' : " << (s <= s2));

	P("---------> operator > <----");
	P("operator '>' : " << (s > s2));

	P("---------> operator >= <----");
	P("operator '>=' : " << (s >= s2));
}
void t_list(void)
{
	ft::list<int>	s, s2;
	std::list<int>  r, r2;
	
	P("-------------- LIST ------------------");
	P("---------> empty <----");
	P("empty ? " << s.empty());
	P("size = " <<  s.size());

	P("---------> push_front (42) (10) <----");
	s.push_front(10);
	s.push_front(42);
	show_list(s);
	P("empty ? " << s.empty());
	P("size = " << s.size());
	P("front = " << s.front());
	P("back = " << s.back());

	P("---------> push_back (42) (10) (5) (20) <----");
	
	s.push_back(5);
	s.push_back(20);
	s2 = s;
	show_list(s);
	P("size = " << s.size());

	P("---------> pop_front  (10) (5) (20) <----");
	s.pop_front();
	show_list(s);

	P("---------> pop_back  (10) (5) <----");
	s.pop_back();
	show_list(s);
	P("front = " << s.front());
	P("back = " << s.back());

	P("---------> remove (5) <----");
	s.remove(5);
	show_list(s);
	P("size = " << s.size());

	P("---------> resize (10) <----");
	s.resize(10);
	P("size = " << s.size());

	P("---------> resize (0) <----");
	s.resize(0);
	P("empty ? " << s.empty());
	P("size = " << s.size());

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
	P("size = " << s.size());

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
	P("empty ? " << s.empty());
	P("size = " << s2.size());

	P("------------------> S(42) and S2(18, 42) <-------------");
	s2.push_back(42);
	s2.push_front(18);
	s.push_front(42);

	P("---------> operator == <----");
	P("operator '==' : " << (s == s2));

	P("---------> operator != <----");
	P("operator '!=' : " << (s != s2));

	P("---------> operator < <----");
	P("operator '<' : " << (s < s2));

	P("---------> operator <= <----");
	P("operator '<=' : " << (s <= s2));

	P("---------> operator > <----");
	P("operator '>' : " << (s > s2));

	P("---------> operator >= <----");
	P("operator '>=' : " << (s >= s2));
}
void t_vector(void)
{
	ft::vector<int>	s, s2;
	std::vector<int> r, r2;
	
	P("-------------- VECTOR ------------------");
	{
		
	}
	P("---------> empty <----");
	P("empty ? " << (s.empty() == r.empty()) );
	P("size = " << ((s.size() == r.size()) ));

	P("---------> push_back (5) (20) <----");
	s.push_back(5);
	r.push_back(5);
	s.push_back(20);
	r.push_back(20);
	s2 = s;
	r2 = r;
	show_list(s);
	P("size ? " << (s.size() == r.size()) );
	P("Operator= ? " << (s2.size() == r2.size() ));

	P("---------> pop_back (5) (10) (20) <----");
	s.pop_back();
	r.pop_back();
	P("front ? " << (s.front() == r.front()) );
	P("back ? " << (s.back() == r.back()));
	s.push_back(10);
	r.push_back(10);
	s.push_back(20);
	r.push_back(20);
	show_list(s);

	P("---------> resize (10) <----");
	s.resize(10);
	r.resize(10);
	P("size ? " << (s.size() == r.size()));
	P("size = " << s.size());

	P("---------> resize (0) <----");
	s.resize(0);
	r.resize(0);
	P("empty ? " << (s.empty() == r.empty()) );
	P("size ? " << (s.size() == r.size()));

	s.push_back(5);
	s.push_back(10);
	s.push_back(20);
	s.push_back(42);
	r.push_back(5);
	r.push_back(10);
	r.push_back(20);
	r.push_back(42);
	P("---------> erase (10) and (20) : (5) (42) <----");
	show_list(s);
	show_list(r);
	ft::vector<int>::iterator it, it2;
	it = s.begin();
	it++;
	it2 = it;
	it2++;
	it2++;
	s.erase(it, it2);

	std::vector<int>::iterator jt, jt2;
	jt = r.begin();
	jt++;
	jt2 = jt;
	jt2++;
	jt2++;
	r.erase(jt, jt2);

	P(" Verif ? " << (s.size() == r.size() && s.front() == r.front() && s.back() == r.back()) );
	P("---------> swap (5) (20) <----");
	s.swap(s2);
	r.swap(r2);
	show_list(s);
	P(" Verif ? " << (s.size() == r.size() && s.front() == r.front() && s.back() == r.back()) );

	P("---------> insert (42) (20) (10) (5) (20) <----");
	it = s.begin();
	s.insert(it, 20);
	it = ++(s.begin());
	s.insert(it, 10);
	it = s.begin();
	s.insert(it, 42);

	jt = r.begin();
	r.insert(jt, 20);
	jt = ++(r.begin());
	r.insert(jt, 10);
	jt = r.begin();
	r.insert(jt, 42);

	P(" Verif ? " << (s.size() == r.size() && s.front() == r.front() && s.back() == r.back()) );
	show_list(s);
	
	P("---------> at <----");
	show_list(s);
	for (size_t i = 0; i < s.size(); i++)
		std::cout << "[" << i << "] = " << s.at(i) << " ";
	std::cout << std::endl;
	std::cout << "verif ? ";
	for (size_t i = 0; i < s.size(); i++)
		std::cout << "[" << i << "] = " << (s.at(i) == r.at(i)) << " ";
	std::cout << std::endl;
	P("---------> reverse_iterator (20) (5) (10) (20) (42) <----");
	std::cout << "List =[ ";
	for (ft::vector<int>::reverse_iterator it3 = s.rbegin(); it3 != s.rend(); it3++)
		std::cout << *it3 <<  " ";
	std::cout << "]" << std::endl;
	P("---------> clear <----");
	show_list(s);
	show_list(s2);
	s2.clear();
	r2.clear();
	s.clear();
	r.clear();
	P("empty ? " << s.empty());
	P("size = " << s2.size());
	P("max_size = " << s2.max_size());

	P("------------------> S(42) and S2(18, 42) <-------------");
	s2.push_back(42);
	r2.push_back(42);
	s2.push_back(18);
	r2.push_back(18);
	s.push_back(42);
	r.push_back(42);

	P("---------> operator == <----");
	P("operator '==' : " << ((s == s2) == (r == r2)) );

	P("---------> operator != <----");
	P("operator '!=' : " << ((s != s2) == (r != r2)) );

	P("---------> operator < <----");
	P("operator '<' : " << ((s < s2) == (r < r2)) );

	P("---------> operator <= <----");
	P("operator '<=' : " << ((s <= s2) == (r <= r2)) );

	P("---------> operator > <----");
	P("operator '>' : " << ((s > s2) == (r > r2)) );

	P("---------> operator >= <----");
	P("operator '>=' : " << ((s >= s2) == (r >= r2)) );
}

void t_map(void)
{
	ft::map<int, int>	s, s2;
	std::map<int, int>  r, r2;

	ft::map<int, int>::iterator	it, it2;
	std::map<int, int>::iterator  jt, jt2;
	
	P("-------------- MAP ------------------");
	P("---------> empty <----");
	P("empty ? " << s.empty());
	P("size = " <<  s.size());

	P("---------> Insert <----");
	for (int i = 0; i < 5; i++)
	{
		s.insert(std::pair<int, int>(i, i*i));
		r.insert(std::pair<int, int>(i, i*i));
	}
	show_map(s);
	P("Verif ? " << compare_map(s, r) );
	P("Size ? " << (s.size() == r.size()) );

	P("---------> Count <----");
	P("Count (exist)? " << (s.count(2) == r.count(2) ) );
	P("Count (doesn't exist)? " << (s.count(42) == r.count(42) ) );
	
	P("---------> Equal range <----");
	std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> a1 = s.equal_range(2);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> b1 = r.equal_range(2);

	P("Verif? " << ((a1.first->first == b1.first->first && a1.first->second == b1.first->second && 
		a1.second->first == b1.second->first && a1.second->second == b1.second->second)));
	P("---------> Erase <----");
	s2 = s;
	r2 = r;
	s2.erase(2);
	r2.erase(2);
	P("Verif?" << compare_map(s2, r2));

	s2 = s;
	r2 = r;
	s2.erase(s2.begin());
	r2.erase(r2.begin());
	P("Verif?" << compare_map(s2, r2));

	s2 = s;
	r2 = r;
	it = s2.begin();
	jt = r2.begin();
	s2.erase(it, ++it);
	r2.erase(jt, ++jt);
	P("Verif?" << compare_map(s2, r2));

	P("---------> Find <----");
	P("Find (exist)? " << (s.find(2)->first == r.find(2)->first && s.find(2)->second == r.find(2)->second) );
	P("Find (doesn't exist)? " << (s.find(42) == s.end() ) );

	{
		P("---------> Key_comp (100)(200)(300) <----");
		ft::map<char,int> mymap;

		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
	}

	P("---------> Lower_bound <----");
	it = s.lower_bound(3);
	jt = r.lower_bound(3);

	P("Verif? " << ((it->first == jt->first && it->second == jt->second)));
	P("---------> Upper_bound <----");
	it = s.upper_bound(3);
	jt = r.upper_bound(3);

	P("Verif? " << ((it->first == jt->first && it->second == jt->second)));
	P("---------> operator[] <----");
	std::cout << "Verif? ";
	for (size_t i = 0; i < s.size(); i++)
		std::cout << (s[i] == r[i]) << " ";
	std::cout << std::endl;

	P("---------> swap (5) (10) (20) (42) <----");

	s2.clear();
	r2.clear();

	for (int i = 10; i < 20; i++)
	{
		s2.insert(std::pair<int, int>(i, i*i));
		r2.insert(std::pair<int, int>(i, i*i));
	}

	s.swap(s2);
	r.swap(r2);
	
	P("Verif? " << compare_map(s, r));
	P("Verif? " << compare_map(s2, r2));
	P("---------> reverse_iterator <----");
	std::cout << "Ft::Map =[ ";
	for (ft::map<int, int>::reverse_iterator it3 = s.rbegin(); it3 != s.rend(); it3++)
		std::cout << it3->first <<  "-" << it3->second << "  ";
	std::cout << "]" << std::endl;

	std::cout << "Std::Map =[ ";
	for (std::map<int, int>::reverse_iterator it3 = r.rbegin(); it3 != r.rend(); it3++)
		std::cout << it3->first <<  "-" << it3->second << "  ";
	std::cout << "]" << std::endl;

	P("---------> clear <----");
	s2.clear();
	r2.clear();
	s.clear();
	r.clear();
	P("empty ? " << s.empty());
	P("size = " << s2.size());
	P("------------------> Operator <-------------");
	for (int i = 0; i < 5; i++)
	{
		s.insert(std::pair<int, int>(i, i*i));
		r.insert(std::pair<int, int>(i, i*i));
	}
	for (int i = 0; i < 3; i++)
	{
		r2.insert(std::pair<int, int>(i, i*i));
		s2.insert(std::pair<int, int>(i, i*i));
	}
	P("---------> operator == <----");
	P("operator '==' : " << ((s == s2) == (r == r2)));

	P("---------> operator != <----");
	P("operator '!=' : " << ((s != s2) == (r != r2)));

	P("---------> operator < <----");
	P("operator '<' : " << ((s < s2) == (r < r2)));

	P("---------> operator <= <----");
	P("operator '<=' : " << ((s <= s2) == (r <= r2)));

	P("---------> operator > <----");
	P("operator '>' : " << ((s > s2) == (r > r2)));

	P("---------> operator >= <----");
	P("operator '>=' : " << ((s >= s2) == (r >= r2)));
}

int main(void)
{
	//t_stack();
	//t_queue();
	//t_list();
	//t_vector();
	//t_map();
	return (0);
}