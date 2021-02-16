#	ifndef FT_UTILS_HPP
#	define FT_UTILS_HPP

#include <typeinfo>

namespace ft
{
	template<bool Condition, typename T = void>
	struct enable_if
	{
	};
	
	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<class A>
	struct less
	{
		bool operator()(const A& __x, const A& __y) const
			{return __x < __y;}
		less(){}
	};

	template<class A, class B, class Compare = ft::less<A> >
	struct pair
	{
		A first;
		B second;

		pair(A one, B two): first(one), second(two){};
		pair(): first(A()), second(B()){};
	};

	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	};	

	template<class T>
	struct is_not_iterator
	{
		// static bool value;
		typedef T type;
		typedef std::true_type value;

		bool val;
		bool check(std::string const& name)
		{
			if (name.find("iterator") != std::string::npos)
				return (false);
			return true;
		}
		
		is_not_iterator()
		{
			T var;
			val = check(typeid(var).name());
		}
	};
}

#	endif
