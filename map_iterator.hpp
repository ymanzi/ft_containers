#	ifndef LIST_ITERATOR_HPP
#	define LIST_ITERATOR_HPP

#include "map.hpp"

namespace List
{
	template < class Key, class T>
	class iterator
	{
		protected:
			typedef	struct	s_map
			{
				struct s_map			*prev;
				struct s_map			*next;
				std::pair<const Key, T>	value;
			}				t_map;

			t_map	*_map;
		public:
			typedef	std::pair<const Key, T>		value_type;


			iterator(void): _map(nullptr) {}
			iterator(void* p_map): _map(static_cast<t_map *>(p_map)) {} // compilation error if the cast fails
			iterator(const iterator& oth) { *this = oth;}
			virtual ~iterator(void) {}

			t_map*			get_map(void) {return (_map);}
			value_type&		operator* (void) {return (_map->value);}
			iterator&		operator= (const iterator& oth)
			{
				_map = oth._map;
				return (*this);
			}
			bool		operator== (const iterator& oth) const {return (_map == oth._map);}
			bool		operator!= (const iterator& oth) const {return (_map != oth._map);}
			iterator&	operator++ () // equal to ++var
			{
				if (_map->next == nullptr)
					raise(SIGSEGV);
				else
					_map = _map->next;
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
				if (_map->prev == nullptr)
					raise(SIGSEGV);
				else
					_map = _map->prev;
				return (*this);
			}

			iterator	operator-- (int) // equal to var-- 
			{
				iterator<T> tmp(*this);
				operator--();
				return (tmp);
			} 
	};

	template < class Key, class T>
	class reverse_iterator: public iterator<Key, T>
	{
		public:
			reverse_iterator(void): iterator<Key, T>() {}
			reverse_iterator(void* p_map): iterator(p_map) {} // compilation error if the cast fails
			reverse_iterator(const reverse_iterator& oth): iterator<Key, T>() { this->_map = oth._map;}
			virtual ~reverse_iterator(void) {}
			reverse_iterator&	operator++ () { if (this->_map->prev == nullptr) raise (SIGSEGV); else this->_map = this->_map->prev; return (*this);} // equal to ++var
			reverse_iterator	operator++ (int) { reverse_iterator tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++
			reverse_iterator&	operator-- () { if (this->_map->next == nullptr) raise (SIGSEGV); else this->_map = this->_map->next; return (*this);} // equal to --var
			reverse_iterator	operator-- (int) { reverse_iterator<T> tmp(*this); operator--(); return tmp;} // equal to var--
	};
}

#	endif