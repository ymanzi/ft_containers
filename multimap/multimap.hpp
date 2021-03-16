#	ifndef MULTIMAP_HPP
#	define MULTIMAP_HPP

#include <iostream>
#include <limits>
#include "../utils/ft_utils.hpp"
#include "multimap_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key> >
	class multimap
	{
		private:
			typedef	struct	s_multimap
			{
				struct s_multimap			*prev;
				struct s_multimap			*next;
				pair<Key, T>	*value;
			}				t_multimap;

			size_t	_size;
			t_multimap	*_multimap;

			void	init_multimap()
			{ 
				_size = 0;
				_multimap = new t_multimap;
				_multimap->next = NULL;
				_multimap->prev = NULL;
				_multimap->value = new ft::pair<Key, T>();
			}		
		public:
			typedef	ft::pair<Key, T>		value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;
			typedef size_t					size_type;
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef Compare					key_compare;

			typedef Multimap::iterator<key_type, mapped_type>				iterator;
			typedef const Multimap::iterator<key_type, mapped_type>			const_iterator;
			typedef Multimap::reverse_iterator<key_type, mapped_type>		reverse_iterator;
			typedef const Multimap::reverse_iterator<key_type, mapped_type>	const_reverse_iterator;
			
			class value_compare//: public std::binary_function<value_type,value_type,bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;
					
				public:
					value_compare (Compare c) : comp(c) {}  // constructed with multimap's comparison object
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			
			explicit multimap(void): _size(0), _multimap(NULL) { init_multimap();} // default constructor
			template <class InputIterator>
			multimap (InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, char>::type = char()): _size(0) { init_multimap(); while (first != last) this->insert(*first++); } // range constructor
			multimap (const multimap& x): _size(0) { init_multimap(); *this = x;} // Copy constructor
			virtual ~multimap()
			{
				t_multimap *elem;
				
				while(_multimap)
				{
					elem = _multimap->next;
					delete _multimap->value;
					delete _multimap;
					_multimap = elem;
				}
			}

			iterator			begin(){ return (iterator(_multimap));}
			const_iterator		begin() const { return (const_iterator(_multimap));}
			void 				clear(){ this->erase(this->begin(), this->end());}
			size_type count (const key_type& k) const
			{
				t_multimap		*elem;
				size_type		nbr = 0;

				elem = _multimap;
				while (elem->next)
				{
					if (elem->value->first == k)
						nbr++;
					elem = elem->next;
				}
				return (nbr);
			}

			bool				empty() const {if (_size) return (false); return (true);}
			iterator			end()
			{
				t_multimap	*elem;

				elem = _multimap;
				while (elem->next)
					elem = elem->next;
				return (iterator(elem));
			}

			const_iterator		end() const
			{
				t_multimap	*elem;

				elem = _multimap;
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
					it = it2;
					if (key_comp()(it2->first, k) ==  key_comp()(k, it2->first))
					{
						for ( ; it2 != end() && key_comp()(it2->first, k) ==  key_comp()(k, it2->first); it2++)
							;
						break ;
					}
				}
				return  ft::pair<iterator, iterator>(it, it2);
			}

			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				iterator	it;
				iterator	it2 = begin();
				
				for ( ; it2 != end(); it2++)
				{
					it = it2;
					if (key_comp()(it2->first, k) ==  key_comp()(k, it2->first))
					{
						for ( ; it2 != end() && key_comp()(it2->first, k) ==  key_comp()(k, it2->first); it2++)
							;
						break ;
					}
				}
				return  ft::pair<const_iterator, const_iterator>(it, it2);
			}

			size_type	erase (const key_type& val)
			{
				const key_type	tmp = val;
				size_t			nbr = 0;
				t_multimap	*elem = _multimap;
				t_multimap	*prev = NULL;
				t_multimap	*next = NULL;

				while (elem->next)
				{
					while (elem->next && key_comp()(elem->value->first, tmp) ==  key_comp()(tmp, elem->value->first))
					{
						_size--;
						nbr++;
						next = elem->next;
						prev = elem->prev;
						next->prev = prev;
						if (prev == NULL)
							_multimap = next;
						else
							prev->next = next;
						delete elem->value;
						delete elem;
						elem = next;
					}
					if (elem->next)
					{
						prev = elem;
						elem = elem->next;
					}
				}
				return (nbr);
			}

			void		erase (iterator it)
			{
				_size--;
				t_multimap	*elem = (t_multimap*)(it.get_multimap());
				elem->next->prev = elem->prev;
				if (elem->prev)
					elem->prev->next = elem->next;
				else
					_multimap = elem->next;
				delete elem->value;
				delete elem;
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
				return (this->insert(val));
			}

			iterator	insert (const value_type& val)	// fill
			{
				t_multimap	*n;
				t_multimap	*prev = NULL;
				t_multimap	*elem = this->_multimap;
				
				while (elem->next && key_comp()(elem->value->first, val.first))
				{
					prev = elem;
					elem = elem->next;
				}
				_size++;
				n = new t_multimap;
				n->value = new value_type(val);
				elem->prev = n;
				n->next = elem;
				n->prev = NULL;
				if (prev == NULL)
					_multimap = n;
				else
				{
					prev->next = n;
					n->prev = prev;
				}
				return iterator(n);	
			}

			template <class InputIterator>
    		void 		insert (InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, char>::type = char() )  // range
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

			size_type 			max_size() const { return (std::numeric_limits<unsigned long long>::max() / sizeof(t_multimap) );}
		
			multimap& 				operator= (const multimap& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->insert(*it);
				return (*this);
			}

			reverse_iterator	rbegin(){ iterator it = end(); return reverse_iterator((--it).get_multimap() );}
			const_reverse_iterator	rbegin() const {iterator it = end(); return const_reverse_iterator((--it).get_multimap() );}
			
			reverse_iterator 	rend(){return reverse_iterator(end().get_multimap());}
			const_reverse_iterator rend() const { return const_reverse_iterator(this->end().get_multimap());}
			
			size_type			size() const {return _size;}
			
			void				swap (multimap& x) {multimap n(*this);   *this = x; x = n;}

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
	bool	operator== (const multimap<Key, T>& lhs, const multimap<Key, T>& rhs)
	{
		Multimap::iterator<Key, T>	it_l = lhs.begin();
		Multimap::iterator<Key, T>	it_r = rhs.begin();

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
	bool	operator!= (const multimap<Key, T>& lhs, const multimap<Key, T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template < class Key, class T>
	bool	operator< (const multimap<Key, T>& lhs, const multimap<Key, T>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class Key, class T>
	bool	operator<= (const multimap<Key, T>& lhs, const multimap<Key, T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template < class Key, class T>
	bool	operator> (const multimap<Key, T>& lhs, const multimap<Key, T>& rhs)
	{
		return (rhs < lhs);
	}

	template < class Key, class T>
	bool	operator>= (const multimap<Key, T>& lhs, const multimap<Key, T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template < class Key, class T>
	void	swap (multimap<Key, T>& x, multimap<Key, T>& y) {x.swap(y);}
}

#	endif
