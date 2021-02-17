#	ifndef MULTISET_ITERATOR_HPP
#	define MULTISET_ITERATOR_HPP

#include "multiset.hpp"

namespace Multiset
{
	template < class T>
	class iterator
	{
		protected:
			typedef	struct	s_multiset
			{
				struct s_multiset			*prev;
				struct s_multiset			*next;
				T						*value;
			}				t_multiset;

			t_multiset	*_multiset;
		public:
			typedef	T		value_type;
			typedef T		key_type;
			typedef char	var;

			iterator(void): _multiset(NULL) {}
			iterator(void* p_multiset): _multiset(static_cast<t_multiset *>(p_multiset)) {} // compilation error if the cast fails
			iterator(const iterator& oth) { *this = oth;}
			virtual ~iterator(void) {}

			t_multiset*			get_multiset(void) {return (_multiset);}
			value_type&		operator* (void) {return (*(this->_multiset->value));}

			iterator&		operator= (const iterator& oth)
			{
				_multiset = oth._multiset;
				return (*this);
			}

			bool		operator== (const iterator& oth) const {return (_multiset == oth._multiset);}
			bool		operator!= (const iterator& oth) const {return (_multiset != oth._multiset);}
			iterator&	operator++ () // equal to ++var
			{
				if (_multiset->next == NULL)
				{
					while (_multiset->prev)
						_multiset = _multiset->prev;
				}
				else
					_multiset = _multiset->next;
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
				if (_multiset->prev == NULL)
				{
					while (_multiset->next)
						_multiset = _multiset->next;
				}
				else
					_multiset = _multiset->prev;
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
			reverse_iterator(void* p_multiset): iterator<T>(p_multiset) {} // compilation error if the cast fails
			reverse_iterator(const reverse_iterator& oth): iterator<T>() { this->_multiset = oth._multiset;}
			virtual ~reverse_iterator(void) {}
			reverse_iterator&	operator++ () { if (this->_multiset->prev == NULL){ while (this->_multiset->next) this->_multiset = this->_multiset->next;}  else this->_multiset = this->_multiset->prev; return (*this);} // equal to ++var
			reverse_iterator	operator++ (int) { reverse_iterator tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++
			reverse_iterator&	operator-- () { if (this->_multiset->next == NULL) { while (this->_multiset->prev) this->_multiset = this->_multiset->prev;} else this->_multiset = this->_multiset->next; return (*this);} // equal to --var
			reverse_iterator	operator-- (int) { reverse_iterator tmp(*this); operator--(); return tmp;} // equal to var--
	};
}

#	endif