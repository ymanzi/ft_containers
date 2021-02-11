#	ifndef TEST_HPP
#	define TEST_HPP

#include <iostream>
#include <string>
#include <cmath>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

#define P(x) std::cout << std::boolalpha << x << std::endl

extern bool g_verif;

void check(bool val, std::string const& msg)
{
	if (!val)
	{
		P(RED "Fail: " + msg);
		g_verif = false;
	}
}

void end_check(bool val, std::string const& msg)
{
	std::cout << msg;
	if (val)
		P(GRN " [CORRECT]" NC);
	else
		P(REDB "[K.O]" NC);
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (std::fabs(first-second)<5.0); }
};

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

template <class T>
bool compare_fct(T a, T b)
{
	if (a < b)
		return (true);
	return (false);
}

template <class T, class K>
void constructor_t(T const& t, K const& k)
{
	// P("~~~~~~~~ Default Constructor ~~~~~~~~~~");
	T ad = T();
	K bd = K();

	// P("~~~~~~~~ Fill Constructor ~~~~~~~~~~");
	T af = T(5, 2);
	K bf = K(5, 2);

	check(compare_container(af, bf)," Fill Constructor ");

	// P("~~~~~~~~ Range Constructor ~~~~~~~~~~");
	T ar = T(af.begin(), af.end());
	K br = K(bf.begin(), bf.end());

	check(compare_container(ar, br)," Range Constructor ");

	// P("~~~~~~~~ Copy Constructor ~~~~~~~~~~");

	T ac(ar);
	K bc(br);

	check(compare_container(ac, bc)," Copy Constructor ");
}

template <class T, class K>
void map_constructor_t(T const& t, K const& k)
{
	// P("~~~~~~~~ Default Constructor ~~~~~~~~~~");
	T ad = T();
	K bd = K();

	for (int i = 0; i < 10; i++)
	{
		ad.insert(std::pair<int, int>(i, i*i));
		bd.insert(std::pair<int, int>(i, i*i));
	}

	// P("~~~~~~~~ Range Constructor ~~~~~~~~~~");
	T ar = T(ad.begin(), ad.end());
	K br = K(bd.begin(), bd.end());

	check(compare_map(ar, br)," Range Constructor ");

	// P("~~~~~~~~ Copy Constructor ~~~~~~~~~~");

	T ac(ar);
	K bc(br);

	check(compare_map(ac, bc)," Copy Constructor ");
}

template <class T, class K>
void assign_t(T const& t, K const& k)
{
	T basic = T(5, 2);
	K basic2 = K(5, 2);
	// P("~~~~~~~~ Assign Range ~~~~~~~~~~");	
	T a;
	K b;

	a.assign(basic.begin(), basic.end());
	b.assign(basic2.begin(), basic2.end());

	check(compare_container(a, b)," Assign Range ");

	// P("~~~~~~~~ Assign Fill ~~~~~~~~~~");
	a.assign(4, 265);
	b.assign(4, 265);
	check(compare_container(a, b)," Assign Fill ");
}

template <class T, class K>
void at_t(T const& t, K const& k)
{
	bool verif = true;
	T a = T(5, 2);
	K b = K(5, 2);
	// P("~~~~~~~~ At ~~~~~~~~~~");	
	
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a.at(i) != b.at(i))
			verif = false;
	}

	// P("~~~~~~ At - Throw Exception ~~~~~~");
	try
	{
		a.at(a.size());
		P("Error: Function At - No exception was throwed");
		verif = false;
	}
	catch (const std::exception& e)
	{
		//P("Good Exception: " << e.what());
	}
	check(verif, "Function At");
}

template <class T, class K>
void back_t(T const& t, K const& k)
{
	T a;
	K b;
	bool verif = true;
	// P("~~~~~~~~ Back ~~~~~~~~~~");	
	for (size_t i = 0; i < 5; i++)
	{
		a.push_back(i * i);
		b.push_back(i * i);
		if (a.back() != b.back())
			verif = false;
	}
	check(verif, "Function Back");
}

