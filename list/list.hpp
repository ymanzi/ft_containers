#	ifndef LIST_HPP
#	define LIST_HPP

#include <iostream>
#include <limits>
#include "list_iterator.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../main_header.hpp"

namespace ft
{
	template < typename T >
	class list
	{
		private:
			struct	s_list
			{
				struct s_list	*prev;
				struct s_list	*next;
				T				value;
			};

			typedef struct s_list t_list;

			size_t			_size;
			struct s_list	*_list;

			void	init_list(void)
			{ 
				_size = 0;

				_list = new t_list;
				_list->prev = nullptr;
				_list->value = T();
				_list->next = nullptr;
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

			bool	is_in_list(List::iterator<T> const& val)
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

				tmp = &elem;
				if (elem.prev)
				{
					elem.next->prev = elem.prev;
					elem.prev->next = elem.next;
				}
				else
					elem.next->prev = elem.prev;
				delete	tmp;
			}
		
			t_list 	*back_e()
			{
				t_list	*elem;

				elem = _list;
				while (elem->next && elem->next->next)
					elem = elem->next;
				return (elem);
			}

			// template<bool B>
			// struct enable_if {};

			// struct enable_if<true, T> { typedef T type; };

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
			typedef List::reverse_iterator<value_type>		reverse_iterator;
			typedef const List::reverse_iterator<value_type>	const_reverse_iterator;
			virtual ~list()
			{
				t_list *elem;
				
				while(_list)
				{
					elem = _list->next;
					delete _list;
					_list = elem;
				}
			}
			
			explicit list(void): _size(0), _list(nullptr) { init_list();} // default constructor
			explicit list (size_type n, const value_type& val = value_type()): _size(0){ init_list(); while (n--) push_back(val); } // fill constructor
			
			template <class InputIterator>
			list (InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value, std::nullptr_t>::type = nullptr): _size(0) { init_list(); this->insert(this->begin(), first, last); } // range constructor
			list (const list& x): _size(0) { init_list(); *this = x;} // Copy constructor

			template <class InputIterator>
  			void 				assign (InputIterator first, InputIterator last) // range
			{
				this->clear();
				this->insert(this->begin(), first, last);
			}

			void assign (size_type n, const value_type& val) {this->clear(); this->insert(this->begin(), n, val);} //Fill
			reference 			back()
			{
				t_list	*elem;

				elem = _list;
				while (elem->next && elem->next->next)
					elem = elem->next;
				return (elem->value);
			}
			const_reference 	back() const {return (const_cast<const_reference>(back()));}
			iterator			begin(){ return (iterator(_list));}
			const_iterator		begin() const { return (const_iterator(_list));}
			void 				clear()
			{
				while (_size)
					pop_front();
			}

