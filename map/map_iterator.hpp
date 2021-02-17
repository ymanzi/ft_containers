#	ifndef MAP_ITERATOR_HPP
#	define MAP_ITERATOR_HPP

#include "map.hpp"

namespace Map
{
	template < class Key, class T>
	class iterator
	{
		protected:
			typedef	struct	s_map
			{
				struct s_map			*prev;
				struct s_map			*next;
				ft::pair<Key, T>	*value;
			}				t_map;

			t_map	*_map;
		public:
			typedef	ft::pair<Key, T>		value_type;
			typedef char	var;

			static const bool input_iter = true;

			iterator(void): _map(NULL) {}
			iterator(void* p_map): _map(static_cast<t_map *>(p_map)) {} // compilation error if the cast fails
			iterator(const iterator& oth) { *this = oth;}
			virtual ~iterator(void) {}

			t_map*			get_map(void) {return (_map);}
			value_type&		operator* (void) {return (*(this->_map->value));}

			value_type		*operator->(void) {return this->_map->value;}

			iterator&		operator= (const iterator& oth)
			{
				_map = oth._map;
				return (*this);
			}

			bool		operator== (const iterator& oth) const {return (_map == oth._map);}
			bool		operator!= (const iterator& oth) const {return (_map != oth._map);}
			iterator&	operator++ () // equal to ++var
			{
				if (_map->next == NULL)
				{
					while (_map->prev)
						_map = _map->prev;
				}
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
				if (_map->prev == NULL)
				{
					while (_map->next)
						_map = _map->next;
				}
				else
					_map = _map->prev;
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
			reverse_iterator(void* p_map): iterator<Key, T>(p_map) {} // compilation error if the cast fails
			reverse_iterator(const reverse_iterator& oth): iterator<Key, T>() { this->_map = oth._map;}
			virtual ~reverse_iterator(void) {}
			reverse_iterator&	operator++ () { if (this->_map->prev == NULL){ while (this->_map->next) this->_map = this->_map->next;}  else this->_map = this->_map->prev; return (*this);} // equal to ++var
			reverse_iterator	operator++ (int) { reverse_iterator tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++
			reverse_iterator&	operator-- () { if (this->_map->next == NULL) { while (this->_map->prev) this->_map = this->_map->prev;} else this->_map = this->_map->next; return (*this);} // equal to --var
			reverse_iterator	operator-- (int) { reverse_iterator tmp(*this); operator--(); return tmp;} // equal to var--
	};
}

#	endif