#include "../main_header.hpp"
#include <string>

#define P(x) std::cout << std::boolalpha << x << std::endl

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

std::string verif(bool elem)
{
	std::string value;
	if (elem)
		value = "1";
	else
		value = "0";
	return (" Verif: " + value);
}

void t_stack(void)
{
	ft::stack<std::string> f;
	ft::stack<std::string> f2;
	std::stack<std::string> s;
	std::stack<std::string> s2;

	P("~~~~~~~~~~~~~~~ STACK ~~~~~~~~~~~~~~~----");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> push <----");
	s.push("one");
	f.push("one");
	P("top = " << s.top() << verif(s.top() == f.top()) );
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> pop <----");
	s.pop();
	f.pop();
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("~~~~~~~~~~~~~~~----> Test Operator <-------------");
	s.push("deux");
	f.push("deux");

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

void t_queue(void)
{
	ft::queue<std::string> f;
	ft::queue<std::string> f2;
	std::queue<std::string> s;
	std::queue<std::string> s2;

	P("~~~~~~~~~~~~~~~ QUEUE ~~~~~~~~~~~~~~~----");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> push - front - back <----");
	s.push("one");
	s.push("two");
	f.push("one");
	f.push("two");
	P("front = " << s.front() << verif(s.front() == f.front()) );
	P("back = " << s.back() << verif(s.back() == f.back()) );
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> pop <----");
	s.pop();
	f.pop();
	P("front = " << s.front() << verif(s.front() == f.front()) );
	P("back = " << s.back() << verif(s.back() == f.back()) );
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("~~~~~~~~~~~~~~~----> Test Operator <-------------");
	s.push("deux");
	f.push("deux");

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

void t_vector(void)
{
	ft::vector<std::string>	 f;
	std::vector<std::string>	s;
	
	P("~~~~~~~~~~~~~~~ VECTOR ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> INSERT <----");
	s.insert(s.begin(), "one");
	s.insert(s.begin(),"two");
	s.insert(s.begin(),"three");
	s.insert(s.begin(),"four");
	f.insert(f.begin(),"one");
	f.insert(f.begin(),"two");
	f.insert(f.begin(),"three");
	f.insert(f.begin(),"four");
	s.insert(s.begin() + 2, 5, "one");
	f.insert(f.begin() + 2, 5, "one");

	s.insert(s.begin(), s.begin() + 2, s.begin() + 5);
	f.insert(f.begin(), f.begin() + 2, f.begin() + 5 );
	P(verif( compare_container(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Constructor <----");
	{
		ft::vector<std::string>	 f2(5, "lol");
		std::vector<std::string>	 s2(5, "lol");
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	{
		ft::vector<std::string>	 f2(f.begin(), f.end());
		std::vector<std::string>	 s2(s.begin(), s.end());
		P("Same container" << verif( compare_container(f2, f) ));
		// show_container(f2);
		// show_container(f);

		P("size = " << f2.size() << verif(f.size() == f2.size()) );
	}

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

	P("---------> Pop_Back <----");
	s.pop_back();
	f.pop_back();
	P(verif( compare_container(s, f) ));

	P("---------> erase <----");
	s.erase(s.begin() + 5);
	s.erase(s.begin() + 1, s.begin() + 3);
	f.erase(f.begin() + 5);
	f.erase(f.begin() + 1, f.begin() + 3);
	P(verif( compare_container(s, f) ));
	
	P("---------> resize (10) <----");
	s.resize(10);
	f.resize(10);
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> resize (5) <----");
	s.resize(5);
	f.resize(5);
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Assign <----");
	{
		ft::vector<std::string>	 f2(f);
		ft::vector<std::string>	 f3;
		std::vector<std::string>	 s2(s);
		std::vector<std::string>	 s3;

		f3.assign(f2.begin(), f2.end());
		s3.assign(s2.begin(), s2.end());
		P(verif( compare_container(s3, f3) ));

		f3.assign(5, "lol");
		s3.assign(5, "lol");
		P(verif( compare_container(s3, f3) ));
	}
	P("---------> at <----");
	{
		bool v = true;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (s.at(i) != f.at(i))
				v = false;
		}
		P(verif(v ));
	}

	P("---------> swap  <----");
	{
		ft::vector<std::string>	 f3;
		std::vector<std::string>	 s3;
		s.swap(s3);
		f.swap(f3);
		P(verif(compare_container(s, f)));
		P(verif(compare_container(s3, f3)));

		swap(s, s3);
		swap(f, f3);
	}
	P("---------> reverse_iterator <----");
	{
		ft::vector<std::string>::reverse_iterator fi3 = f.rbegin();
		std::vector<std::string>::reverse_iterator si3 = s.rbegin();
		bool good = true;
		for (; si3 != s.rend(); si3++)
		{
			if (*si3 != *fi3)
				good = false;
			fi3++;
		}
		P("Reverse Iterator" << verif(good));
	}
	P("---------> clear <----");
	ft::vector<std::string>		f2(f);
	std::vector<std::string>	s2(s);
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

void t_map(void)
{
	ft::map<std::string, std::string>	f;
	std::map<std::string, std::string>	s;
	
	P("~~~~~~~~~~~~~~~ MAP ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> INSERT <----");
	s.insert(std::pair<std::string, std::string>("one", "one") );
	s.insert(std::pair<std::string, std::string>("two", "two") );
	s.insert(s.begin(), std::pair<std::string, std::string>("three", "three") );
	s.insert(s.begin(), std::pair<std::string, std::string>("four", "four") );
	
	f.insert(ft::pair<std::string, std::string>("one", "one") );
	f.insert(ft::pair<std::string, std::string>("two", "two") );
	f.insert(f.begin(), ft::pair<std::string, std::string>("three", "three") );
	f.insert(f.begin(), ft::pair<std::string, std::string>("four", "four") );

	s.insert(s.begin(), s.end());
	f.insert(f.begin(), f.end());
	P(verif( compare_map(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Constructor <----");
	{
		ft::map<std::string, std::string>	 f2(f);
		std::map<std::string, std::string>	 s2(s);
		P("Same container" << verif( compare_map(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	{
		ft::map<std::string, std::string>	 f2(f.begin(), f.end());
		std::map<std::string, std::string>	 s2(s.begin(), s.end());
		P("Same container" << verif( compare_map(f2, f) ));
		// show_container(f2);
		// show_container(f);

		P("size = " << f2.size() << verif(f.size() == f2.size()) );
	}
	P("---------> Operator= <----");
	{
		ft::map<std::string, std::string>	 f2 = f;
		std::map<std::string, std::string>	 s2 = s;
		P("Same container" << verif( compare_map(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	P("---------> Count <----");
	P(verif( (s.count("one") == f.count("one") && s.count("lol") == f.count("lol"))  ));
	
	P("---------> Equal_Range <----");
	{
		std::pair<std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator> si;
		ft::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> fi; 

		si = s.equal_range("three");
		fi = f.equal_range("three");

		P(verif( (si.first->first == fi.first->first && si.first->second == fi.first->second 
		&& si.second->first == fi.second->first && si.second->second == fi.second->second)  ));
	}
	P("---------> Lower_Bound <----");
	{
		std::map<std::string, std::string>::iterator si;
		ft::map<std::string, std::string>::iterator fi;

		si = s.lower_bound("three");
		fi = f.lower_bound("three");

		P(verif( (si->first == fi->first && si->second == fi->second)  ));
	}
	P("---------> Upper_Bound <----");
	{
		std::map<std::string, std::string>::iterator si;
		ft::map<std::string, std::string>::iterator fi;

		si = s.upper_bound("three");
		fi = f.upper_bound("three");

		P(verif( (si->first == fi->first && si->second == fi->second)  ));
	}
	P("---------> Value_Comp <----");
	{
		std::map<std::string, std::string>::iterator si = s.begin();
		ft::map<std::string, std::string>::iterator fi = f.begin();

		P( verif( (s.value_comp()(*si, *++si) == f.value_comp()(*fi, *++fi)) ));
	}

	P("---------> operator[] <----");
	{
		bool v = true;
		std::map<std::string, std::string>::iterator si = s.begin();
		ft::map<std::string, std::string>::iterator fi = f.begin();

		for ( ; si != s.end() ; si++)
		{
			if (s[si->first] != f[fi->first])
				v = false;
			fi++;
		}
		P(verif(v ));
	}

	P("---------> erase <----");
	{
		std::map<std::string, std::string>::iterator si = s.begin();
		ft::map<std::string, std::string>::iterator fi = f.begin();
		s.erase(si++);
		f.erase(fi++);
		si++;
		fi++;

		std::map<std::string, std::string>::iterator si2 = s.begin();
		ft::map<std::string, std::string>::iterator fi2 = f.begin();
		s.erase(si2->first);
		f.erase(fi2->first);

		si2 = s.begin();
		fi2 = f.begin();

		f.erase(fi2, fi);
		s.erase(si2, si);
		P(verif( compare_map(s, f) ));
	}
	P("---------> swap  <----");
	{
		ft::map<std::string, std::string>	 f3;
		std::map<std::string, std::string>	 s3;
		s.swap(s3);
		f.swap(f3);
		P(verif(compare_map(s, f)));
		P(verif(compare_map(s3, f3)));

		swap(s, s3);
		swap(f, f3);
	}
	P("---------> reverse_iterator <----");
	{
		ft::map<std::string, std::string>::reverse_iterator fi3 = f.rbegin();
		std::map<std::string, std::string>::reverse_iterator si3 = s.rbegin();
		bool good = true;
		for (; si3 != s.rend(); si3++)
		{
			if (si3->first != fi3->first || si3->second != fi3->second)
				good = false;
			fi3++;
		}
		P("Reverse Iterator" << verif(good));
	}
	P("---------> clear <----");
	ft::map<std::string, std::string>	f2(f);
	std::map<std::string, std::string>	s2(s);
	
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

void t_multimap(void)
{
	ft::multimap<std::string, std::string>	f;
	std::multimap<std::string, std::string>	s;
	
	P("~~~~~~~~~~~~~~~ MULTIMAP ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> INSERT <----");
	{
		s.insert(std::pair<std::string, std::string>("one", "one") );
		s.insert(std::pair<std::string, std::string>("two", "two") );
		s.insert(s.begin(), std::pair<std::string, std::string>("three", "three") );
		s.insert(s.begin(), std::pair<std::string, std::string>("four", "four") );
		s.insert(std::pair<std::string, std::string>("one", "one") );
		s.insert(std::pair<std::string, std::string>("two", "two") );
		s.insert(s.begin(), std::pair<std::string, std::string>("three", "three") );
		s.insert(s.begin(), std::pair<std::string, std::string>("four", "four") );
		
		f.insert(ft::pair<std::string, std::string>("one", "one") );
		f.insert(ft::pair<std::string, std::string>("two", "two") );
		f.insert(f.begin(), ft::pair<std::string, std::string>("three", "three") );
		f.insert(f.begin(), ft::pair<std::string, std::string>("four", "four") );
		f.insert(ft::pair<std::string, std::string>("one", "one") );
		f.insert(ft::pair<std::string, std::string>("two", "two") );
		f.insert(f.begin(), ft::pair<std::string, std::string>("three", "three") );
		f.insert(f.begin(), ft::pair<std::string, std::string>("four", "four") );

		ft::multimap<std::string, std::string>	f2(f);
		std::multimap<std::string, std::string>	s2(s);

		s.insert(s2.begin(), s2.end());
		f.insert(f2.begin(), f2.end());
		P(verif( compare_map(s, f) ));
		P("size = " << s.size() << verif(s.size() == f.size()) );
	}
	P("---------> Constructor <----");
	{
		ft::multimap<std::string, std::string>	 f2(f);
		std::multimap<std::string, std::string>	 s2(s);
		P("Same container" << verif( compare_map(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	{
		ft::multimap<std::string, std::string>	 f2(f.begin(), f.end());
		std::multimap<std::string, std::string>	 s2(s.begin(), s.end());
		P("Same container" << verif( compare_map(f2, f) ));
		// show_container(f2);
		// show_container(f);

		P("size = " << f2.size() << verif(f.size() == f2.size()) );
	}
	P("---------> Operator= <----");
	{
		ft::multimap<std::string, std::string>	 f2 = f;
		std::multimap<std::string, std::string>	 s2 = s;
		P("Same container" << verif( compare_map(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	P("---------> Count <----");
	P(verif( (s.count("one") == f.count("one") && s.count("lol") == f.count("lol"))  ));
	
	P("---------> Equal_Range <----");
	{
		std::pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> si;
		ft::pair<ft::multimap<std::string, std::string>::iterator, ft::multimap<std::string, std::string>::iterator> fi; 

		si = s.equal_range("three");
		fi = f.equal_range("three");

		P(verif( (si.first->first == fi.first->first && si.first->second == fi.first->second 
		&& si.second->first == fi.second->first && si.second->second == fi.second->second)  ));
	}
	P("---------> Lower_Bound <----");
	{
		std::multimap<std::string, std::string>::iterator si;
		ft::multimap<std::string, std::string>::iterator fi;

		si = s.lower_bound("three");
		fi = f.lower_bound("three");

		P(verif( (si->first == fi->first && si->second == fi->second)  ));
	}
	P("---------> Upper_Bound <----");
	{
		std::multimap<std::string, std::string>::iterator si;
		ft::multimap<std::string, std::string>::iterator fi;

		si = s.upper_bound("three");
		fi = f.upper_bound("three");

		P(verif( (si->first == fi->first && si->second == fi->second)  ));
	}
	P("---------> Value_Comp <----");
	{
		std::multimap<std::string, std::string>::iterator si = s.begin();
		ft::multimap<std::string, std::string>::iterator fi = f.begin();

		P( verif( (s.value_comp()(*si, *++si) == f.value_comp()(*fi, *++fi)) ));
	}

	P("---------> erase <----");
	{
		std::multimap<std::string, std::string>::iterator si = s.begin();
		ft::multimap<std::string, std::string>::iterator fi = f.begin();
		s.erase(si);
		f.erase(fi);

		si = s.begin();
		fi = f.begin();

		s.erase(si->first);
		f.erase(fi->first);

		si = s.begin();
		fi = f.begin();

		std::multimap<std::string, std::string>::iterator si2(si);
		ft::multimap<std::string, std::string>::iterator fi2(fi);
		si2++;
		++si2;
		fi2++;
		++fi2;

		f.erase(++fi, ++fi2);
		s.erase(++si, ++si2);
		P(verif( compare_map(s, f) ));
	}
	P("---------> swap  <----");
	{
		ft::multimap<std::string, std::string>	 f3;
		std::multimap<std::string, std::string>	 s3;
		s.swap(s3);
		f.swap(f3);
		P(verif(compare_map(s, f)));
		P(verif(compare_map(s3, f3)));

		swap(s, s3);
		swap(f, f3);
	}
	P("---------> reverse_iterator <----");
	{
		ft::multimap<std::string, std::string>::reverse_iterator fi3 = f.rbegin();
		std::multimap<std::string, std::string>::reverse_iterator si3 = s.rbegin();
		bool good = true;
		for (; si3 != s.rend(); si3++)
		{
			if (si3->first != fi3->first || si3->second != fi3->second)
				good = false;
			fi3++;
		}
		P("Reverse Iterator" << verif(good));
	}
	P("---------> clear <----");
	ft::multimap<std::string, std::string>	f2(f);
	std::multimap<std::string, std::string>	s2(s);
	
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

void t_set(void)
{
	ft::set<std::string>	f;
	std::set<std::string>	s;
	
	P("~~~~~~~~~~~~~~~ SET ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> INSERT <----");
	s.insert("one");
	s.insert("two") ;
	s.insert("three") ;
	s.insert("four") ;
	
	f.insert("one") ;
	f.insert("two");
	f.insert("three") ;
	f.insert("four") ;

	s.insert(s.begin(), s.end());
	f.insert(f.begin(), f.end());
	P(verif( compare_container(s, f) ));
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> Constructor <----");
	{
		ft::set<std::string>	 f2(f);
		std::set<std::string>	 s2(s);
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	{
		ft::set<std::string>	 f2(f.begin(), f.end());
		std::set<std::string>	 s2(s.begin(), s.end());
		P("Same container" << verif( compare_container(f2, f) ));
		// show_container(f2);
		// show_container(f);

		P("size = " << f2.size() << verif(f.size() == f2.size()) );
	}
	P("---------> Operator= <----");
	{
		ft::set<std::string>	 f2 = f;
		std::set<std::string>	 s2 = s;
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	P("---------> Count <----");
	P(verif( (s.count("one") == f.count("one") && s.count("lol") == f.count("lol"))  ));
	
	P("---------> Equal_Range <----");
	{
		std::pair<std::set< std::string>::iterator, std::set< std::string>::iterator> si;
		ft::pair<ft::set< std::string>::iterator, ft::set< std::string>::iterator> fi; 

		si = s.equal_range("three");
		fi = f.equal_range("three");

		P(verif( ( *(si.first) == *(fi.first) && *(si.second) == *(fi.second))  ));
	}
	P("---------> Lower_Bound <----");
	{
		std::set< std::string>::iterator si;
		ft::set< std::string>::iterator fi;

		si = s.lower_bound("three");
		fi = f.lower_bound("three");

		P(verif( (*si == *fi)  ));
	}
	P("---------> Upper_Bound <----");
	{
		std::set< std::string>::iterator si;
		ft::set< std::string>::iterator fi;

		si = s.upper_bound("three");
		fi = f.upper_bound("three");

		P(verif( (*si == *fi)  ));
	}
	P("---------> Value_Comp <----");
	{
		std::set< std::string>::iterator si = s.begin();
		ft::set< std::string>::iterator fi = f.begin();

		P( verif( (s.value_comp()(*si, *++si) == f.value_comp()(*fi, *++fi)) ));
	}

	P("---------> erase <----");
	{
		std::set< std::string>::iterator si = s.begin();
		ft::set< std::string>::iterator fi = f.begin();
		s.erase(si++);
		f.erase(fi++);
		si++;
		fi++;

		std::set< std::string>::iterator si2 = s.begin();
		ft::set< std::string>::iterator fi2 = f.begin();
		s.erase(*si2 );
		f.erase(*fi2 );

		si2 = s.begin();
		fi2 = f.begin();

		f.erase(fi2, fi);
		s.erase(si2, si);
		P(verif( compare_container(s, f) ));
	}
	P("---------> swap  <----");
	{
		ft::set< std::string>	 f3;
		std::set< std::string>	 s3;
		s.swap(s3);
		f.swap(f3);
		P(verif(compare_container(s, f)));
		P(verif(compare_container(s3, f3)));

		swap(s, s3);
		swap(f, f3);
	}
	P("---------> reverse_iterator <----");
	{
		ft::set< std::string>::reverse_iterator fi3 = f.rbegin();
		std::set< std::string>::reverse_iterator si3 = s.rbegin();
		bool good = true;
		for (; si3 != s.rend(); si3++)
		{
			if (*si3 != *fi3)
				good = false;
			fi3++;
		}
		P("Reverse Iterator" << verif(good));
	}
	P("---------> clear <----");
	ft::set< std::string>	f2(f);
	std::set< std::string>	s2(s);
	
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

void t_multiset(void)
{
	ft::multiset<std::string>	f;
	std::multiset<std::string>	s;
	
	P("~~~~~~~~~~~~~~~ MULTISET ~~~~~~~~~~~~~~~");
	P("---------> empty <----");
	P("empty ? " << s.empty() << verif(s.empty() == f.empty()) );
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> INSERT <----");
	{
		s.insert("one");
		s.insert("two") ;
		s.insert("three") ;
		s.insert("four") ;
		s.insert("one");
		s.insert("two") ;
		s.insert("three") ;
		s.insert("four") ;
		
		f.insert("one") ;
		f.insert("two");
		f.insert("three") ;
		f.insert("four") ;
		f.insert("one") ;
		f.insert("two");
		f.insert("three") ;
		f.insert("four") ;

		ft::multiset<std::string>	f2(f);
		std::multiset<std::string>	s2(s);

		s.insert(s2.begin(), s2.end());
		f.insert(f2.begin(), f2.end());
		P(verif( compare_container(s, f) ));
		P("size = " << s.size() << verif(s.size() == f.size()) );
	}
	P("---------> Constructor <----");
	{
		ft::multiset<std::string>	 f2(f);
		std::multiset<std::string>	 s2(s);
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	{
		ft::multiset<std::string>	 f2(f.begin(), f.end());
		std::multiset<std::string>	 s2(s.begin(), s.end());
		P("Same container" << verif( compare_container(f2, f) ));
		// show_container(f2);
		// show_container(f);

		P("size = " << f2.size() << verif(f.size() == f2.size()) );
	}
	P("---------> Operator= <----");
	{
		ft::multiset<std::string>	 f2 = f;
		std::multiset<std::string>	 s2 = s;
		P("Same container" << verif( compare_container(s2, f2) ));
		P("size = " << s2.size() << verif(s2.size() == f2.size()) );
	}
	P("---------> Count <----");
	P(verif( (s.count("one") == f.count("one") && s.count("lol") == f.count("lol"))  ));
	
	P("---------> Equal_Range <----");
	{
		std::pair<std::multiset< std::string>::iterator, std::multiset< std::string>::iterator> si;
		ft::pair<ft::multiset< std::string>::iterator, ft::multiset< std::string>::iterator> fi; 

		si = s.equal_range("three");
		fi = f.equal_range("three");

		P(verif( ( *(si.first) == *(fi.first) && *(si.second) == *(fi.second))  ));
	}
	P("---------> Lower_Bound <----");
	{
		std::multiset< std::string>::iterator si;
		ft::multiset< std::string>::iterator fi;

		si = s.lower_bound("three");
		fi = f.lower_bound("three");

		P(verif( (*si == *fi)  ));
	}
	P("---------> Upper_Bound <----");
	{
		std::multiset< std::string>::iterator si;
		ft::multiset< std::string>::iterator fi;

		si = s.upper_bound("three");
		fi = f.upper_bound("three");

		P(verif( (*si == *fi)  ));
	}
	P("---------> Value_Comp <----");
	{
		std::multiset< std::string>::iterator si = s.begin();
		ft::multiset< std::string>::iterator fi = f.begin();

		P( verif( (s.value_comp()(*si, *++si) == f.value_comp()(*fi, *++fi)) ));
	}

	P("---------> erase <----");
	{
		std::multiset< std::string>::iterator si = s.begin();
		ft::multiset< std::string>::iterator fi = f.begin();
		s.erase(si);
		f.erase(fi);

		si = s.begin();
		fi = f.begin();

		s.erase(*si);
		f.erase(*fi);

		si = s.begin();
		fi = f.begin();

		std::multiset< std::string>::iterator si2(si);
		ft::multiset< std::string>::iterator fi2(fi);
		si2++;
		++si2;
		fi2++;
		++fi2;
		
		f.erase(++fi, ++fi2);
		s.erase(++si, ++si2);
		P(verif( compare_container(s, f) ));
		// show_container(s);
		// show_container(f);
	}
	P("---------> swap  <----");
	{
		ft::multiset< std::string>	 f3;
		std::multiset< std::string>	 s3;
		s.swap(s3);
		f.swap(f3);

		P(verif(compare_container(s, f)));
		P(verif(compare_container(s3, f3)));

		swap(s, s3);
		swap(f, f3);
	}
	P("---------> reverse_iterator <----");
	{
		ft::multiset< std::string>::reverse_iterator fi3 = f.rbegin();
		std::multiset< std::string>::reverse_iterator si3 = s.rbegin();
		bool good = true;
		for (; si3 != s.rend(); si3++)
		{
			if (*si3 != *fi3)
				good = false;
			fi3++;
		}
		P("Reverse Iterator" << verif(good));
	}
	P("---------> clear <----");
	ft::multiset< std::string>	f2(f);
	std::multiset< std::string>	s2(s);
	
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

void t_deque(void)
{
	ft::deque<std::string>	f;
	std::deque<std::string>	s;
	
	P("~~~~~~~~~~~~~~~ DEQUE ~~~~~~~~~~~~~~~");
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
	ft::deque<std::string>	f2(f.begin(), f.end());
	std::deque<std::string>	s2(s.begin(), s.end());

	P(verif( compare_container(s2, f2) ));
	P("---------> Pop_Front <----");
	s.pop_front();
	f.pop_front();
	P(verif( compare_container(s, f) ));

	P("---------> Pop_Back <----");
	s.pop_back();
	f.pop_back();
	P(verif( compare_container(s, f) ));
	
	P("---------> resize (10) <----");
	s.resize(10);
	f.resize(10);
	P("size = " << s.size() << verif(s.size() == f.size()) );

	P("---------> resize (5) <----");
	s.resize(5);
	f.resize(5);
	P("size = " << s.size() << verif(s.size() == f.size()) );
	P("---------> Assign <----");
	{
		ft::deque<std::string>	 f2(f);
		ft::deque<std::string>	 f3;
		std::deque<std::string>	 s2(s);
		std::deque<std::string>	 s3;

		f3.assign(f2.begin(), f2.end());
		s3.assign(s2.begin(), s2.end());
		P(verif( compare_container(s3, f3) ));

		f3.assign(5, "lol");
		s3.assign(5, "lol");
		P(verif( compare_container(s3, f3) ));
	}
	P("---------> at <----");
	{
		bool v = true;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (s.at(i) != f.at(i))
				v = false;
		}
		P(verif(v));
	}
	P("---------> erase <----");
	ft::deque<std::string>::iterator fi, fi2;
	std::deque<std::string>::iterator si, si2;

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

	P("---------> swap  <----");
	s.swap(s2);
	f.swap(f2);
	P(verif(compare_container(s, f)));
	P(verif(compare_container(s2, f2)));
	swap(s, s2);
	swap(f, f2);

	P("---------> insert <----");
	si = s.begin();
	si++;
	++si;
	s.insert(si, "lol2");
	s.insert(si, "lol2");
	s.insert(si, "lol2");
	si = ++(s.begin());
	s.insert(si, "lol1");
	s.insert(si, "lol1");
	si = ++(s.begin());
	si++;
	++si;
	s2.insert(s2.begin(), s.begin(), si);

	fi = f.begin();
	fi++;
	++fi;
	f.insert(fi, "lol2");
	f.insert(fi, "lol2");
	f.insert(fi, "lol2");
	fi = ++(f.begin());
	f.insert(fi, "lol1");
	f.insert(fi, "lol1");
	fi = ++(f.begin());
	fi++;
	++fi;
	f2.insert(f2.begin(), f.begin(), fi);
	P(verif(compare_container(s, f)));
	P(verif(compare_container(s2, f2)));
	
	P("---------> reverse_iterator <----");
	ft::deque<std::string>::reverse_iterator fi3 = f.rbegin();
	std::deque<std::string>::reverse_iterator si3 = s.rbegin();
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
	t_deque();
	// system("leaks a.out");
	return (0);
}