template <class T, class K>
void capacity_t(T const& t, K const& k)
{
	T a;
	K b;
	bool verif = true;
	// P("~~~~~~~~ Capacity ~~~~~~~~~~");	
	for (size_t i = 0; i < 100; i++)
	{
		a.push_back(i * i);
		b.push_back(i * i);
	}
	check((a.capacity() >= a.size()), "Function Capacity");
}

template <class T, class K>
void map_clear_empty_t(T const& t, K const& k)
{
	T a;
	K b;

	for (int i = 0; i < 10; i++)
	{
		a.insert(std::pair<int, int>(i, i*i));
		b.insert(std::pair<int, int>(i, i*i));
	}
	// P("~~~~~~~~ Clear ~~~~~~~~~~");	
	a.clear();
	b.clear();
	check(((a.size() == b.size()) && a.empty()), "Function Clear & Empty");
}

template <class T, class K>
void clear_empty_t(T const& t, K const& k)
{
	T a(121, 5);
	K b(121, 5);
	// P("~~~~~~~~ Clear ~~~~~~~~~~");	
	a.clear();
	b.clear();
	check(((a.size() == b.size()) && a.empty()), "Function Clear & Empty");
}

template <class T, class K>
void map_count_t(T const& t, K const& k)
{
	T a;
	K b;

	for (int i = 0; i < 10; i++)
	{
		a.insert(std::pair<int, int>(i, i*i));
		b.insert(std::pair<int, int>(i, i*i));
	}
	// P("~~~~~~~~ Count ~~~~~~~~~~");	
	check((a.count(5) == b.count(5) && a.count(36) == b.count(36)), "Function Count");
}

template <class T, class K>
void map_equal_range_t(T const& t, K const& k)
{
	T a;
	K b;

	for (int i = 0; i < 10; i++)
	{
		a.insert(std::pair<int, int>(i, i*i));
		b.insert(std::pair<int, int>(i, i*i));
	}
	std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> a1 = a.equal_range(2);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> b1 = b.equal_range(2);

	// P("~~~~~~~~ Equal_Range ~~~~~~~~~~");	
	check((a1.first->first == b1.first->first && a1.first->second == b1.first->second && 
		a1.second->first == b1.second->first && a1.second->second == b1.second->second), "Function Equal_Range");
}

template <class T, class K>
void erase_t(T const& t, K const& k)
{
	T a;
	K b;
	bool verif = true;
	
	typename T::iterator it2;
	typename K::iterator ik2;
	
	typename T::iterator it3;
	typename K::iterator ik3;
	
	// P("~~~~~~~~ Erase (Single Element) ~~~~~~~~~~");	
	{
		for (size_t i = 0; i < 100; i++)
		{
			a.push_back(i * i);
			b.push_back(i * i);
		}
		int r = rand() % 60;
		for (int i = 0; i < r; i++)
		{
			typename T::iterator it = a.begin();
			typename K::iterator ik = b.begin();

			int r2 = rand() % 20;
			for (int l = 0; i < l; i++)
			{
				it++;
				ik++;
			}
			it2 = a.erase(it);
			ik2 = b.erase(ik);

			if (*it2 != *ik2)
				verif = false;
		}
		check((verif && compare_container(a, b)), "Function Erase (Single Element)");
	}
	// P("~~~~~~~~ Erase (Iterator) ~~~~~~~~~~");	
	{
		for (size_t i = 0; i < 100; i++)
		{
			a.push_back(i * i);
			b.push_back(i * i);
		}
		int r = rand() % 10;
		for (int i = 0; i < r; i++)
		{
			typename T::iterator it = a.begin();
			typename K::iterator ik = b.begin();

			int r2 = rand() % 10;
			for (int l = 0; i < l; i++)
			{
				it++;
				ik++;
			}
			it2 = it;
			ik2 = ik;

			r2 = rand() % 10;
			for (int l = 0; i < l; i++)
			{
				it2++;
				ik2++;
			}
			it3 = a.erase(it, it2);
			ik3 = b.erase(ik, ik2);
			if (*it3 != *ik3)
				verif = false;
		}
		check((verif && compare_container(a, b)), "Function Erase (Iterator)");
	}
}

