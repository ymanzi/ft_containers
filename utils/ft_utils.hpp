#	ifndef FT_UTILS_HPP
#	define FT_UTILS_HPP

#include <typeinfo>

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	};


	template<bool Condition, typename T = void>
	struct enable_if
	{
	};
	
	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<class A, class B>
	struct pair
	{
		A first;
		B second;

		pair(A one, B two): first(one), second(two){};
		pair(): first(A()), second(B()){};
	};

	template<class A>
	struct less
	{
		bool operator()(const A& __x, const A& __y) const
			{return __x < __y;}
		less(){}
	};

	// template<class T>
	// struct is_iterator
	// {
	// 	typedef T type;
	// 	bool value;

	// 	bool check(std::string const& name)
	// 	{

	// 	}
	// 	is_iterator()

	// };
}

#	endif
