#	ifndef LIST_HPP
#	define LIST_HPP

#include <iostream>
#include <limits>
#include "map_iterator.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key> >
	class map
	{
		private:
			typedef	struct	s_map
			{
				struct s_map			*prev;
				struct s_map			*next;
				std::pair<const Key, T>	value;
			}				t_map;

			size_t			_size;
			t_map	*_map;

			void	init_map()
			{ 
				_size = 0;
				_map = new t_map;
				_map->next = nullptr;
				_map->prev = nullptr;
				_map->value = std::pair<const Key, T>();
			}
		
		public:
			typedef	std::pair<const Key, T>		value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef ptrdiff_t					difference_type;
			typedef size_t						size_type;
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef Compare						key_compare;

			typedef Map::iterator<value_type>				iterator;
			typedef const Map::iterator<value_type>			const_iterator;
			typedef Map::reverse_iterator<value_type>		reverse_iterator;
			typedef const Map::reverse_iterator<value_type>	const_reverse_iterator;
			virtual ~map()
			{
				t_map *elem;
				
				while(_map)
				{
					elem = _map->next;
					delete _map;
					_map = elem;
				}
			}
			
			explicit map(void): _size(0), _map(nullptr) { init_map();} // default constructor
			explicit map (size_type n, const value_type& val = value_type()): _size(0) { init_map(); while (n--) push_back(val); } // fill constructor
			template <class InputIterator>
			map (InputIterator first, InputIterator last): _size(0) { init_map(); this->insert(this->begin(), first, last); } // range constructor
			map (const map& x): _size(0) { init_map(); *this = x;} // Copy constructor
			virtual ~map()
			{
				t_map *elem;
				
				while(_map)
				{
					elem = _map->next;
					delete _map;
					_map = elem;
				}
			}

			iterator			begin(){ return (iterator(_map));}
			const_iterator		begin() const { return (const_iterator(_map));}
			void 				clear(){ this->erase(this->begin(), this->end());}
			size_type count (const key_type& k) const
			{
				t_map		*elem;

				elem = _map;
				while (elem->next)
				{
					if (elem->value.first == k)
						return (1);
					elem = elem->next;
				}
				return (0);
			}

			bool				empty() const {if (_size) return (false); return (true);}
			iterator			end()
			{
				t_map	*elem;

				elem = _map;
				while (elem->next)
					elem = elem->next;
				return (iterator(elem));
			}

			const_iterator		end() const
			{
				t_map	*elem;

				elem = _map;
				while (elem->next)
					elem = elem->next;
				return (const_iterator(elem));
			}

			std::pair<iterator,iterator>    equal_range (const key_type& k)
			{
				iterator	it;
				iterator	it2 = begin();
				
				for ( ; it2 != end(); it2++)
				{
					if (it2->first == k)
						break ;
				}
				it = it2++;
				return  std::pair<iterator, iterator>(it, it2);
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				iterator	it;
				iterator	it2 = begin();
				
				for ( ; it2 != end(); it2++)
				{
					if (it2->first == k)
						break ;
				}
				it = it2++;
				return  std::pair<const_iterator, const_iterator>(it, it2);
			}

			size_type erase (const key_type& k)
			{
				t_map	*elem = _map;
				t_map	*prev = nullptr;
				t_map	*next = nullptr;

				while (elem->next)
				{
					if (elem->value.first == k)
					{
						next = elem->next;
						if (prev == nullptr)
						{
							_map = next;
							delete elem;
						}
						else
						{
							next->prev = prev;
							prev->next = next;
							delete elem;
						}
						return (1);
					}
					prev = elem;
					elem = elem->next;
				}
				return (0);
			}

			void			erase (iterator it)
			{
				this->erase(it->value.first);
			}

			void 		erase (iterator first, iterator last)
			{
				iterator next;
				while (first != last)
				{
					next = first->next;
					this->erase(first);
					first = next;
				}
			}
			reference			front() {return (_map->value);}
			const_reference		front() const {return (const_cast<const_reference>(front()));}
			iterator			insert (iterator position, const value_type& val)	// single element
			{
				t_map	*n;
				t_map	*elem;

				n = new t_map;
				elem = (t_map*)(position.get_map());
				
				_size++;
				n->value = val;
				n->prev = elem->prev;
				n->next = elem;
				if (elem == this->_map)
					this->_map = n;
				else
					elem->prev->next = n;
				elem->prev = n;
				return (iterator(n));
			}
			void				insert (iterator position, size_type nbr, const value_type& val)	// fill
			{
				while (nbr--)
					insert(position, val);
			}
			template <class InputIterator>
    		void 				insert (iterator position, InputIterator first, InputIterator last)  // range
			{
				while (first != last)
				{
					insert(position, *first);
					++first;
				}
			}
			size_type 			max_size() const { return (std::numeric_limits<char>::max() / sizeof(t_map) );}
			void				merge (map& x)
			{
				if ( *this != x)
				{
					map	n;
					if (this->size())
						n.splice(n.begin(), *this);
					if (x.size())
						n.splice(n.begin(), x);
					n.sort();
					*this = n;
				}
			}
			template <class Compare>
  			void				merge (map& x, Compare comp)
			  {
				if ( *this != x)
				{
					map	n;
					n.splice(n.begin(), *this);
					n.splice(n.begin(), x);
					n.sort(comp);
					*this = n;
				}
			}
			map& 				operator= (const map& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->push_back(*it);
				return (*this);
			}
			void				pop_back()
			{
				t_map	*elem;

				elem = _map;
				if (_size == 0)
					return;
				else if (_size == 1)
					this->pop_front();
				else
				{
					_size--;
					while (elem->next->next)
						elem = elem->next;
					elem->prev->next = elem->next;
					elem->next->prev = elem->prev;
					delete elem;
				}
			}
			void				pop_front()
			{
				if (_size)
				{
					t_map	*elem;
					
					elem = _map;
					_size--;
					_map = elem->next;
					elem->next->prev = nullptr;
					delete elem;
				}
			}
			void				push_back (const value_type& val)
			{
				t_map	*n;
				t_map	*elem;

				elem = back_e();
				if (_size == 0)
					push_front(val);
				else
				{
					_size++;
					n = new t_map;
					n->next = elem->next;
					n->value = val;
					n->prev = elem;
					elem->next = n;
				}
			}
			void				push_front (const value_type& val)
			{
				t_map	*n;

				_size++;
				n = new t_map;
				n->next = _map;
				n->value = val;
				n->prev = nullptr;
				_map->prev = n;
				_map = n;
			}
			reverse_iterator	rbegin(){return (reverse_iterator(back_e()));}
			const_reverse_iterator	rbegin() const {return (const_reverse_iterator(&back()));}
			void				remove (const value_type& val)
			{
				t_map	*tmp;
				t_map	*elem;

				elem = _map;
				while (elem->next)
				{
					tmp = elem->next;
					if (elem->value == val)
					{
						_size--;
						if (elem == _map)
							_map = tmp;
						this->del_one(*elem);
					}
					elem = tmp;
				}
			}
			template <class Predicate>
  			void 				remove_if (Predicate pred)
			{
				t_map	*tmp;
				t_map	*elem;

				elem = _map;
				while (elem->next)
				{
					tmp = elem->next;
					if (pred(elem->value))
					{
						_size--;
						if (elem == _map)
							_map = tmp;
						this->del_one(elem);
					}
					elem = tmp;
				}
			}
			reverse_iterator 	rend(){ return reverse_iterator(back_e()->next);}
			const_reverse_iterator rend() const { return const_reverse_iterator(this->end()) ;}
			void 				resize (size_type n, value_type val = value_type())
			{
				size_t		i = 0;
				iterator	i_end = this->end();
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					i++;
					if (i > n)
					{
						this->erase(it, i_end);
						return ;
					}
				}
				if (n > i)
				{
					n -= i;
					insert(i_end, n, val);
				}
			}
			void				reverse()
			{
				map elem(*this);

				this->clear();
				for (iterator it = elem.begin(); it != elem.end(); it++)
					this->push_front(*it);
			}
			size_type			size() const {return _size;}
			void				sort()
			{
				iterator	min;
				T			tmp;

				for (Map::iterator<T> it1 = this->begin(); it1 != this->end(); ++it1)
				{
					min = it1;
					for (Map::iterator<T> it2(it1); it2 != this->end(); ++it2)
					{
						if (*min > *it2)
							min = it2;
					}
					tmp = *it1;
					*it1 = *min;
					*min = tmp;
				}
			}
			template <class Compare>
  			void				sort (Compare comp)
			{
				iterator	min;
				T			tmp;

				for (iterator it1 = this->begin(); it1 != this->end(); it1++)
				{
					min = it1;
					for (iterator it2 = it1; it2 != this->end(); it2++)
					{
						if (comp(*it2, *min))
							min = it2;
					}
					if (comp(*min, *it1))
					{
						tmp = *it1;
						*it1 = *min;
						*min = tmp;
					}
				}
			}
			void				splice (iterator position, map& x) { insert(position, x.begin(), x.end());} //entire map
			void 				splice (iterator position, map& x, iterator i) // single element
			{
				for (iterator it = x.begin(); it != x.end(); it++)
				{
					if (it == i)
					{
						insert(position, *i);
						return ;
					}
				}
			} 
			void				splice (iterator position, map& x, iterator first, iterator last) // element range
			{
				for (iterator it = x.begin(); it != x.end(); it++)
				{
					if (it == first)
					{
						insert(position, first, last);
						return ;
					}
				}
			} 
			void				swap (map& x) {map<T> n(*this);   *this = x; x = n;}
			void				unique()
			{
				t_map		*tmp;
				t_map		*elem;
				T			val;
				bool		set;

				set = true;
				elem = _map;
				while (elem->next)
				{
					val = elem->value;
					elem = elem->next;
					while (elem && elem->next && val == elem->value)
					{
						iterator start(elem);
						tmp = elem->next;
						erase(start);
						set = false;
						elem = tmp;
					}
					if (set)
						elem = elem->next;
				}
			}
			template <class BinaryPredicate>
  			void				unique (BinaryPredicate binary_pred)
			{
				t_map		*tmp;
				t_map		*elem;
				T			val;
				bool		set;

				set = true;
				elem = _map;
				while (elem->next)
				{
					val = elem->value;
					elem = elem->next;
					while (elem->next && binary_pred(elem->value, val))
					{
						iterator start(elem);
						tmp = elem->next;
						erase(start);
						set = false;
						elem = tmp;
					}
					if (set)
						elem = elem->next;
				}
			}
	};

	//relational operators
	template <class T>
	bool	operator== (const map<T>& lhs, const map<T>& rhs)
	{
		Map::iterator<T>	it_l = lhs.begin();
		Map::iterator<T>	it_r = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (it_l != lhs.end() && it_r != rhs.end())
		{
			if (*it_l != *it_r)
				return (false);
			++it_l;
			++it_r;
		}
		return (true);
	}

	template <class T>
	bool	operator!= (const map<T>& lhs, const map<T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator< (const map<T>& lhs, const map<T>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T>
	bool	operator<= (const map<T>& lhs, const map<T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T>
	bool	operator> (const map<T>& lhs, const map<T>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool	operator>= (const map<T>& lhs, const map<T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T>
	void	swap (map<T>& x, map<T>& y) {x.swap(y);}
}

#	endif
