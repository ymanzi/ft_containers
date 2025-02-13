#include "list.hpp"
#include <list>
#include <string>

#define P(x) std::cout << std::boolalpha << x << std::endl
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define NC "\e[0m"

template <class T>
std::string verif(T elem)
{
	std::string value;
	if (elem)
		return (" Verif: " GRN " [O.K]" NC);
	else
		return (" Verif: " RED " [K.0]" NC);
}

template< class T>
void	show_container(T& l)
{
	std::cout << "Container =( ";
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
bool	compare_container(T & t, K & k)
{
	(void)t;
	(void)k;
	typename T::iterator it = t.begin();
	typename K::iterator jt = k.begin();

	if (t.size() == 0 && t.size() == k.size())
		return (true);
	else if (t.size() == 0)
		return (false);
	for ( ;it != t.end() && jt != k.end(); it++)
	{
		if (*it != *jt)
			return (false);
		jt++;
	}
	return (true);
}

template <class T, class K>
bool	compare_map(T & t, K & k)
{
	(void)t;
	(void)k;
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

void t_list(void)
{
	ft::list<std::string>	f;
	std::list<std::string>	s;
	
	P("~~~~~~~~~~~~~~~ LIST ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> push_front <----");
	s.push_front("one");
	s.push_front("two");
	s.push_front("three");
	s.push_front("four");

	f.push_front("one");
	f.push_front("two");
	f.push_front("three");
	f.push_front("four");
	// show_container(f);
	P(verif( compare_container(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> push_back <----");
	s.push_back("un");
	s.push_back("deux");
	s.push_back("trois");
	s.push_back("quatre");
	s.push_back("un");
	s.push_back("deux");
	s.push_back("trois");
	s.push_back("quatre");

	f.push_back("un");
	f.push_back("deux");
	f.push_back("trois");
	f.push_back("quatre");
	f.push_back("un");
	f.push_back("deux");
	f.push_back("trois");
	f.push_back("quatre");
	// show_container(f);
	P(verif( compare_container(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Front <----");
	P("front = " << s.front() << verif(s.front() == f.front()) );

	P("---------> Back <----");
	P("Back = " << s.back() << verif(s.back() == f.back()) );

	P("---------> Iterator constructor <----");
	ft::list<std::string>	f2(f.begin(), f.end());
	std::list<std::string>	s2(s.begin(), s.end());

	P(verif( compare_container(s2, f2) ));
	P("---------> Pop_Front <----");
	s.pop_front();
	f.pop_front();
	P(verif( compare_container(s, f) ));

	P("---------> Pop_Back <----");
	s.pop_back();
	f.pop_back();
	P(verif( compare_container(s, f) ));

	P("---------> remove <----");
	s.remove("trois");
	s.remove("three");
	f.remove("trois");
	f.remove("three");
	P(verif( compare_container(s, f) ));
	
	P("---------> resize (10) <----");
	s.resize(10);
	f.resize(10);
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> resize (5) <----");
	s.resize(5);
	f.resize(5);
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> sort <----");
	s.sort();
	f.sort();
	P(verif( compare_container(s, f) ));

	P("---------> merge <----");
	s2.sort();
	f2.sort();
	s.merge(s2);
	f.merge(f2);
	P(verif( compare_container(s, f) ));
	P(verif(compare_container(s2, f2)));
	
	P("---------> erase <----");
	ft::list<std::string>::iterator fi, fi2;
	std::list<std::string>::iterator si, si2;

	si = s.begin();
	si++;
	si2 = si;
	si2++;
	s.erase(si, si2);

	fi = f.begin();
	fi++;
	fi2 = fi;
	fi2++;
	f.erase(fi, fi2);

	P(verif( compare_container(s, f) ));
	P("---------> reverse <----");
	s.reverse();
	f.reverse();
	P(verif( compare_container(s, f) ));

	P("---------> splice <----");
	s2.push_back("trois");
	s2.push_back("quatre");
	f2.push_back("trois");
	f2.push_back("quatre");

	s.splice(s.begin(), s2, ++s2.begin());
	f.splice(f.begin(), f2, ++f2.begin());
	P(verif(compare_container(s, f)));
	P(verif(compare_container(s2, f2)));

	P("---------> swap  <----");
	s.swap(s2);
	f.swap(f2);
	P(verif(compare_container(s, f)));
	P(verif(compare_container(s2, f2)));

	P("---------> insert <----");
	si = s.begin();
	si++;
	++si;
	s.insert(si, "lol2");
	s.insert(si, "lol2");
	s.insert(si, "lol2");
	si++;
	s.insert(si, "lol1");
	s.insert(si, "lol1");
	s2.insert(s2.begin(), s.begin(), si);

	fi = f.begin();
	fi++;
	++fi;
	f.insert(fi, "lol2");
	f.insert(fi, "lol2");
	f.insert(fi, "lol2");
	fi++;
	f.insert(fi, "lol1");
	f.insert(fi, "lol1");
	f2.insert(f2.begin(), f.begin(), fi);
	P(verif(compare_container(s, f)));
	P(verif(compare_container(s2, f2)));
	
	P("---------> unique <----");
	s.sort();
	f.sort();
	s.unique();
	f.unique();
	P(verif( compare_container(s, f) ));
	
	P("---------> reverse_iterator <----");
	ft::list<std::string>::reverse_iterator fi3 = f.rbegin();
	std::list<std::string>::reverse_iterator si3 = s.rbegin();
	bool good = true;
	for (; si3 != s.rend(); si3++)
	{
		if (*si3 != *fi3)
			good = false;
		fi3++;
	}
	P("Reverse Iterator" << verif(good));

	P("---------> clear <----");
	f.clear();
	s.clear();
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> operator == <----");
	P("operator '==' : " << (s == s2) << verif((s == s2) == (f == f2)));

	P("---------> operator != <----");
	P("operator '!=' : " << (s != s2) << verif((s != s2) == (f != f2)));

	P("---------> operator < <----");
	P("operator '<' : " << (s < s2) << verif((s < s2) == (f < f2)));

	P("---------> operator <= <----");
	P("operator '<=' : " << (s <= s2) << verif((s <= s2) == (f <= f2)));

	P("---------> operator > <----");
	P("operator '>' : " << (s > s2) << verif((s > s2) == (f > f2)));

	P("---------> operator >= <----");
	P("operator '>=' : " << (s >= s2) << verif((s >= s2) == (f >= f2)));
}

int main(void)
{
	t_list();
	// system("leaks a.out");

	return (0);
}