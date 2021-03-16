#	ifndef DEQUE_HPP
#	define DEQUE_HPP

#include <iostream>
#include <limits>
#include "deque_iterator.hpp"
#include "../utils/ft_utils.hpp"
#include "../main_header.hpp"

namespace ft
{
	template < typename T >
	class deque
	{
		private:
			struct	s_deque
			{
				struct s_deque	*prev;
				struct s_deque	*next;
				T				value;
			};

			typedef struct s_deque t_deque;

			size_t			_size;
			struct s_deque	*_deque;

			void	init_deque(void)
			{ 
				_size = 0;

				_deque = new t_deque;
				_deque->prev = NULL;
				_deque->value = T();
				_deque->next = NULL;
			}

			bool	is_in_deque(T const& val)
			{
				t_deque	elem;

				elem = *_deque;
				while (elem.next)
				{
					if (elem.value == val)
						return (true);
					elem = elem.next;
				}
				return (false);
			}

			bool	is_in_deque(t_deque const* val)
			{
				t_deque	*elem;

				elem = _deque;
				while (elem)
				{
					if (elem == val)
						return (true);
					elem = elem->next;
				}
				return (false);
			}

			bool	is_in_deque(Deque::iterator<T> const& val)
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

			void	del_one(t_deque &elem)
			{
				t_deque	*tmp;

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
		
			t_deque 	*back_e()
			{
				t_deque	*elem;

				elem = _deque;
				while (elem->next && elem->next->next)
					elem = elem->next;
				return (elem);
			}

		public:
			typedef	T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef size_t						size_type;

			typedef Deque::iterator<value_type>			iterator;
			typedef const Deque::iterator<value_type>	const_iterator;
			typedef Deque::reverse_iterator<value_type>		reverse_iterator;
			typedef const Deque::reverse_iterator<value_type>	const_reverse_iterator;
			virtual ~deque()
			{
				t_deque *elem;
				
				while(_deque)
				{
					elem = _deque->next;
					delete _deque;
					_deque = elem;
				}
			}
			
			explicit deque(void): _size(0), _deque(NULL) { init_deque();} // default constructor
			explicit deque (size_type n, const value_type& val = value_type()): _size(0){ init_deque(); while (n--) push_back(val); } // fill constructor
			
			template <class InputIterator>
			deque (InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, char>::type = char() ): _size(0) { init_deque(); this->insert(this->begin(), first, last); } // range constructor
			deque (const deque& x): _size(0) { init_deque(); *this = x;} // Copy constructor

			template <class InputIterator>
  			void 				assign (InputIterator first, InputIterator last) // range
			{
				this->clear();
				this->insert(this->begin(), first, last);
			}

			void assign (size_type n, const value_type& val) {this->clear(); this->insert(this->begin(), n, val);} //Fill
			reference at (size_type n) { if (n >= _size) throw std::out_of_range("vector::_M_range_check"); return  this->operator[](n);}
			const_reference at (size_type n) const { if (n >= _size) throw std::out_of_range("vector::_M_range_check"); return this->operator[](n);}
			
			reference 			back()
			{
				t_deque	*elem;

				elem = _deque;
				while (elem->next && elem->next->next)
					elem = elem->next;
				return (elem->value);
			}
			const_reference 	back() const {return (const_cast<const_reference>(back()));}
			iterator			begin(){ return (iterator(_deque));}
			const_iterator		begin() const { return (const_iterator(_deque));}
			void 				clear()
			{
				while (_size)
					pop_front();
			}

			bool				empty() const {if (_size) return (false); return (true);}
			iterator			end()
			{
				t_deque	*elem;

				elem = _deque;
				while (elem->next)
					elem = elem->next;
				return (iterator(elem));
			}
			const_iterator		end() const
			{
				t_deque	*elem;

				elem = _deque;
				while (elem->next)
					elem = elem->next;
				return (const_iterator(elem));
			}
			iterator			erase (iterator position)
			{
				t_deque	*elem = (t_deque*)(position.get_deque());
				if (elem->next)
				{
					t_deque *nxt = elem->next;
					this->_size--;
					if (elem == _deque)
						_deque = nxt;
					this->del_one(*elem);
					return (iterator(nxt));
				}
				return (position);
			}
			iterator 			erase (iterator first, iterator last)
			{
				t_deque	*elem_f = (t_deque*)first.get_deque();
				t_deque	*elem_l = (t_deque*)last.get_deque();
				t_deque	*tmp;

				if (elem_f->next)
				{
					while (elem_f->next && elem_f != elem_l)
					{
						tmp = elem_f->next;
						this->_size--;
						if (elem_f == _deque)
							_deque = tmp;
						this->del_one(*elem_f);
						elem_f = tmp;
					}
				}
				return (last);
			}
			reference			front() {return (_deque->value);}
			const_reference		front() const {return (const_cast<const_reference>(front()));}
			iterator			insert (iterator position, const value_type& val)	// single element
			{
				t_deque	*n;
				t_deque	*elem;

				n = new t_deque;
				elem = (t_deque*)(position.get_deque());
				
				_size++;
				n->value = val;
				n->prev = elem->prev;
				n->next = elem;
				if (elem == this->_deque)
					this->_deque = n;
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
    		void 				insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, char>::type = char() )  // range
			{
				while (first != last)
				{
					insert(position, *first);
					++first;
				}
			}
			size_type 			max_size() const { return (std::numeric_limits<unsigned long long>::max() / sizeof(t_deque) );}
			deque& 				operator= (const deque& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->push_back(*it);
				return (*this);
			}

			reference operator[](size_type n) 
			{
				t_deque *elem = _deque;
				if (n >= _size) 
					throw std::out_of_range("Deque::_M_range_check");
				for (size_t i = 0; i < _size; i++)
				{
					if (i == n)
						return (elem->value);
					elem = elem->next;
				}
				return (_deque->value);
			}
			const_reference operator[](size_type n) const
			{
				t_deque *elem = _deque;
				if (n >= _size) 
					throw std::out_of_range("Deque::_M_range_check");
				for (size_t i = 0; i < _size; i++)
				{
					if (i == n)
						return (elem->value);
					elem = elem->next;
				}
				return (_deque->value);
			}

			void				pop_back()
			{
				t_deque	*elem;

				elem = _deque;
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
					t_deque	*elem;
					
					elem = _deque;
					_size--;
					_deque = elem->next;
					elem->next->prev = NULL;
					delete elem;
				}
			}
			void				push_back (const value_type& val)
			{
				t_deque	*n;
				t_deque	*elem;

				elem = back_e();
				if (_size == 0)
					push_front(val);
				else
				{
					_size++;
					n = new t_deque;
					n->next = elem->next;
					elem->next->prev = n;
					n->value = val;
					n->prev = elem;
					elem->next = n;
				}
			}
			void				push_front (const value_type& val)
			{
				t_deque	*n;

				_size++;
				n = new t_deque;
				n->next = _deque;
				n->value = val;
				n->prev = NULL;
				_deque->prev = n;
				_deque = n;
			}

			reverse_iterator	rbegin(){return reverse_iterator(back_e());}
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(back_e());}
			
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
			size_type			size() const {return _size;}
			void				swap (deque& x) {deque<T> n(*this);   *this = x; x = n;}
	};

	//relational operators
	template <class T>
	bool	operator== (const deque<T>& lhs, const deque<T>& rhs)
	{
		Deque::iterator<T>	it_l = lhs.begin();
		Deque::iterator<T>	it_r = rhs.begin();

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
	bool	operator!= (const deque<T>& lhs, const deque<T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator< (const deque<T>& lhs, const deque<T>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T>
	bool	operator<= (const deque<T>& lhs, const deque<T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T>
	bool	operator> (const deque<T>& lhs, const deque<T>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool	operator>= (const deque<T>& lhs, const deque<T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T>
	void	swap (deque<T>& x, deque<T>& y) {x.swap(y);}
}

#	endif