template <class T, class K>
void map_erase_t(T const& t, K const& k)
{
	T a;
	K b;
	bool verif = true;
	
	typename T::iterator it2;
	typename K::iterator ik2;
	
	typename T::iterator it3;
	typename K::iterator ik3;
	
	// P("~~~~~~~~ Erase (Single Element) ~~~~~~~~~~");	
	{
		for (size_t i = 0; i < 100; i++)
		{
			a.push_back(i * i);
			b.push_back(i * i);
		}
		int r = rand() % 60;
		for (int i = 0; i < r; i++)
		{
			typename T::iterator it = a.begin();
			typename K::iterator ik = b.begin();

			int r2 = rand() % 20;
			for (int l = 0; i < l; i++)
			{
				it++;
				ik++;
			}
			it2 = a.erase(it);
			ik2 = b.erase(ik);

			if (*it2 != *ik2)
				verif = false;
		}
		check((verif && compare_container(a, b)), "Function Erase (Single Element)");
	}
	// P("~~~~~~~~ Erase (Iterator) ~~~~~~~~~~");	
	{
		for (size_t i = 0; i < 100; i++)
		{
			a.push_back(i * i);
			b.push_back(i * i);
		}
		int r = rand() % 10;
		for (int i = 0; i < r; i++)
		{
			typename T::iterator it = a.begin();
			typename K::iterator ik = b.begin();

			int r2 = rand() % 10;
			for (int l = 0; i < l; i++)
			{
				it++;
				ik++;
			}
			it2 = it;
			ik2 = ik;

			r2 = rand() % 10;
			for (int l = 0; i < l; i++)
			{
				it2++;
				ik2++;
			}
			it3 = a.erase(it, it2);
			ik3 = b.erase(ik, ik2);
			if (*it3 != *ik3)
				verif = false;
		}
		check((verif && compare_container(a, b)), "Function Erase (Iterator)");
	}
}

template <class T, class K>
void front_t(T const& t, K const& k)
{
	T a;
	K b;
	bool verif = true;
	// P("~~~~~~~~ Front ~~~~~~~~~~");	
	for (size_t i = 0; i < 5; i++)
	{
		a.push_back(i * i);
		b.push_back(i * i);
		if (a.front() != b.front())
			verif = false;
	}
	check(verif, "Function Front");
}

template <class T, class K>
void insert_t(T const& t, K const& k)
{
	T a;
	K b;
	bool verif = true;
	std::srand(std::time(nullptr));
	
	typename T::iterator it2;
	typename K::iterator ik2;
	
	typename T::iterator it3;
	typename K::iterator ik3;
	
	// P("~~~~~~~~ Insert (Single Element) ~~~~~~~~~~");	
	{
		int r;
		for (size_t i = 0; i < 100; i++)
		{
			it2 = a.begin();
			ik2 = b.begin();

			if (a.size())
				r = rand() % a.size();
			else
				r = 0;
			 for (int l = 0; l < r; l++)
			 {
				 it2++;
				 ik2++;
			 }
 			it3 = a.insert(it2, i * i);
			ik3 = b.insert(ik2, i * i);
			if (*it3 != *ik3)
				verif = false;
		}
		check((verif && compare_container(a, b)), "Function Insert (Single Element)");
	}
	// P("~~~~~~~~ Insert (Fill) ~~~~~~~~~~");	
	{
		int r;
		for (size_t i = 0; i < 20; i++)
		{
			it2 = a.begin();
			ik2 = b.begin();

			if (a.size())
				r = rand() % a.size() - 1;
			else
				r = 0;
			for (int l = 0; l < r; l++)
			{
				it2++;
				ik2++;
			}
 			a.insert(it2, i, i * i);
			b.insert(ik2, i, i * i);
		}
		check((compare_container(a, b)), "Function Insert (Fill)");		
	}

	// P("~~~~~~~~ Insert (Iterator) ~~~~~~~~~~");	
	{
		for (size_t i = 0; i < 50; i++)
		{
			a.push_back(i * i);
			b.push_back(i * i);
		}
		int r = rand() % 10;
		for (int i = 0; i < r; i++)
		{
			typename T::iterator it = a.begin();
			typename K::iterator ik = b.begin();

			int r2 = rand() % 10;
			for (int l = 0; i < l; i++)
			{
				it++;
				ik++;
			}
			it2 = it;
			ik2 = ik;

			r2 = rand() % 10;
			for (int l = 0; i < l; i++)
			{
				it2++;
				ik2++;
			}
			a.insert(a.begin(), it, it2);
			b.insert(b.begin(), ik, ik2);
		}
		check((compare_container(a, b)), "Function Insert (Iterator)");	
	}
}

