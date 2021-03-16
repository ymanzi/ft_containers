#	ifndef MULTISET_HPP
#	define MULTISET_HPP

#include <iostream>
#include <limits>
#include "../utils/ft_utils.hpp"
#include "multiset_iterator.hpp"

namespace ft
{
	template < class T, class Compare = ft::less<T> >
	class multiset
	{
		private:
			typedef	struct	s_multiset
			{
				struct s_multiset			*prev;
				struct s_multiset			*next;
				T						*value;
			}				t_multiset;

			size_t	_size;
			t_multiset	*_multiset;

			void	init_multiset()
			{ 
				_size = 0;
				_multiset = new t_multiset;
				_multiset->next = NULL;
				_multiset->prev = NULL;
				_multiset->value = new T;
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

			typedef Multiset::iterator<key_type>					iterator;
			typedef const Multiset::iterator<key_type>			const_iterator;
			typedef Multiset::reverse_iterator<key_type>			reverse_iterator;
			typedef const Multiset::reverse_iterator<key_type>	const_reverse_iterator;
			
			class value_compare//: public std::binary_function<value_type,value_type,bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;
					
				public:
					value_compare (Compare c) : comp(c) {}  // constructed with multiset's comparison object
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x, y);
					}
			};
			
			explicit multiset(void): _size(0), _multiset(NULL) { init_multiset();} // default constructor
			template <class InputIterator>
			multiset (InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, char>::type = char()): _size(0) { init_multiset(); while (first != last) this->insert(*first++); } // range constructor
			multiset (const multiset& x): _size(0) { init_multiset(); *this = x;} // Copy constructor
			virtual ~multiset()
			{
				t_multiset *elem;
				
				while(_multiset)
				{
					elem = _multiset->next;
					delete _multiset->value;
					delete _multiset;
					_multiset = elem;
				}
			}

			iterator			begin(){ return (iterator(_multiset));}
			const_iterator		begin() const { return (const_iterator(_multiset));}
			void 				clear(){ this->erase(this->begin(), this->end());}
			size_type count (const key_type& k) const
			{
				t_multiset		*elem;
				size_type		nbr = 0;

				elem = _multiset;
				while (elem->next)
				{
					if (*(elem->value) == k)
						nbr++;
					elem = elem->next;
				}
				return (nbr);
			}

			bool				empty() const {if (_size) return (false); return (true);}
			iterator			end()
			{
				t_multiset	*elem;

				elem = _multiset;
				while (elem->next)
					elem = elem->next;
				return (iterator(elem));
			}

			const_iterator		end() const
			{
				t_multiset	*elem;

				elem = _multiset;
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
					if (key_comp()(*it2, k) ==  key_comp()(k, *it2))
					{
						for ( ; it2 != end() && key_comp()(*it2, k) ==  key_comp()(k, *it2); it2++)
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
					if (key_comp()(*it2, k) ==  key_comp()(k, *it2))
					{
						for ( ; it2 != end() && key_comp()(*it2, k) ==  key_comp()(k, *it2); it2++)
							;
						break ;
					}	
				}				
				return  ft::pair<const_iterator, const_iterator>( it, it2);
			}

			size_type	erase (const key_type& val)
			{
				const key_type	tmp = val;
				size_t			nbr = 0;
				t_multiset		*elem = _multiset;
				t_multiset		*prev = NULL;
				t_multiset		*next = NULL;

				while (elem->next)
				{
					while (elem->next && key_comp()(*(elem->value), tmp) ==  key_comp()(tmp, *(elem->value)))
					{
						nbr++;
						_size--;
						next = elem->next;
						prev = elem->prev;
						next->prev = prev;
						if (prev == NULL)
							_multiset = next;
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
				t_multiset	*elem = (t_multiset*)(it.get_multiset());
				elem->next->prev = elem->prev;
				if (elem->prev)
					elem->prev->next = elem->next;
				else
					_multiset = elem->next;
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
					if (key_comp()(*it, k) ==  key_comp()(k, *it))
						return (it);
				}
				return (this->end());
			}

			const_iterator find (const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (key_comp()(*it, k) ==  key_comp()(k, *it))
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
				t_multiset	*n;
				t_multiset	*prev = NULL;
				t_multiset	*elem = this->_multiset;
				
				while (elem->next && key_comp()(*(elem->value), val))
				{
					prev = elem;
					elem = elem->next;
				}
				_size++;
				n = new t_multiset;
				n->value = new value_type(val);
				elem->prev = n;
				n->next = elem;
				n->prev = NULL;
				if (prev == NULL)
					_multiset = n;
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

			size_type 			max_size() const { return (std::numeric_limits<unsigned long long>::max() / sizeof(t_multiset) );}
		
			multiset& 				operator= (const multiset& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->insert(*it);
				return (*this);
			}

			reverse_iterator	rbegin(){ iterator it = end(); return reverse_iterator((--it).get_multiset() );}
			const_reverse_iterator	rbegin() const {iterator it = end(); return const_reverse_iterator((--it).get_multiset() );}
			
			reverse_iterator 	rend(){return reverse_iterator(end().get_multiset());}
			const_reverse_iterator rend() const { return const_reverse_iterator(this->end().get_multiset());}
			
			size_type			size() const {return _size;}
			
			void				swap (multiset& x) {multiset n(*this);   *this = x; x = n;}

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
	bool	operator== (const ft::multiset<T>& lhs, const ft::multiset<T>& rhs)
	{
		Multiset::iterator<T>	it_l = lhs.begin();
		Multiset::iterator<T>	it_r = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (it_l != lhs.end() && it_r != rhs.end())
		{
			if (*it_l !=  *it_r)
				return (false);
			++it_l;
			++it_r;
		}
		return (true);
	}

	template <class T>
	bool	operator!= (const ft::multiset<T>& lhs, const ft::multiset<T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator< (const ft::multiset<T>& lhs, const ft::multiset<T>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T>
	bool	operator<= (const ft::multiset<T>& lhs, const ft::multiset<T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T>
	bool	operator> (const ft::multiset<T>& lhs, const ft::multiset<T>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool	operator>= (const ft::multiset<T>& lhs, const ft::multiset<T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T>
	void	swap (ft::multiset<T>& x, ft::multiset<T>& y) {x.swap(y);}
};

#	endif