			bool				empty() const {if (_size) return (false); return (true);}
			iterator			end()
			{
				t_list	*elem;

				elem = _list;
				while (elem->next)
					elem = elem->next;
				return (iterator(elem));
			}
			const_iterator		end() const
			{
				t_list	*elem;

				elem = _list;
				while (elem->next)
					elem = elem->next;
				return (const_iterator(elem));
			}
			iterator			erase (iterator position)
			{
				t_list	*elem = (t_list*)(position.get_list());
				if (elem->next)
				{
					t_list *nxt = elem->next;
					this->_size--;
					if (elem == _list)
						_list = nxt;
					this->del_one(*elem);
					return (iterator(nxt));
				}
				return (position);
			}
			iterator 			erase (iterator first, iterator last)
			{
				t_list	*elem_f = (t_list*)first.get_list();
				t_list	*elem_l = (t_list*)last.get_list();
				t_list	*tmp;

				if (elem_f->next)
				{
					while (elem_f->next && elem_f != elem_l)
					{
						tmp = elem_f->next;
						this->_size--;
						if (elem_f == _list)
							_list = tmp;
						this->del_one(*elem_f);
						elem_f = tmp;
					}
				}
				return (last);
			}
			reference			front() {return (_list->value);}
			const_reference		front() const {return (const_cast<const_reference>(front()));}
			iterator			insert (iterator position, const value_type& val)	// single element
			{
				t_list	*n;
				t_list	*elem;

				n = new t_list;
				elem = (t_list*)(position.get_list());
				
				_size++;
				n->value = val;
				n->prev = elem->prev;
				n->next = elem;
				if (elem == this->_list)
					this->_list = n;
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
    		void 				insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value, std::nullptr_t>::type = nullptr)  // range
			{
				while (first != last)
				{
					insert(position, *first);
					++first;
				}
			}
			size_type 			max_size() const { return (std::numeric_limits<char>::max() / sizeof(t_list) );}
			void				merge (list& x)
			{
				if ( *this != x)
				{
					list	n(*this);
					if (x.size())
						n.insert(n.begin(), x.begin(), x.end());
					n.sort();
					*this = n;
				}
			}
			template <class Compare>
  			void				merge (list& x, Compare comp)
			  {
				if ( *this != x)
				{
					list	n(*this);
					if (x.size())
						n.insert(n.begin(), x.begin(), x.end());
					n.sort(comp);
					*this = n;
				}			
			}
			list& 				operator= (const list& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->push_back(*it);
				return (*this);
			}
			void				pop_back()
			{
				t_list	*elem;

				elem = _list;
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
					t_list	*elem;
					
					elem = _list;
					_size--;
					_list = elem->next;
					elem->next->prev = nullptr;
					delete elem;
				}
			}
			void				push_back (const value_type& val)
			{
				t_list	*n;
				t_list	*elem;

				elem = back_e();
				if (_size == 0)
					push_front(val);
				else
				{
					_size++;
					n = new t_list;
					n->next = elem->next;
					elem->next->prev = n;
					n->value = val;
					n->prev = elem;
					elem->next = n;
				}
			}
			void				push_front (const value_type& val)
			{
				t_list	*n;

				_size++;
				n = new t_list;
				n->next = _list;
				n->value = val;
				n->prev = nullptr;
				_list->prev = n;
				_list = n;
			}
			reverse_iterator	rbegin(){return reverse_iterator(back_e());}
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(back_e());}
			void				remove (const value_type& val)
			{
				t_list	*tmp;
				t_list	*elem;

				elem = _list;
				while (elem->next)
				{
					tmp = elem->next;
					if (elem->value == val)
					{
						_size--;
						if (elem == _list)
							_list = tmp;
						this->del_one(*elem);
					}
					elem = tmp;
				}
			}
			template <class Predicate>
  			void 				remove_if (Predicate pred)
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
						if (elem == _list)
							_list = tmp;
						this->del_one(*elem);
					}
					elem = tmp;
				}
			}
			reverse_iterator 	rend(){ if (back_e()->next) return reverse_iterator(back_e()->next); return reverse_iterator(back_e());}
			const_reverse_iterator rend() const { if (back_e()->next) return const_reverse_iterator(back_e()->next); return const_reverse_iterator(back_e());}
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
				list elem(*this);

				this->clear();
				for (iterator it = elem.begin(); it != elem.end(); it++)
					this->push_front(*it);
			}
			size_type			size() const {return _size;}
			void				sort()
			{
				iterator	min;
				T			tmp;

				for (List::iterator<T> it1 = this->begin(); it1 != this->end(); ++it1)
				{
					min = it1;
					for (List::iterator<T> it2(it1); it2 != this->end(); ++it2)
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

				for (iterator it1 = this->begin(); it1 != this->end(); ++it1)
				{
					min = it1;
					for (iterator it2(it1); it2 != this->end(); ++it2)
					{
						if (comp(*it2, *min))
							min = it2;
					}
					tmp = *it1;
					*it1 = *min;
					*min = tmp;
				}
			}
			void				splice (iterator position, list& x) { insert(position, x.begin(), x.end()); x.erase(x.begin(), x.end()); } //entire list
			void 				splice (iterator position, list& x, iterator i) // single element
			{
				insert(position, *i);
				x.erase(i);
			} 

			void				splice (iterator position, list& x, iterator first, iterator last) // element range
			{
				insert(position, first, last);
				x.erase(first, last);
			}
			
			void				swap (list& x) {list<T> n(*this);   *this = x; x = n;}
			void				unique()
			{
				t_list		*tmp;
				t_list		*elem;
				T			val;
				bool		set;

				set = true;
				elem = _list;
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
				t_list		*tmp;
				t_list		*elem;
				T			val;
				bool		set;

				set = true;
				elem = _list;
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
	bool	operator== (const list<T>& lhs, const list<T>& rhs)
	{
		List::iterator<T>	it_l = lhs.begin();
		List::iterator<T>	it_r = rhs.begin();

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
	bool	operator!= (const list<T>& lhs, const list<T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator< (const list<T>& lhs, const list<T>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T>
	bool	operator<= (const list<T>& lhs, const list<T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T>
	bool	operator> (const list<T>& lhs, const list<T>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool	operator>= (const list<T>& lhs, const list<T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T>
	void	swap (list<T>& x, list<T>& y) {x.swap(y);}
}

#	endif
