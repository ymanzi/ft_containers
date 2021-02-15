#	ifndef VECTOR_ITERATOR_HPP
#	define VECTOR_ITERATOR_HPP

#include "vector.hpp"

namespace Vector
{
	template < typename T >
	class iterator
	{
		protected:
			T*		_vector;

		public:
			T*		get_vector() {return this->_vector;}
			iterator(void): _vector(NULL) {}
			iterator(void* p_vector): _vector(static_cast<T *>(p_vector)) {} // compilation error if the cast fails
			iterator(const iterator<T>& oth) { *this = oth;}
			virtual ~iterator(void) {}
			T&			operator*  (void) {return (*_vector);}
			iterator&	operator=  (const iterator<T>& oth)
			{
				_vector = oth._vector;
				return (*this);
			}
			bool		operator== (const iterator<T>& oth) const {return (_vector == oth._vector);}
			bool		operator!= (const iterator<T>& oth) const {return (_vector != oth._vector);}
			bool		operator< (const iterator<T>& oth) const {return (_vector < oth._vector);}
			bool		operator<= (const iterator<T>& oth) const {return (_vector <= oth._vector);}
			bool		operator> (const iterator<T>& oth) const {return (_vector > oth._vector);}
			bool		operator>= (const iterator<T>& oth) const {return (_vector >= oth._vector);}

			iterator&	operator++ ()  // equal to ++var
			{
				_vector++;
				return (*this);
			}
			iterator	operator+ (const size_t n) // equal to ++var
			{
				iterator<T> tmp(*this);
				for (size_t i = 0; i < n; i++)
					tmp.operator++();
				return (tmp);
			}
			iterator	operator- (const size_t n) // equal to ++var
			{
				iterator<T>	tmp(*this);
				for (size_t i = 0; i < n; i++)
					tmp.operator--();
				return (tmp);
			}

			iterator&	operator-= (const size_t n) // equal to ++var
			{
				for (size_t i = 0; i < n; i++)
					operator--();
				return (*this);
			}

			iterator&	operator+= (const size_t n) // equal to ++var
			{
				for (size_t i = 0; i < n; i++)
					operator++();
				return (*this);
			}

			T&	operator[] (const size_t n) // equal to ++var
			{
				return (_vector[n]);
			}

			iterator	operator++ (int) // the (int) means that ++ is after the var // equal to var++ 
			{
				iterator<T> tmp(*this);
				operator++();
				return (tmp);
			}
			iterator&	operator-- () // equal to --var
			{
				_vector--;
				return (*this);
			}

			iterator	operator-- (int) // equal to var-- 
			{
				iterator<T> tmp(*this);
				operator--();
				return (tmp);
			}
			
	};

	template < typename T >
	class reverse_iterator: public iterator<T>
	{
		public:
			reverse_iterator(void): iterator<T>() {}
			reverse_iterator(void* p_vector): iterator<T>(p_vector) {} // compilation error if the cast fails
			reverse_iterator(const reverse_iterator<T>& oth): iterator<T>() { *this = oth;}
			virtual ~reverse_iterator(void) {}
			reverse_iterator&	operator= (const iterator<T>& oth)
			{
				this->_vector = oth._vector;
				return (*this);
			}
			reverse_iterator&	operator++ () { (this->_vector)--; return (*this);} // equal to ++var
			reverse_iterator	operator++ (int) { reverse_iterator<T> tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++
			reverse_iterator&	operator-- () { (this->_vector)++; return (*this);} // equal to --var
			reverse_iterator	operator-- (int) { reverse_iterator<T> tmp(*this); operator--(); return tmp;} // equal to var--
			reverse_iterator&	operator-= (const size_t n) // equal to ++var
			{
				for (size_t i = 0; i < n; i++)
					operator--();
				return (*this);
			}
			reverse_iterator&	operator+= (const size_t n) // equal to ++var
			{
				for (size_t i = 0; i < n; i++)
					operator++();
				return (*this);
			}
			reverse_iterator	operator+ (const size_t n) // equal to ++var
			{
				reverse_iterator<T> tmp(*this);
				for (size_t i = 0; i < n; i++)
					operator++();
				return (tmp);
			}
			reverse_iterator	operator- (const size_t n) // equal to ++var
			{
				reverse_iterator<T>	tmp(*this);
				for (size_t i = 0; i < n; i++)
					operator--();
				return (tmp);
			}


	};
}

#	endif