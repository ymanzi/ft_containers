#	ifndef DEQUE_ITERATOR_HPP
#	define DEQUE_ITERATOR_HPP

#include "deque.hpp"

namespace Deque
{
	template < typename T >
	class iterator
	{
		protected:
			typedef struct	s_deque
			{
				struct s_deque	*prev;
				struct s_deque	*next;
				T				value;
			}				t_deque;
			void	begin()
			{
				while (_deque->prev)
					_deque = _deque->prev;
			}
			void	end()
			{
				while (_deque->next)
					_deque = _deque->next;
			}

			t_deque	*_deque;
		public:
			typedef char	var;
			iterator(void): _deque(NULL) {}
			iterator(void* p_deque): _deque(static_cast<t_deque *>(p_deque)) {} // compilation error if the cast fails
			iterator(const iterator<T>& oth) { *this = oth;}
			virtual ~iterator(void) {}

			t_deque*		get_deque(void) {return (_deque);}
			T&			operator*  (void) {return (_deque->value);}
			iterator&	operator=  (const iterator<T>& oth)
			{
				_deque = oth._deque;
				return (*this);
			}
			bool		operator== (const iterator<T>& oth) const {return (_deque == oth._deque);}
			bool		operator!= (const iterator<T>& oth) const {return (_deque != oth._deque);}
			bool		operator< (const iterator<T>& oth) const {return (_deque < oth._deque);}
			bool		operator<= (const iterator<T>& oth) const {return (_deque <= oth._deque);}
			bool		operator> (const iterator<T>& oth) const {return (_deque > oth._deque);}
			bool		operator>= (const iterator<T>& oth) const {return (_deque >= oth._deque);}
			
			iterator&	operator++ () // equal to ++var
			{
				if (_deque->next == NULL)
					this->begin();
				else
					_deque = _deque->next;
				return (*this);
			}

			iterator	operator+ (const size_t n)
			{
				iterator tmp(*this);
				for (size_t i = 0; i < n; i++)
					tmp.operator++();
				return (tmp);
			}

			iterator	operator- (const size_t n) 
			{
				iterator	tmp(*this);
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

			T	operator[] (const size_t n) // equal to ++var
			{
				iterator	tmp(*this);
				for (size_t i = 0; i < n; i++)
					tmp.operator++();
				return (*tmp);
			}

			iterator	operator++ (int) // the (int) means that ++ is after the var // equal to var++ 
			{
				iterator<T> tmp(*this);
				operator++();
				return (tmp);
			} 

			iterator&	operator-- () // equal to --var
			{
				if (_deque->prev == NULL)
					this->end();
				else
					_deque = _deque->prev;
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
			reverse_iterator(void* p_deque): iterator<T>(p_deque) {} // compilation error if the cast fails
			reverse_iterator(const reverse_iterator<T>& oth): iterator<T>() { this->_deque = oth._deque;}
			virtual ~reverse_iterator(void) {}
			reverse_iterator&	operator++ () { if (this->_deque->prev == 0) this->end(); else this->_deque = this->_deque->prev; return (*this);} // equal to ++var
			reverse_iterator	operator++ (int) { reverse_iterator<T> tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++
			reverse_iterator&	operator-- () { if (this->_deque->next == 0) this->begin(); else this->_deque = this->_deque->next; return (*this);} // equal to --var
			reverse_iterator	operator-- (int) { reverse_iterator<T> tmp(*this); operator--(); return tmp;} // equal to var--
			T	operator[] (const size_t n) // equal to ++var
			{
				reverse_iterator	tmp(*this);
				for (size_t i = 0; i < n; i++)
					tmp.operator++();
				return (*tmp);
			}

			reverse_iterator&	operator+= (const size_t n) // equal to ++var
			{
				for (size_t i = 0; i < n; i++)
					operator++();
				return (*this);
			}

			reverse_iterator&	operator-= (const size_t n) // equal to ++var
			{
				for (size_t i = 0; i < n; i++)
					operator--();
				return (*this);
			}

			reverse_iterator	operator+ (const size_t n)
			{
				reverse_iterator tmp(*this);
				for (size_t i = 0; i < n; i++)
					tmp.operator++();
				return (tmp);
			}

			reverse_iterator	operator- (const size_t n) 
			{
				reverse_iterator	tmp(*this);
				for (size_t i = 0; i < n; i++)
					tmp.operator--();
				return (tmp);
			}

	};
}

#	endif