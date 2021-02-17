#	ifndef SET_ITERATOR_HPP
#	define SET_ITERATOR_HPP

#include "set.hpp"

namespace Set
{
	template < class T>
	class iterator
	{
		protected:
			typedef	struct	s_set
			{
				struct s_set			*prev;
				struct s_set			*next;
				T						*value;
			}				t_set;

			t_set	*_set;
		public:
			typedef	T		value_type;
			typedef T		key_type;
			typedef char	var;

			iterator(void): _set(NULL) {}
			iterator(void* p_set): _set(static_cast<t_set *>(p_set)) {} // compilation error if the cast fails
			iterator(const iterator& oth) { *this = oth;}
			virtual ~iterator(void) {}

			t_set*			get_set(void) {return (_set);}
			value_type&		operator* (void) {return (*(this->_set->value));}

			iterator&		operator= (const iterator& oth)
			{
				_set = oth._set;
				return (*this);
			}

			bool		operator== (const iterator& oth) const {return (_set == oth._set);}
			bool		operator!= (const iterator& oth) const {return (_set != oth._set);}
			iterator&	operator++ () // equal to ++var
			{
				if (_set->next == NULL)
				{
					while (_set->prev)
						_set = _set->prev;
				}
				else
					_set = _set->next;
				return (*this);
			}

			iterator	operator++ (int) // the (int) means that ++ is after the var // equal to var++ 
			{
				iterator tmp(*this);
				operator++();
				return (tmp);
			} 

			iterator&	operator-- () // equal to --var
			{
				if (_set->prev == NULL)
				{
					while (_set->next)
						_set = _set->next;
				}
				else
					_set = _set->prev;
				return (*this);
			}

			iterator	operator-- (int) // equal to var-- 
			{
				iterator tmp(*this);
				operator--();
				return (tmp);
			} 
	};

	template < class T>
	class reverse_iterator: public iterator<T>
	{
		public:
			reverse_iterator(void): iterator<T>() {}
			reverse_iterator(void* p_set): iterator<T>(p_set) {} // compilation error if the cast fails
			reverse_iterator(const reverse_iterator& oth): iterator<T>() { this->_set = oth._set;}
			virtual ~reverse_iterator(void) {}
			reverse_iterator&	operator++ () { if (this->_set->prev == NULL){ while (this->_set->next) this->_set = this->_set->next;}  else this->_set = this->_set->prev; return (*this);} // equal to ++var
			reverse_iterator	operator++ (int) { reverse_iterator tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++
			reverse_iterator&	operator-- () { if (this->_set->next == NULL) { while (this->_set->prev) this->_set = this->_set->prev;} else this->_set = this->_set->next; return (*this);} // equal to --var
			reverse_iterator	operator-- (int) { reverse_iterator tmp(*this); operator--(); return tmp;} // equal to var--
	};
}

#	endif