template <class T, class K>
void merge_t(T const& t, K const& k)
{
	T a;
	T a1;
	K b;
	K b1;
	bool verif = true;
	std::srand(std::time(nullptr));
	
	typename T::iterator it2;
	typename K::iterator ik2;
	
	int r;
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		if (r % 2)
		{
			a.push_back(r);
			b.push_back(r);
		}
		else
		{
			a1.push_back(r);
			b1.push_back(r);
		}
		a.sort();
		a1.sort();
		b.sort();
		b1.sort();
	}
	{
		T tmp(a);
		a.merge(a1);
		b.merge(b1);
		check((compare_container(a, b)), "Function Merge (Void parameter)");
		a = tmp;
	}
	{
		a.merge(a1, compare_fct<int>);
		b.merge(b1, compare_fct<int>);
		check((compare_container(a, b)), "Function Merge (Comp parameter)");
	}
}

template <class T, class K>
void operator_at_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	for (int i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}
	
	// P("~~~~~~~~ Operator = ~~~~~~~~~~");	
	
	T a1 = a;
	K b1 = b;

	check((compare_container(a1, b1)), "Operator =");	
}

template <class T, class K>
void pop_back_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	for (int i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}

	for (int i = 0; i < 80; i++)
	{
		a.pop_back();
		b.pop_back();
		if (a.back() != b.back())
			verif = false;
	}
	
	// P("~~~~~~~~ Pop Back ~~~~~~~~~~");	
	
	check(verif, "Function Pop_Back");
}

template <class T, class K>
void pop_front_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	for (int i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}

	for (int i = 0; i < 80; i++)
	{
		a.pop_front();
		b.pop_front();
		if (a.front() != b.front())
			verif = false;
	}
	
	// P("~~~~~~~~ Pop Front ~~~~~~~~~~");	
	
	check(verif, "Function Pop_Front");
}

template <class T, class K>
void push_back_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	for (int i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
		if (a.back() != b.back() && a.back() != r)
			verif = false;
	}
	// P("~~~~~~~~ Push Back ~~~~~~~~~~");	
	
	check(verif, "Function Push_Back");
}

template <class T, class K>
void push_front_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	for (int i = 0; i < 100; i++)
	{
		r = rand();
		a.push_front(r);
		b.push_front(r);
		if (a.front() != b.front() && a.front() != r)
			verif = false;
	}
	// P("~~~~~~~~ Push Front ~~~~~~~~~~");	
	
	check(verif, "Function Push_Front");
}

template <class T, class K>
void remove_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	int tab[20];
	for (int i = 0; i < 20; i++)
		tab[i] = rand();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			a.push_front(tab[j]);
			b.push_front(tab[j]);
		}
	}
	a.remove(tab[5]);
	a.remove(10);
	b.remove(tab[5]);
	b.remove(10);
	// P("~~~~~~~~ Remove ~~~~~~~~~~");	
	
	check(compare_container(a,b), "Function Remove");
}

template <class T, class K>
void remove_if_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	int tab[20];
	for (int i = 0; i < 20; i++)
		tab[i] = rand() % 100;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			a.push_front(tab[j]);
			b.push_front(tab[j]);
		}
	}
	a.remove_if(single_digit);
	a.remove_if(is_odd());
	b.remove_if(single_digit);
	b.remove_if(is_odd());
	// P("~~~~~~~~ Remove ~~~~~~~~~~");	
	
	check(compare_container(a,b), "Function Remove_if");
}

template <class T, class K>
void re_size_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	for (int i = 0; i < 100; i++)
	{
		r = rand() % 100;
		a.resize(r);
		b.resize(r);
		if (a.size() != b.size())
			verif = false;
	}
	// P("~~~~~~~~ (Re)Size ~~~~~~~~~~");	
	
	check(verif, "Function (Re)size");
}

