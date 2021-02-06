#	ifndef MAP_HPP
#	define MAP_HPP

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

			size_t	_size;
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

			typedef Map::iterator<key_type, mapped_type>				iterator;
			typedef const Map::iterator<key_type, mapped_type>			const_iterator;
			typedef Map::reverse_iterator<key_type, mapped_type>		reverse_iterator;
			typedef const Map::reverse_iterator<key_type, mapped_type>	const_reverse_iterator;
			
			class value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			
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

			std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
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

			size_type	erase (const key_type& k)
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

			void		erase (iterator it)
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

			iterator	find (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (it->value.first == k)
						return (it);
				}
				return (this->end());
			}

			const_iterator find (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (it->value.first == k)
						return (const_iterator(it));
				}
				return (const_iterator(this->end()));
			}

			iterator		insert (iterator position, const value_type& val)	// single element
			{
				t_map	*n;
				t_map	*prev = nullptr;
				t_map	*next;
				t_map	*elem = this->_map;
				(void)position;
				
				while (elem->next && key_compare(val, elem->value.first))
				{
					prev = elem;
					elem = elem->next;
				}
				if (key_compare(val, elem->value.first) == key_compare(elem->value.first, val))
					return iterator(elem);
				else
				{
					_size++;
					n = new t_map;
					n->value = val;
					elem->prev = n;
					n->next = elem;
					n->prev = nullptr;
					if (prev == nullptr)
					{
						_map = n;
						return (iterator(_map));
					}
					else
					{
						prev->next = n;
						n->prev = prev;
					}
					return (iterator(n));	
				}
			}


			std::pair<iterator, bool>	insert (const value_type& val)	// fill
			{
				t_map	*n;
				t_map	*prev = nullptr;
				t_map	*next;
				t_map	*elem = this->_map;
				
				while (elem->next && key_compare(val, elem->value.first))
				{
					prev = elem;
					elem = elem->next;
				}
				if (elem->next && key_compare(val, elem->value.first) == key_compare(elem->value.first, val))
					return  std::pair<iterator, bool>(iterator(elem), false);
				else
				{
					_size++;
					n = new t_map;
					n->value = val;
					elem->prev = n;
					n->next = elem;
					n->prev = nullptr;
					if (prev == nullptr)
						_map = n;
					else
					{
						prev->next = n;
						n->prev = prev;
					}
					return std::pair<iterator, bool>(iterator(n), true);	
				}
			}

			template <class InputIterator>
    		void 		insert (InputIterator first, InputIterator last)  // range
			{
				iterator it;
				while (first != last)
				{
					insert(it, first->second);
					++first;
				}
			}
			
			key_compare key_comp() const
			{

				return key_compare();
			}
			
			iterator lower_bound (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare(it->first, k))
						return (it);
				}
				return this->end();
			}

			const_iterator lower_bound (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare(it->first, k))
						return (it);
				}
				return this->end();
			}

			size_type 			max_size() const { return (std::numeric_limits<char>::max() / sizeof(t_map) );}
		
			map& 				operator= (const map& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->insert(*it);
				return (*this);
			}
			
			mapped_type& operator[] (const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if ((*it).first == k)
						return (*it).second;
				}
				std::pair<iterator,bool> buf;
				value_type tmp;
				buf = this->insert(tmp);
				return *(buf.first);
			}

			reverse_iterator	rbegin(){ iterator it = end(); return reverse_iterator(--it);}
			const_reverse_iterator	rbegin() const {iterator it = end(); return const_reverse_iterator(--it);}
			
			reverse_iterator 	rend(){return reverse_iterator(end());}
			const_reverse_iterator rend() const { return const_reverse_iterator(this->end());}
			
			size_type			size() const {return _size;}
			
			void				swap (map& x) {map n(*this);   *this = x; x = n;}

			iterator upper_bound (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare(it->first, k) && it->first != k)
						return (it);
				}
				return this->end();
			}

			const_iterator upper_bound (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare(it->first, k) && it->first != k)
						return (it);
				}
				return this->end();
			}

			/*value_compare value_comp() const
			{
				return value_compare();
			}*/
			
	};

	//relational operators
	template < class Key, class T>
	bool	operator== (const map<Key, T>& lhs, const map<Key, T>& rhs)
	{
		Map::iterator<Key, T>	it_l = lhs.begin();
		Map::iterator<Key, T>	it_r = rhs.begin();

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

	template < class Key, class T>
	bool	operator!= (const map<Key, T>& lhs, const map<Key, T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template < class Key, class T>
	bool	operator< (const map<Key, T>& lhs, const map<Key, T>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class Key, class T>
	bool	operator<= (const map<Key, T>& lhs, const map<Key, T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template < class Key, class T>
	bool	operator> (const map<Key, T>& lhs, const map<Key, T>& rhs)
	{
		return (rhs < lhs);
	}

	template < class Key, class T>
	bool	operator>= (const map<Key, T>& lhs, const map<Key, T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template < class Key, class T>
	void	swap (map<Key, T>& x, map<Key, T>& y) {x.swap(y);}
}

#	endif
