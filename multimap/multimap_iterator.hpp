#	ifndef MULTIMAP_ITERATOR_HPP
#	define MULTIMAP_ITERATOR_HPP

#include "multimap.hpp"

namespace Multimap
{
	template < class Key, class T>
	class iterator
	{
		protected:
			typedef	struct	s_multimap
			{
				struct s_multimap			*prev;
				struct s_multimap			*next;
				ft::pair<Key, T>	*value;
			}				t_multimap;

			t_multimap	*_multimap;
		public:
			typedef	ft::pair<Key, T>		value_type;
			typedef char	var;

			static const bool input_iter = true;

			iterator(void): _multimap(NULL) {}
			iterator(void* p_multimap): _multimap(static_cast<t_multimap *>(p_multimap)) {} // compilation error if the cast fails
			iterator(const iterator& oth) { *this = oth;}
			virtual ~iterator(void) {}

			t_multimap*			get_multimap(void) {return (_multimap);}
			value_type&		operator* (void) {return (*(this->_multimap->value));}

			value_type		*operator->(void) {return this->_multimap->value;}

			iterator&		operator= (const iterator& oth)
			{
				_multimap = oth._multimap;
				return (*this);
			}

			bool		operator== (const iterator& oth) const {return (_multimap == oth._multimap);}
			bool		operator!= (const iterator& oth) const {return (_multimap != oth._multimap);}
			iterator&	operator++ () // equal to ++var
			{
				if (_multimap->next == NULL)
				{
					while (_multimap->prev)
						_multimap = _multimap->prev;
				}
				else
					_multimap = _multimap->next;
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
				if (_multimap->prev == NULL)
				{
					while (_multimap->next)
						_multimap = _multimap->next;
				}
				else
					_multimap = _multimap->prev;
				return (*this);
			}

			iterator	operator-- (int) // equal to var-- 
			{
				iterator tmp(*this);
				operator--();
				return (tmp);
			} 
	};

	template < class Key, class T>
	class reverse_iterator: public iterator<Key, T>
	{
		public:
			reverse_iterator(void): iterator<Key, T>() {}
			reverse_iterator(void* p_multimap): iterator<Key, T>(p_multimap) {} // compilation error if the cast fails
			reverse_iterator(const reverse_iterator& oth): iterator<Key, T>() { this->_multimap = oth._multimap;}
			virtual ~reverse_iterator(void) {}
			reverse_iterator&	operator++ () { if (this->_multimap->prev == NULL){ while (this->_multimap->next) this->_multimap = this->_multimap->next;}  else this->_multimap = this->_multimap->prev; return (*this);} // equal to ++var
			reverse_iterator	operator++ (int) { reverse_iterator tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++
			reverse_iterator&	operator-- () { if (this->_multimap->next == NULL) { while (this->_multimap->prev) this->_multimap = this->_multimap->prev;} else this->_multimap = this->_multimap->next; return (*this);} // equal to --var
			reverse_iterator	operator-- (int) { reverse_iterator tmp(*this); operator--(); return tmp;} // equal to var--
	};
}

#	endif