#	ifndef MAP_HPP
#	define MAP_HPP

#include <iostream>
#include <limits>
#include <stdexcept>
// #include "map_iterator.hpp"
#include "lexicographical_compare.hpp"
#include <utility>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key> >
	class map
	{
		private:
			typedef struct	s_map
			{
				std::pair<const Key, T> elem;
				struct s_map			*next;
				struct s_map			*prev;
			}				t_map;

			size_t	_size;
			t_map		*_map;

			void	init_map()
			{ 
				_size = 0;
				_map = new t_map;
				_map->next = nullptr;
				_map->prev = nullptr;
				
			}

			size_t	get_indice(Vector::iterator<T> &position)
			{
				T*		ptr = (T*)(position.get_map());
				for (size_t i = 0; i < _size; i++)
				{
					if (this->_map + i == ptr)
						return (i);
				}
				return (_size - 1);
			}

		public:
			typedef	std::pair<const Key, T>		value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef ptrdiff_t					difference_type;
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef Compare						key_compare;
			typedef size_t						size_type;

			typedef Vector::iterator<value_type>			iterator;
			typedef const Vector::iterator<value_type>	const_iterator;
			typedef Vector::reverse_iterator<value_type>		reverse_iterator;
			typedef const Vector::reverse_iterator<value_type>	const_reverse_iterator;
			

			explicit map (const key_compare& comp = key_compare()){init_map();} // default constructor
			// template <class InputIterator>
			// map (InputIterator first, InputIterator last) { init_map(); this->insert(this->begin(), first, last); } // range constructor
			map (const map& x) { init_map(); *this = x;} // Copy constructor
			virtual ~map(){ _size = 0; delete _map; } //Destructor

			iterator			begin(){ return (iterator(_map));}
			// const_iterator		begin() const { return const_iterator(_map);}
			// size_type			capacity() const {return _max_size;}
			// void 				clear()
			// {
			// 	delete _map;
			// 	init_map();
			// }

			// bool				empty() const {if (_size) return (false); return (true);}
			// iterator			end() {return (iterator(_map + _size));}
			// const_iterator		end() const {return (const_iterator(_map + _size));}
			// iterator			erase (iterator position)
			// {
			// 	size_t	i = (size_t)(get_indice(position));
			// 	_size--;
			// 	while (i < _size)
			// 	{
			// 		_map[i] = _map[i + 1];
			// 		i++;
			// 	}
			// 	return (position);
			// }

			// iterator 			erase (iterator first, iterator last)
			// {
			// 	size_t	elem_f = (size_t)(get_indice(first));
			// 	size_t	elem_l = (size_t)(get_indice(last));
			// 	size_t	i = elem_f;
				
			// 	while (i < _size && elem_l + i < _size)
			// 	{
			// 		_map[i] = _map[elem_l + i];
			// 		i++;
			// 	}
			// 	_size -= (elem_l - elem_f);
			// 	return (last);
			// }
			// reference			front() {return (_map[0]);}
			// const_reference		front() const {return (const_cast<const_reference>(front()));}
			// iterator			insert (iterator position, const value_type& val)	// single element
			// {
			// 	size_t	elem = (size_t)(get_indice(position));
			// 	size_t	i = 0;
			// 	if (_size + 1 >= _max_size)
			// 		new_size(_size + 5);
			// 	map	n(*this);
			// 	_map[elem] = val;
			// 	while (elem + i < _size)
			// 	{
			// 		_map[elem + i + 1] = n._map[elem + i];
			// 		i++;
			// 	}
			// 	_size++;
			// 	return (position);
			// }
			// void				insert (iterator position, size_type nbr, const value_type& val)	// fill
			// {
			// 	while (nbr--)
			// 		insert(position, val);
			// }
			// template <class InputIterator>
    		// void 				insert (iterator position, InputIterator first, InputIterator last)  // range
			// {
			// 	while (first != last)
			// 	{
			// 		insert(position, *first);
			// 		++first;
			// 	}
			// }
			// size_type 			max_size() const { return (std::numeric_limits<char>::max() / sizeof(T));}
			// map& 				operator= (const map& oth)
			// {
			// 	this->clear();
			// 	for (iterator it = oth.begin(); it != oth.end(); it++ )
			// 		this->push_back(*it);
			// 	return (*this);
			// }
			// reference 		operator[] (size_type n) {if (n >= _size) return (_map[_size - 1]); return _map[n];}
			// const_reference operator[] (size_type n) const {return const_cast<const T>(_map[n]);}
			// void				pop_back()
			// {
			// 	_size--;
			// }
			// void				pop_front()
			// {
			// 	this->erase(this->begin());
			// }
			// void				push_back (const value_type& val)
			// {
			// 	if (_size + 1 <= _max_size)
			// 		new_size(_size + 5);
			// 	this->_map[_size] = val;
			// 	_size++;
			// }
			// reverse_iterator	rbegin(){if (!_size) return (reverse_iterator(_map));  return (reverse_iterator(_map + _size - 1));}
			// const_reverse_iterator	rbegin() const {if (!_size) return (const_reverse_iterator(_map));  return (const_reverse_iterator(_map + _size - 1));}
			// reverse_iterator 	rend(){ return reverse_iterator(_map - 1);}
			// const_reverse_iterator rend() const { return const_reverse_iterator(_map - 1) ;}
			// void				reserve (size_type n) { if (n > _max_size) new_size(n); }
			// void 				resize (size_type n, value_type val = value_type())
			// {
			// 	new_size(n, val);
			// 	_size = n;
			// }
			// size_type			size() const {return _size;}
			// void				swap (map& x) {map<T> n(*this);   *this = x; x = n;}
	};

	// relational operators
	// template <class T>
	// bool	operator== (const map<T>& lhs, const map<T>& rhs)
	// {
	// 	Vector::iterator<T>	it_l = lhs.begin();
	// 	Vector::iterator<T>	it_r = rhs.begin();

	// 	if (lhs.size() != rhs.size())
	// 		return (false);
	// 	while (it_l != lhs.end() && it_r != rhs.end())
	// 	{
	// 		if (*it_l != *it_r)
	// 			return (false);
	// 		++it_l;
	// 		++it_r;
	// 	}
	// 	return (true);
	// }

	// template <class T>
	// bool	operator!= (const map<T>& lhs, const map<T>& rhs)
	// {
	// 	return (!(lhs == rhs));
	// }

	// template <class T>
	// bool	operator< (const map<T>& lhs, const map<T>& rhs)
	// {
	// 	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	// }

	// template <class T>
	// bool	operator<= (const map<T>& lhs, const map<T>& rhs)
	// {
	// 	return (!(rhs < lhs));
	// }

	// template <class T>
	// bool	operator> (const map<T>& lhs, const map<T>& rhs)
	// {
	// 	return (rhs < lhs);
	// }

	// template <class T>
	// bool	operator>= (const map<T>& lhs, const map<T>& rhs)
	// {
	// 	return (!(lhs < rhs));
	// }

	// template <class T>
	// void	swap (map<T>& x, map<T>& y) {x.swap(y);}
}
#	endif