template <class T, class K>
void reverse_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	
	T a;
	K b;
	int r;
	int tab[20];
	for (int i = 0; i < 20; i++)
		tab[i] = rand() % 100;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			a.push_front(tab[j]);
			b.push_front(tab[j]);
		}
	}
	a.reverse();
	b.reverse();
	// P("~~~~~~~~ Remove ~~~~~~~~~~");	
	
	check(compare_container(a,b), "Function Reverse");
}

template <class T, class K>
void splice_t(T const& t, K const& k)
{
	T a;
	T a1;
	K b;
	K b1;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::iterator it;
	typename T::iterator it2;
	typename T::iterator it3;
	typename K::iterator ik;
	typename K::iterator ik2;
	typename K::iterator ik3;
	
	int r;
	{
		for (size_t i = 0; i < 100; i++)
		{
			r = rand();
			if (r % 2)
			{
				a.push_back(r);
				b.push_back(r);
			}
			else
			{
				a1.push_back(r);
				b1.push_back(r);
			}
		}
		it = a.begin();
		ik = b.begin();
		for (size_t i = 0; i < 10; i++)
		{
			it++;
			ik++;
		}
		a.splice(it, a1);
		b.splice(ik, b1);
		check((compare_container(a, b) && compare_container(a1, b1)), "Function Splice (Entire List)");
	}
	{
		for (size_t i = 0; i < 100; i++)
		{
			r = rand();
			if (r % 2)
			{
				a.push_back(r);
				b.push_back(r);
			}
			else
			{
				a1.push_back(r);
				b1.push_back(r);
			}
		}
		it = a.begin();
		it2 = a1.begin();
		ik = b.begin();
		ik2 = b1.begin();
		for (size_t i = 0; i < 10; i++)
		{
			it++;
			it2++;
			ik++;
			ik2++;
		}
		a.splice(it, a1, it2);
		b.splice(ik, b1, ik2);
		check((compare_container(a, b) && compare_container(a1, b1)), "Function Splice (Single Element)");
	}
	{
		for (size_t i = 0; i < 100; i++)
		{
			r = rand();
			if (r % 2)
			{
				a.push_back(r);
				b.push_back(r);
			}
			else
			{
				a1.push_back(r);
				b1.push_back(r);
			}
		}
		it = a.begin();
		it2 = a1.begin();
		it3 = a1.begin();
		ik = b.begin();
		ik2 = b1.begin();
		ik3 = b1.begin();
		for (size_t i = 0; i < 10; i++)
		{
			it++;
			it2++;
			it3++;
			ik++;
			ik2++;
			ik3++;
		}
		for (size_t i = 0; i < 10; i++)
		{
			it3++;
			ik3++;
		}
		a.splice(it, a1, it2, it3);
		b.splice(ik, b1, ik2, ik3);
		check((compare_container(a, b) && compare_container(a1, b1)), "Function Splice (Element Range)");
	}
}

template <class T, class K>
void swap_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));
	{
	T a;
	K b;

	T a1;
	K b1;
	int r;
	for (int i = 0; i < 20; i++)
	{
		r = rand() % 100 + 1;
		a.push_back(r);
		b.push_back(r);
		a.swap(a1);
		b.swap(b1);
		if (!compare_container(a, b) || !compare_container(a1, b1) )
			verif = false;
	}
	
	if (!compare_container(a, b) || !compare_container(a1, b1) )
		verif = false;

	// P("~~~~~~~~ Swap ~~~~~~~~~~");	
	
	check(verif, "Function Swap- Internal");
	}
	{
	T a;
	K b;

	T a1;
	K b1;
	int r;
	for (int i = 0; i < 20; i++)
	{
		r = rand() % 100 + 1;
		a.push_back(r);
		b.push_back(r);
		swap(a, a1);
		swap(b, b1);
		if (!compare_container(a, b) || !compare_container(a1, b1) )
			verif = false;
	}
	if (!compare_container(a, b) || !compare_container(a1, b1) )
		verif = false;

	// P("~~~~~~~~ Swap ~~~~~~~~~~");	
	
	check(verif, "Function Swap - External");
	}
}

