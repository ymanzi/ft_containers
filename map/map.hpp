#	ifndef MAP_HPP
#	define MAP_HPP

#include <iostream>
#include <limits>
#include "../utils/ft_utils.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key> >
	class map
	{
		private:
			typedef	struct	s_map
			{
				struct s_map			*prev;
				struct s_map			*next;
				pair<const Key, T>	*value;
			}				t_map;

			size_t	_size;
			t_map	*_map;

			void	init_map()
			{ 
				_size = 0;
				_map = new t_map;
				_map->next = NULL;
				_map->prev = NULL;
				_map->value = new ft::pair<const Key, T>();
			}		
		public:
			typedef	ft::pair<const Key, T>		value_type;
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
			
			class value_compare//: public std::binary_function<value_type,value_type,bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;
					
				public:
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			
			explicit map(void): _size(0), _map(NULL) { init_map();} // default constructor
			template <class InputIterator>
			map (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_not_iterator<InputIterator>::value, std::nullptr_t>::type = NULL): _size(0) { init_map(); while (first != last) this->insert(*first++); } // range constructor
			map (const map& x): _size(0) { init_map(); *this = x;} // Copy constructor
			virtual ~map()
			{
				t_map *elem;
				
				while(_map)
				{
					elem = _map->next;
					delete _map->value;
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
					if (elem->value->first == k)
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

			ft::pair<iterator,iterator>    equal_range (const key_type& k)
			{
				iterator	it;
				iterator	it2 = begin();
				
				for ( ; it2 != end(); it2++)
				{
					if (it2->first == k)
						break ;
				}
				it = it2++;
				return  ft::pair<iterator, iterator>(it, it2);
			}

			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				bool found = false;
				iterator	it;
				iterator	it2 = begin();
				
				for ( ; it2 != end(); it2++)
				{
					if (key_comp()(it2->first, k) ==  key_comp()(k, it2->first))
					{
						found = true;
						break ;
					}
				}
				if (found)
					it = it2++;
				else
					it = it2;
				return  ft::pair<const_iterator, const_iterator>(it, it2);
			}

			size_type	erase (const key_type& k)
			{
				t_map	*elem = _map;
				t_map	*prev = NULL;
				t_map	*next = NULL;

				while (elem->next)
				{
					if (elem->value->first == k)
					{
						_size--;
						next = elem->next;
						if (prev == NULL)
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
				this->erase(it->first);
			}

			void 		erase (iterator first, iterator last)
			{
				iterator next;
				while (first != last)
				{
					next = first++;
					this->erase(next);
				}
			}

			iterator	find (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (it->first == k)
						return (it);
				}
				return (this->end());
			}

			const_iterator find (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (it->value->first == k)
						return (const_iterator(it));
				}
				return (const_iterator(this->end()));
			}

			iterator		insert (iterator position, const value_type& val)	// single element
			{
				(void)position;
				ft::pair<iterator, bool> ret = this->insert(val);
				return (ret.first);
			}

			ft::pair<iterator, bool>	insert (const value_type& val)	// fill
			{
				t_map	*n;
				t_map	*prev = NULL;
				t_map	*elem = this->_map;
				
				while (elem->next && Compare()(elem->value->first, val.first) && Compare()(val.first, elem->value->first) != Compare()(elem->value->first, val.first))
				{
					prev = elem;
					elem = elem->next;
				}
				if (elem->next && Compare()(val.first, elem->value->first) == Compare()(elem->value->first, val.first))
					return  ft::pair<iterator, bool>(iterator(elem), false);
				else
				{
					_size++;
					n = new t_map;
					n->value = new value_type(val);
					elem->prev = n;
					n->next = elem;
					n->prev = NULL;
					if (prev == NULL)
						_map = n;
					else
					{
						prev->next = n;
						n->prev = prev;
					}
					return ft::pair<iterator, bool>(iterator(n), true);	
				}
			}

			template <class InputIterator>
    		void 		insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_not_iterator<InputIterator>::value, std::nullptr_t>::type = NULL)  // range
			{
				while (first != last)
					this->insert(*first++);
			}
			
			key_compare key_comp() const
			{
				return key_compare();
			}
			
			iterator lower_bound (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare()(it->first, k))
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
				iterator it = this->begin();
				for ( ; it != this->end(); it++)
				{
					if ((*it).first == k)
						return (*it).second;
				}
				value_type buf(k, mapped_type());
				this->insert(buf);
				t_map *tmp = _map;
				mapped_type *p = &(tmp->value->second);
				while (tmp->next)
				{
					if (tmp->value->first == k)
					{
						p = &(tmp->value->second);
						break ;
					}
					tmp = tmp->next;
				}
				return *p;
			}

			reverse_iterator	rbegin(){ iterator it = end(); return reverse_iterator((--it).get_map() );}
			const_reverse_iterator	rbegin() const {iterator it = end(); return const_reverse_iterator((--it).get_map() );}
			
			reverse_iterator 	rend(){return reverse_iterator(end().get_map());}
			const_reverse_iterator rend() const { return const_reverse_iterator(this->end().get_map());}
			
			size_type			size() const {return _size;}
			
			void				swap (map& x) {map n(*this);   *this = x; x = n;}

			iterator upper_bound (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare()(it->first, k) && it->first != k)
						return (it);
				}
				return this->end();
			}

			const_iterator upper_bound (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare()(it->first, k) && it->first != k)
						return (it);
				}
				return this->end();
			}

			value_compare value_comp() const
			{
				Compare c;
				return value_compare(c);
			}
			
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
			if (it_l->first != it_r->first || it_l->second != it_r->second)
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
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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
