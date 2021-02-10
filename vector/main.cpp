#include "vector.hpp"
#include <vector>
#include <string>
#include "../utils/test.hpp"

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
	show_container(s);
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
	show_container(s);

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
	show_container(s);
	show_container(r);
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
	show_container(s);
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
	show_container(s);
	
	P("---------> at <----");
	show_container(s);
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
	show_container(s);
	show_container(s2);
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

int main(void)
{
	// t_vector();

	std::vector<int> b;
	ft::vector<int> a;

	constructor_t(a, b);
	assign_t(a, b);
	at_t(a, b);
	back_t(a, b);
	capacity_t(a, b);
	clear_empty_t(a, b);
	erase_t(a, b);
	front_t(a, b);
	insert_t(a, b);
	operator_at_t(a, b);
	pop_back_t(a, b);
	push_back_t(a, b);
	re_size_t(a, b);
	swap_t(a, b);
	iterator_t(a, b);
	r_iterator_t(a, b);
	comp_t(a, b);
	iterator_comp_t(a, b);
	r_iterator_comp_t(a, b);
	P("Vector Test Finished: If you have no error, everything is Good, otherwhise.....");
	return (0);
}