#	ifndef LIST_HPP
#	define LIST_HPP

#include <iostream>
#include <limits>
#include "list_iterator.hpp"

namespace ft
{
	template < class T >
	class list
	{
		private:
			typedef struct	s_list
			{
				struct s_list	*prev;
				struct s_list	*next;
				T				value;
			}				t_list;

			size_t			_size;
			struct s_list	*_list;

			init_list(void)
			{ 
				_list = new struct s_list;
				_list.prev = nullptr;
				_list.value = T();
				_list.next = nullptr;
			}

			bool	is_in_list(T const& val)
			{
				t_list	elem;

				elem = *_list;
				while (elem.next)
				{
					if (elem.value == val)
						return (true);
					elem = elem.next;
				}
				return (false);
			}

			bool	is_in_list(t_list const* val)
			{
				t_list	*elem;

				elem = _list;
				while (elem)
				{
					if (elem == val)
						return (true);
					elem = elem->next;
				}
				return (false);
			}

			bool	is_in_list(iterator const& val)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (it == val)
						return (true);
				}
				if (val == this->end())
					return (true);
				return (false);
			}

			void	del_one(t_list &elem)
			{
				t_list	*tmp;

				tmp = elem.next->prev;
				if (elem.prev)
				{
					elem.next->prev = elem.prev;
					elem.prev->next = elem.next;
				}
				else
					elem.next->prev = nullptr;
				delete	tmp;
			}
		
		public:
			typedef	T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef ptrdiff_t					difference_type;
			typedef size_t						size_type;

			typedef List::iterator<value_type>			iterator;
			typedef const List::iterator<value_type>	const_iterator;
			typedef List::r_iterator<value_type>		reverse_iterator;
			typedef const List::r_iterator<value_type>	const_reverse_iterator;
			
			
			explicit list(void): _size(0), _list(nullptr) { init_list();} // default constructor
			explicit list (size_type n, const value_type& val = value_type()): _size(0) { init_list(); this->insert(this->begin(), n, val); } // fill constructor
			template <class InputIterator>
			list (InputIterator first, InputIterator last): _size(0) { init_list(); this->insert(this->begin(), first, last); } // range constructor
			list (const list& x): _size(0) { init_list(); *this = x;} // Copy constructor

			reference 			back();
			const_reference 	back() const;
			iterator			begin(){ return (iterator(_list));}
			const_iterator		begin() const { return (const_iterator(_list));}
			void 				clear();
			bool				empty() const {if (_size) return (true); return (false);}
			iterator			end() {}
			const_iterator		end() const;
			iterator			erase (iterator position);
			iterator 			erase (iterator first, iterator last);
			reference			front();
			const_reference		front() const;
			iterator			insert (iterator position, const value_type& val);	// single element
			void				insert (iterator position, size_type nbr, const value_type& val);	// fill
			template <class InputIterator>
    		void 				insert (iterator position, InputIterator first, InputIterator last);  // range 
			size_type 			max_size() const { return (std::numeric_limits<char>::max() / sizeof(t_list) );}
			void				merge (list& x);
			template <class Compare>
  			void				merge (list& x, Compare comp);
			list& 				operator= (const list& oth);
			void				pop_back();
			void				pop_front();
			void				push_back (const value_type& val);
			void				push_front (const value_type& val);
			reverse_iterator	rbegin();
			const_reverse_iterator	rbegin() const;
			void				remove (const value_type& val);
			template <class Predicate>
  			void 				remove_if (Predicate pred);
			reverse_iterator 	rend(){ return reverse_iterator(this->end()) ;}
			const_reverse_iterator rend() const { return const_reverse_iterator(this->end()) ;}
			void 				resize (size_type n, value_type val = value_type());
			void				reverse();
			size_type			size() const {return _size;}
			void				sort();
			template <class Compare>
  			void				sort (Compare comp);
			void				splice (iterator position, list& x) { insert(position, x.begin(), x.end());} //entire list
			void 				splice (iterator position, list& x, iterator i) {insert(position, *i);} // single element
			void				splice (iterator position, list& x, iterator first, iterator last) { insert(position, first, last);} // element range
			void				swap (list& x) {*this = x;}
			void				unique();
			template <class BinaryPredicate>
  			void				unique (BinaryPredicate binary_pred);

	};

	template < typename T >
	T&			list<T>::back(void)
	{
		t_list	*elem;

		elem = _list;
		while (elem->next->next)
			elem = elem->next;
		return (*elem);
	}

	template < typename T >
	const T&	list<T>::back(void) const
	{
		return (back());
	}

	template < typename T >
	void		list<T>::clear(void)
	{
		while (size)
			pop_front();
	}

	template < typename T >
	iterator	list<T>::end()
	{
		t_list	*elem;

		elem = _list;
		while (elem->next)
			elem = elem->next;
		return (iterator(elem));
	}

	template < typename T >
	iterator	list<T>::erase (iterator position)
	{
		t_list	*pos_list;

		pos_list = position.get_list();
		if (pos_list->next && this->is_in_list(pos_list))
		{
			t_list	*elem;
			t_list	*nxt;

			_size--;
			elem = _list;
			while (elem != pos_list)
				elem = elem->next;
			if (_list == elem)
				_list = elem->next;
			nxt = elem->next;
			del_one(*elem);
			return (iterator(nxt));
		}
		return (position);
	}

	template < typename T >
	iterator	list<T>::erase (iterator first, iterator last)
	{
		t_list	*first_list;
		t_list	*last_list;

		first_list = first.get_list();
		last_list = last.get_list();
		if (first_list->next
		&& this->is_in_list(first_list) && this->is_in_list(last_list))
		{
			t_list	*elem;
			t_list	*tmp;

			elem = _list;
			while (elem != pos_list)
				elem = elem->next;
			if (_list == elem)
				_list = last_list;
			while (size && elem != last_list)
			{
				if (!(elem->next))
					elem = _list;
				else
				{
					_size--;
					tmp = elem->next;
					del_one(*elem);
					elem = tmp;
				}
			}
			return (last);
		}
		return (first);
	}

	template < typename T >
	const_iterator	list<T>::end() const
	{
		t_list	*elem;

		elem = _list;
		while (elem->next)
			elem = elem->next;
		return (const_iterator(elem));
	}

	template < typename T >
	T&			list<T>::front(void)
	{
		return (*_list);
	}

	template < typename T >
	const T&	list<T>::front(void) const
	{
		return (*_list);
	}

	template < typename T >
	iterator	list<T>::insert (iterator position, const value_type& val)
	{
		if (is_in_list(position))
		{
			_size++;
			t_list *p_list = position.get_list();
			t_list	*n = new t_list;
			n->value = val;
			n->next = p_list;
			n->prev = p_list->prev;
			p_list->prev = n;
			if (n->prev)
				n->prev->next = n;
			else
				_list = n;
			return (n);
		}
		return (position);
	}

	template < typename T >
	void		list<T>::insert (iterator position, size_type nbr, const value_type& val)
	{
		if (is_in_list(position))
		{
			t_list *p_list = position.get_list();
			while (nbr--)
			{
				_size++;
				t_list	*n = new t_list;
				n->value = val;
				n->next = p_list;
				n->prev = p_list->prev;
				p_list->prev = n;
				if (n->prev)
					n->prev->next = n;
				else
					_list = n;
			}
		}
	}

	template <class T>
	template <class InputIterator>
    void		list<T>::insert (iterator position, InputIterator first, InputIterator last)
	{
		if (is_in_list(position))
		{
			while (first != last)
			{
				insert(position, *first);
				++position;
				++first;
			}
		}
	}

	template <class T>
	list<T>&	list<T>::operator= (const list& oth)
	{
		this->clear();
		_size = oth._size;
		for (iterator it = oth.begin(); it != oth.end(); it++ )
			this->push_back(*it);
		return (*this);
	}

	template <class T>
	void		list<T>::merge (list& x)
	{
		if ( *this != x)
		{
			list	n;
			n.splice(n.begin(), *this);
			n.splice(n.begin(), x);
			n.sort();
			*this = n;
		}
	}

	template <class Compare>
	template <class T>
	void		list<T>::merge (list& x, Compare comp)
	{
		if ( *this != x)
		{
			list	n;
			n.splice(n.begin(), *this);
			n.splice(n.begin(), x);
			n.sort(comp);
			*this = n;
		}
	}

	template < typename T >
	void		list<T>::pop_back(void)
	{
		t_list	*elem;

		elem = _list;
		if (_size == 0)
			return;
		else if (_size == 1)
			this->pop_front()
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

	template < typename T >
	void		list<T>::pop_front(void)
	{
		t_list	*elem;

		elem = _list;
		if (_size == 0)
			return;
		else if (_size == 1)
		{
			_size--;
			_list = _list->next;
			del_one(*_list);
			return;
		}
		else
		{
			_size--;
			elem = elem->next;
			elem->prev = nullptr;
			delete _list;
			_list = elem;
		}
	}

	template < typename T >
	void 		list<T>::push_back (const value_type& val)
	{
		t_list	*n;
		t_list	elem;

		if (_size == 0)
		{
			push_front(val);
			return ;
		}
		elem = back();
		n = new t_list;

		_size++;
		n->next = elem.next;
		n->value = val;
		n->prev = &elem;

		elem.next = n;
	}

	template < typename T >
	void 		list<T>::push_front (const value_type& val)
	{
		t_list	*n;

		n = new t_list;

		_size++;
		n->next = _list;
		n->value = val;
		n->prev = nullptr;
		_list->prev = n;

		_list = n;
	}

	template < typename T >
	reverse_iterator	list<T>::rbegin()
	{
		t_list	*elem = _list;

		while (elem->next->next)
			elem = elem->next;
		return (reverse_iterator(elem));
	}

	template < typename T >
	const_reverse_iterator	list<T>::rbegin() const
	{
		t_list	*elem = _list;

		while (elem->next->next)
			elem = elem->next;
		return (const_reverse_iterator(elem));
	}

	template < typename T >
	void 		list<T>::remove (const value_type& val)
	{
		for (iterator it = this->begin(); it != this->end(); it++)
		{
			if (*it == val)
			{
				if (it == this->begin())
					_this = reinterpret_cast<t_list *>(it).next;
				this->del_one(reinterpret_cast<t_list *>(it));
				return ;
			}
		}
	}

	template < class T >
	template < class Predicate >
  	void		list<T>::remove_if (Predicate pred)
	{
		t_list	*tmp;
		t_list	*elem;

		elem = _list;
		while (elem->next)
		{
			tmp = elem->next;
			if (pred(elem->value))
			{
				_size--;
				if (elem == _this)
					_this = tmp;
				this->del_one(elem);
			}
			elem = tmp;
		}
	}

	template < class T >
	void		list<T>resize (size_type n, value_type val = value_type())
	{
		size_t		i = 0;
		iterator	i_end = this->end();
		for (iterator it = this->begin(); it != i_end; it++)
		{
			i++;
			if (i < n)
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

	template < class T >
	void		list<T>::reverse()
	{
		list<T> elem(*this);

		this->clear();
		this->insert(this->end(), elem.rbegin(), elem.rend());
	}

	template <class T>
	void		list<T>::sort()
	{
		iterator	min;
		T			tmp;

		for (iterator it1 = this->begin(); it1 != this->end(); it1++)
		{
			min = it1;
			for (iterator it2 = it1; it2 != this->end(); it2++)
			{
				if (min > it2)
					min = it2;
			}
			if (it1 > min)
			{
				tmp = *it1;
				*it1 = *min;
				*min = tmp;
			}
		}
	}

	template <class Compare>
	template <class T>
	void		list<T>::sort (Compare comp)
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

	template <class T>
	void		list<T>::unique()
	{
		t_list	*elem;

		elem = _list;
		while (elem->next)
		{
			while (elem->value == elem->next->value)
			{
				_size--;
				del_one(*(elem->next));
			}
			elem = elem->next;
		}
	}

	template <class BinaryPredicate>
	template <class T>
	void		list<T>::unique (BinaryPredicate binary_pred)
	{
		t_list	*elem;

		elem = _list;
		while (elem->next)
		{
			while (binary_pred(elem->next->value, elem->value))
			{
				_size--;
				del_one(*(elem->next));
			}
			elem = elem->next;
		}
	}

	//relational operators
	template <class T>
	bool operator== (const list<T>& lhs, const list<T>& rhs)
	{
		iterator	it_l = lhs.begin();
		iterator	it_r = rhs.begin();

		if (lhs.size != rhs.size())
			return (false);
		while (it_l != lhs.end() && it_r != rhs.end())
		{
			if (*it_l != *it_r)
				return (false);
			it_l++;
			it_r++;
		}
		return (true);
	}

	template <class T>
	bool operator!= (const list<T>& lhs, const list<T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T>                                          /////////FAIRE
	bool operator< (const list<T>& lhs, const list<T>& rhs)
	{
		iterator	it_l = lhs.begin();
		iterator	it_r = rhs.begin();

		while (it_l != lhs.end() && it_r != rhs.end())
		{
			if (*it_l > *it_r)
				return (false);
			it_l++;
			it_r++;
		}
		if (rhs.size() > lhs.size())
			return (false);
		return (true);
	}
	bool operator!= (const list<T>& rhs) {return (_cont != rhs._cont);} 
	bool operator<  (const list<T>& rhs) {return (_cont < rhs._cont);} 
	bool operator<= (const list<T>& rhs) {return (_cont <= rhs._cont);} 
	bool operator>  (const list<T>& rhs) {return (_cont > rhs._cont);} 
	bool operator>= (const list<T>& rhs) {return (_cont >= rhs._cont);} 

}

#	endif