template <class T, class K>
void sort_t(T const& t, K const& k)
{
	T a;
	K b;
	bool verif = true;
	std::srand(std::time(nullptr));
	
	typename T::iterator it2;
	typename K::iterator ik2;
	
	int r;
	for (size_t i = 0; i < 100; i++)
	{
		it2 = a.begin();
		ik2 = b.begin();

		if (a.size())
			r = rand() % a.size();
		else
			r = 0;
			for (int l = 0; l < r; l++)
			{
				it2++;
				ik2++;
			}
			r = rand();
		a.insert(it2, r);
		b.insert(ik2, r);
	}
	{
		a.sort();
		b.sort();
		check((compare_container(a, b)), "Function Sort (Void parameter)");
	}
	{
		a.sort(compare_fct<int>);
		b.sort(compare_fct<int>);
		check((compare_container(a, b)), "Function Sort (Comp parameter)");
	}
}

template <class T, class K>
void unique_t(T const& t, K const& k)
{
	bool verif = true;
	std::srand(std::time(nullptr));

	// P("~~~~~~~~ Unique ~~~~~~~~~~");	
	T a;
	K b;
	int r;
	int tab[20];
	for (int i = 0; i < 20; i++)
		tab[i] = rand();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			a.push_front(tab[j]);
			b.push_front(tab[j]);
		}
	}
	a.sort();
	b.sort();
	{
		a.unique();
		b.unique();
		check(compare_container(a,b), "Function Unique void");
	}
	{
		a.unique(is_near());
		b.unique(is_near());
		check(compare_container(a,b), "Function Unique with Class");
	}
	{
		a.unique(same_integral_part);
		b.unique(same_integral_part);
		check(compare_container(a,b), "Function Unique with Function");
	}	
}

template <class T, class K>
void iterator_t(T const& t, K const& k)
{
	T a;
	K b;
	int r;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::iterator it;
	typename K::iterator ik;
	
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}
	for (size_t i = 0; i < 100; i++)
	{
		it = a.begin();
		ik = b.begin();
		r = rand() % (a.size() - 1);
		for (int j = 0; j < r; j++)
		{
			it++;
			ik++;
		}
		if (*it != *ik)
			verif = false;
	}
	check(verif, "Iterator Check");
}

template <class T, class K>
void r_iterator_t(T const& t, K const& k)
{
	T a;
	K b;
	int r;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::reverse_iterator it;
	typename K::reverse_iterator ik;
	
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}
	for (size_t i = 0; i < 100; i++)
	{
		it = a.rbegin();
		ik = b.rbegin();
		r = rand() % (a.size() - 1);
		for (int j = 0; j < r; j++)
		{
			it++;
			ik++;
		}
		if (*it != *ik)
			verif = false;
	}
	check(verif, "Iterator Check");
}

template <class T, class K>
void comp_t(T const& t, K const& k)
{
	T a;
	T a1;
	K b;
	K b1;
	int r;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::reverse_iterator it;
	typename K::reverse_iterator ik;
	
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}
	check(((a == a1) == (b == b1)) , "Operator == ");
	check(((a != a1) == (b != b1)) , "Operator != ");
	check(((a < a1) == (b < b1)) , "Operator <");
	check(((a <= a1) == (b <= b1)) , "Operator <=");
	check(((a > a1) == (b > b1)) , "Operator > ");
	check(((a >= a1) == (b >= b1)) , "Operator >=");
}

template <class T, class K>
void iterator_comp_t_ra(T const& t, K const& k)
{
	T a;
	K b;
	int r;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::iterator it = a.begin();
	typename T::iterator it2(it);
	typename K::iterator ik = b.begin();
	typename K::iterator ik2(ik);
	
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}

	r = rand() % (int)(a.size() - 10);

	for (int j = 0; j < r; j++)
	{
		it++;
		ik++;
	}
	check(((ik == ik2) == (it == it2)) , "Iterator Operator == ");
	check(((ik++ == ik2++) == (it++ == it2++)) , "Iterator Operator it++ ");
	check(((++ik == ++ik2) == (++it == ++it2)) , "Iterator Operator ++it");
	check(((ik-- == ik2--) == (it-- == it2--)) , "Iterator Operator it-- ");
	check(((--ik == --ik2) == (--it == --it2)) , "Iterator Operator --it");
	check(((ik != ik2) == (it != it2)) , "Iterator Operator != ");
	check(((ik < ik2) == (it < it2)) , "Iterator Operator <");
	check(((ik <= ik2) == (it <= it2)) , "Iterator Operator <=");
	check(((ik > ik2) == (it > it2)) , "Iterator Operator > ");
	check(((ik >= ik2) == (it >= it2)) , "Iterator Operator >=");
}

