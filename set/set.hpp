#	ifndef SET_HPP
#	define SET_HPP

#include <iostream>
#include <limits>
#include "../utils/ft_utils.hpp"
#include "set_iterator.hpp"

namespace ft
{
	template < class T, class Compare = ft::less<T> >
	class set
	{
		private:
			typedef	struct	s_set
			{
				struct s_set			*prev;
				struct s_set			*next;
				T						*value;
			}				t_set;

			size_t	_size;
			t_set	*_set;

			void	init_set()
			{ 
				_size = 0;
				_set = new t_set;
				_set->next = NULL;
				_set->prev = NULL;
				_set->value = new T;
			}

		public:
			typedef	T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef size_t						size_type;
			typedef T							key_type;
			typedef Compare						key_compare;

			typedef Set::iterator<key_type>					iterator;
			typedef const Set::iterator<key_type>			const_iterator;
			typedef Set::reverse_iterator<key_type>			reverse_iterator;
			typedef const Set::reverse_iterator<key_type>	const_reverse_iterator;
			
			class value_compare//: public std::binary_function<value_type,value_type,bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;
					
				public:
					value_compare (Compare c) : comp(c) {}  // constructed with set's comparison object
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x, y);
					}
			};
			
			explicit set(void): _size(0), _set(NULL) { init_set();} // default constructor
			template <class InputIterator>
			set (InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, char>::type = char()): _size(0) { init_set(); while (first != last) this->insert(*first++); } // range constructor
			set (const set& x): _size(0) { init_set(); *this = x;} // Copy constructor
			virtual ~set()
			{
				t_set *elem;
				
				while(_set)
				{
					elem = _set->next;
					delete _set->value;
					delete _set;
					_set = elem;
				}
			}

			iterator			begin(){ return (iterator(_set));}
			const_iterator		begin() const { return (const_iterator(_set));}
			void 				clear(){ this->erase(this->begin(), this->end());}
			size_type count (const key_type& k) const
			{
				t_set		*elem;

				elem = _set;
				while (elem->next)
				{
					if (*(elem->value) == k)
						return (1);
					elem = elem->next;
				}
				return (0);
			}

			bool				empty() const {if (_size) return (false); return (true);}
			iterator			end()
			{
				t_set	*elem;

				elem = _set;
				while (elem->next)
					elem = elem->next;
				return (iterator(elem));
			}

			const_iterator		end() const
			{
				t_set	*elem;

				elem = _set;
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
					if (*it2 == k)
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
					if (key_comp()(*it2, k) ==  key_comp()(k, *it2))
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
				t_set	*elem = _set;
				t_set	*prev = NULL;
				t_set	*next = NULL;

				while (elem->next)
				{
					if (*(elem->value) == k)
					{
						_size--;
						next = elem->next;
						if (prev == NULL)
						{
							_set = next;
							delete elem->value;
							delete elem;
						}
						else
						{
							next->prev = prev;
							prev->next = next;
							delete elem->value;
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
				this->erase(*it);
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
					if (*it == k)
						return (it);
				}
				return (this->end());
			}

			const_iterator find (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (*it == k)
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
				t_set	*n;
				t_set	*prev = NULL;
				t_set	*elem = this->_set;
				
				while (elem->next && Compare()(*(elem->value), val) && Compare()(val, *(elem->value)) != Compare()(*(elem->value), val))
				{
					prev = elem;
					elem = elem->next;
				}
				if (elem->next && Compare()(val, *(elem->value)) == Compare()(*(elem->value), val))
					return  ft::pair<iterator, bool>(iterator(elem), false);
				else
				{
					_size++;
					n = new t_set;
					n->value = new value_type(val);
					elem->prev = n;
					n->next = elem;
					n->prev = NULL;
					if (prev == NULL)
						_set = n;
					else
					{
						prev->next = n;
						n->prev = prev;
					}
					return ft::pair<iterator, bool>(iterator(n), true);	
				}
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
					if (!key_compare()(*it, k))
						return (it);
				}
				return this->end();
			}

			const_iterator lower_bound (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare(*it, k))
						return (it);
				}
				return this->end();
			}

			size_type 			max_size() const { return (std::numeric_limits<char>::max() / sizeof(t_set) );}
		
			set& 				operator= (const set& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->insert(*it);
				return (*this);
			}

			reverse_iterator	rbegin(){ iterator it = end(); return reverse_iterator((--it).get_set() );}
			const_reverse_iterator	rbegin() const {iterator it = end(); return const_reverse_iterator((--it).get_set() );}
			
			reverse_iterator 	rend(){return reverse_iterator(end().get_set());}
			const_reverse_iterator rend() const { return const_reverse_iterator(this->end().get_set());}
			
			size_type			size() const {return _size;}
			
			void				swap (set& x) {set n(*this);   *this = x; x = n;}

			iterator upper_bound (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare()(*it, k) && *it != k)
						return (it);
				}
				return this->end();
			}

			const_iterator upper_bound (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!key_compare()(*it, k) && *it != k)
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
	template <class T>
	bool	operator== (const ft::set<T>& lhs, const ft::set<T>& rhs)
	{
		Set::iterator<T>	it_l = lhs.begin();
		Set::iterator<T>	it_r = rhs.begin();

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
	bool	operator!= (const ft::set<T>& lhs, const ft::set<T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator< (const ft::set<T>& lhs, const ft::set<T>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T>
	bool	operator<= (const ft::set<T>& lhs, const ft::set<T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T>
	bool	operator> (const ft::set<T>& lhs, const ft::set<T>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool	operator>= (const ft::set<T>& lhs, const ft::set<T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T>
	void	swap (ft::set<T>& x, ft::set<T>& y) {x.swap(y);}
};

#	endif
