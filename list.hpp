#	ifndef LIST_HPP
#	define LIST_HPP

#include <iostream>

namespace ft 
{
	template < class T >
	class list
	{
		private:
			struct s_list
			{
				struct s_list	*prev;
				struct s_list	*next;
//				struct s_list	*head; //utile ?
				T				value;
			};

			size_t			_size;
			struct s_list	*_list;

			init_list(void)
			{ 
				_list = new struct s_list;
				_list.prev = nullptr;
//				_list.head = _list;
				_list.value = T();
				_list.next = new struct s_list;

				_list.next.value = T();
				_list.next.prev = _list;
				_list.next.next = nullptr;
//				_list.next.head = _list;
			}
		
		public:
			typedef	T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef	struct s_list				t_list;
			typedef ptrdiff_t					difference_type;
			typedef size_t						size_type;

			// typedef List::iterator<value_type>			iterator;
			// typedef const List::iterator<value_type>	const_iterator;
			// typedef List::r_iterator<value_type>		reverse_iterator;
			// typedef const List::r_iterator<value_type>	const_reverse_iterator;
			
			
			explicit list(void): _size(0), _list(nullptr) { init_list();}
	//		explicit list (size_type n, const value_type& val = value_type()){ } //////////// FAIRE

			reference 		back();
			const_reference back() const;
		//	iterator begin();
		//	const_iterator begin() const;
			void 			clear();
		//	iterator		end();
		//	const_iterator	end() const;
			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);
			reference		front();
			const_reference	front() const;
			bool			empty() const {if (_size) return (true); return (false);}
			void			pop_back();
			void			pop_front();
			void			push_back (const value_type& val);
			void			push_front (const value_type& val);
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			void			remove (const value_type& val);

			template <class Predicate>
  			void remove_if (Predicate pred);


			






			explicit list (const container_type& ctnr = container_type()): _size(ctnr.size()), _cont(ctnr) {}
			value_type& back() { return (_cont.back());} 
			const value_type& back() const { return (_cont.back());} 
			bool empty() const { return (_cont.empty());} // Check if the list is empty 
			value_type& front() { return (_cont.front());} 
			const value_type& front() const { return (_cont.front());} 
			void pop() {_cont.pop_front(); _size--;}  // Delete the last element of the list			
			void push (const value_type& val) {_cont.push_back(val); _size++;} //add an element at the list
			size_type size() const {return (_size);}  // give the size of the list;
			
		//relational operators
			bool operator== (const list<T,Container>& rhs) {return (_cont == rhs._cont);}
			bool operator!= (const list<T,Container>& rhs) {return (_cont != rhs._cont);} 
			bool operator<  (const list<T,Container>& rhs) {return (_cont < rhs._cont);} 
			bool operator<= (const list<T,Container>& rhs) {return (_cont <= rhs._cont);} 
			bool operator>  (const list<T,Container>& rhs) {return (_cont > rhs._cont);} 
			bool operator>= (const list<T,Container>& rhs) {return (_cont >= rhs._cont);} 
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
	void		list<T>::pop_back(void)
	{
		t_list	*elem;

		elem = _list;
		if (_size == 0)
			return;
		else if (_size == 1)
		{
			_size--;
			return;
		}
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
	void 		list<T>::remove (const value_type& val)
	{
		t_list	*tmp;
		t_list	*elem;

		elem = _list;
		while (_size && elem->next)
		{
			if (elem->value == val)
			{
				tmp = elem->next;
				_size--;
				if (elem == _list)
				{
					if (_size == 0)
						_list->val = T();
					else
					{
						_list = elem->next;
						elem->next->prev = nullptr;
						delete elem;
					}
				}
				else
				{
					elem->prev->next = elem->next;
					elem->next->prev = elem->prev;
					delete elem;
				}
				elem = tmp;
			}
			else
				elem = elem->next;
		}
	}

	template < class T >
	template < class Predicate >
  	void		list<T>::remove_if (Predicate pred)
	{
		// FAIRE
	}
}

namespace List
{
	template < class T >
	class iterator
	{

	};
}

#	endif