template <class T, class K>
void iterator_comp_t_bd(T const& t, K const& k)
{
	T a;
	K b;
	int r;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::iterator it = a.begin();
	typename T::iterator it2(it);
	typename K::iterator ik = b.begin();
	typename K::iterator ik2(ik);
	
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}

	r = rand() % (int)(a.size() - 10);

	for (int j = 0; j < r; j++)
	{
		it++;
		ik++;
	}
	check(((ik == ik2) == (it == it2)) , "Iterator Operator == ");
	check(((ik++ == ik2++) == (it++ == it2++)) , "Iterator Operator it++ ");
	check(((++ik == ++ik2) == (++it == ++it2)) , "Iterator Operator ++it");
	check(((ik-- == ik2--) == (it-- == it2--)) , "Iterator Operator it-- ");
	check(((--ik == --ik2) == (--it == --it2)) , "Iterator Operator --it");
	check(((ik != ik2) == (it != it2)) , "Iterator Operator != ");
}

template <class T, class K>
void r_iterator_comp_t_ra(T const& t, K const& k)
{
	T a;
	K b;
	int r;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::reverse_iterator it = a.rbegin();
	typename T::reverse_iterator it2(it);
	typename K::reverse_iterator ik = b.rbegin();
	typename K::reverse_iterator ik2(ik);
	
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}

	r = rand() % (int)(a.size() - 10);

	for (int j = 0; j < r; j++)
	{
		it++;
		ik++;
	}
	check(((ik == ik2) == (it == it2)) , "Reverse Iterator Operator == ");
	check(((ik++ == ik2++) == (it++ == it2++)) , "Reverse Iterator Operator it++ ");
	check(((++ik == ++ik2) == (++it == ++it2)) , "Reverse Iterator Operator ++it");
	check(((ik-- == ik2--) == (it-- == it2--)) , "Reverse Iterator Operator it-- ");
	check(((--ik == --ik2) == (--it == --it2)) , "Reverse Iterator Operator --it");
	check(((ik != ik2) == (it != it2)) , "Reverse Iterator Operator != ");
	check(((ik < ik2) == (it < it2)) , "Reverse Iterator Operator <");
	check(((ik <= ik2) == (it <= it2)) , "Reverse Iterator Operator <=");
	check(((ik > ik2) == (it > it2)) , "Reverse Iterator Operator > ");
	check(((ik >= ik2) == (it >= it2)) , "Reverse Iterator Operator >=");
}

template <class T, class K>
void r_iterator_comp_t_bd(T const& t, K const& k)
{
	T a;
	K b;
	int r;
	bool verif = true;
	std::srand(std::time(nullptr));
	typename T::reverse_iterator it = a.rbegin();
	typename T::reverse_iterator it2(it);
	typename K::reverse_iterator ik = b.rbegin();
	typename K::reverse_iterator ik2(ik);
	
	for (size_t i = 0; i < 100; i++)
	{
		r = rand();
		a.push_back(r);
		b.push_back(r);
	}

	r = rand() % (int)(a.size() - 10);

	for (int j = 0; j < r; j++)
	{
		it++;
		ik++;
	}
	check(((ik == ik2) == (it == it2)) , "Reverse Iterator Operator == ");
	check(((ik++ == ik2++) == (it++ == it2++)) , "Reverse Iterator Operator it++ ");
	check(((++ik == ++ik2) == (++it == ++it2)) , "Reverse Iterator Operator ++it");
	check(((ik-- == ik2--) == (it-- == it2--)) , "Reverse Iterator Operator it-- ");
	check(((--ik == --ik2) == (--it == --it2)) , "Reverse Iterator Operator --it");
	check(((ik != ik2) == (it != it2)) , "Reverse Iterator Operator != ");
}

#	endif