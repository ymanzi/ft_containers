#	ifndef VECTOR_HPP
#	define VECTOR_HPP

#include <iostream>
#include <limits>
#include <stdexcept>
#include "vector_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "enable_if.hpp"

namespace ft
{
	template < class T >
	class vector
	{
		private:
			size_t	_size;
			size_t	_max_size;
			T		*_vector;

			void	init_vector(size_t n = 5, T val = T())
			{ 
				_size = 0;
				_max_size = n;
				_vector = new T[n];
				for (size_t i = 0; i < n; i++)
					_vector[i] = val;
			}

			void	new_size(size_t n, T val = T())
			{
				size_t	i = 0;
				T		*n_vec = new T[n];
				while (i < n && i < _size)
				{
					n_vec[i] = _vector[i];
					i++;
				}
				while (i < n)
					n_vec[i++] = val;
				_max_size = n;
				delete _vector;
				_vector = n_vec;
			}

			size_t	get_indice(Vector::iterator<T> &position)
			{
				T*		ptr = (T*)(position.get_vector());
				for (size_t i = 0; i < _size; i++)
				{
					if (this->_vector + i == ptr)
						return (i);
				}
				return (_size - 1);
			}

		public:
			typedef	T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef ptrdiff_t					difference_type;
			typedef size_t						size_type;

			typedef Vector::iterator<value_type>			iterator;
			typedef const Vector::iterator<value_type>	const_iterator;
			typedef Vector::reverse_iterator<value_type>		reverse_iterator;
			typedef const Vector::reverse_iterator<value_type>	const_reverse_iterator;
			virtual ~vector()
			{
				_size = 0;
				delete _vector;
			}

			explicit vector(void): _size(0) { init_vector();} // default constructor
			explicit vector (size_type n, const value_type& val = value_type()) { init_vector(n, val);} // fill constructor
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value, std::nullptr_t>::type = nullptr) { init_vector(); this->insert(this->begin(), first, last); } // range constructor
			vector (const vector& x) { init_vector(); *this = x;} // Copy constructor

			template <class InputIterator>
  			void 				assign (InputIterator first, InputIterator last) // range
			{
				this->clear();
				this->insert(this->begin(), first, last);
			}
			void assign (size_type n, const value_type& val) {this->clear(); this->insert(this->begin(), n, val);} //Fill
			reference at (size_type n) { if (n >= _size) throw std::out_of_range("vector::_M_range_check"); return _vector[n];}
			const_reference at (size_type n) const {return (const_cast<const_reference>(at(n)));}
			
			reference 			back()
			{
				return (_vector[_size - 1]);
			}
			const_reference 	back() const {return (const_cast<const_reference>(back()));}
			iterator			begin(){ return (iterator(_vector));}
			const_iterator		begin() const { return const_iterator(_vector);}
			size_type			capacity() const {return _max_size;}
			void 				clear()
			{
				delete _vector;
				init_vector();
			}

			bool				empty() const {if (_size) return (false); return (true);}
			iterator			end() {return (iterator(_vector + _size));}
			const_iterator		end() const {return (const_iterator(_vector + _size));}
			iterator			erase (iterator position)
			{ 
				size_t	i = (size_t)(get_indice(position));
				_size--;
				while (i < _size)
				{
					this->_vector[i] = this->_vector[i + 1];
					i++;
				}
				return (position);
			}

			iterator 			erase (iterator first, iterator last)
			{
				size_t	elem_f = (size_t)(get_indice(first));
				size_t	elem_l = (size_t)(get_indice(last));
				size_t	i = elem_f;
				
				for (size_t j = 0; j < _size && elem_l + j < _size; j++)
					_vector[i + j] = _vector[elem_l + j];
				_size -= (elem_l - elem_f);
				return (last);
			}
			reference			front() {return (_vector[0]);}
			const_reference		front() const {return (const_cast<const_reference>(front()));}
			iterator			insert (iterator position, const value_type& val)	// single element
			{
				size_t	elem = (size_t)(get_indice(position));
				size_t	i = 0;
				if (_size + 1 >= _max_size)
					new_size(_size + 5);
				vector	n(*this);
				_vector[elem] = val;
				while (elem + i < _size)
				{
					_vector[elem + i + 1] = n._vector[elem + i];
					i++;
				}
				_size++;
				return (position);
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
			size_type 			max_size() const { return (std::numeric_limits<char>::max() / sizeof(T));}
			vector& 				operator= (const vector& oth)
			{
				this->clear();
				for (iterator it = oth.begin(); it != oth.end(); it++ )
					this->push_back(*it);
				return (*this);
			}
			reference 		operator[] (size_type n) {if (n >= _size) return (_vector[_size - 1]); return _vector[n];}
			const_reference operator[] (size_type n) const {return const_cast<const T>(_vector[n]);}
			void				pop_back()
			{
				_size--;
			}

			void				push_back (const value_type& val)
			{
				if (_size + 1 <= _max_size)
					new_size(_size + 5);
				this->_vector[_size] = val;
				_size++;
			}
			reverse_iterator	rbegin(){if (!_size) return (reverse_iterator(_vector));  return (reverse_iterator(_vector + _size - 1));}
			const_reverse_iterator	rbegin() const {if (!_size) return (const_reverse_iterator(_vector));  return (const_reverse_iterator(_vector + _size - 1));}
			reverse_iterator 	rend(){ return reverse_iterator(_vector - 1);}
			const_reverse_iterator rend() const { return const_reverse_iterator(_vector - 1) ;}
			void				reserve (size_type n) { if (n > _max_size) new_size(n); }
			void 				resize (size_type n, value_type val = value_type())
			{
				new_size(n, val);
				_size = n;
			}
			size_type			size() const {return _size;}
			void				swap (vector& x) {vector<T> n(*this);   *this = x; x = n;}
	};

	//relational operators
	template <class T>
	bool	operator== (const vector<T>& lhs, const vector<T>& rhs)
	{
		Vector::iterator<T>	it_l = lhs.begin();
		Vector::iterator<T>	it_r = rhs.begin();

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
	bool	operator!= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator< (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T>
	bool	operator<= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T>
	bool	operator> (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool	operator>= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T>
	void	swap (vector<T>& x, vector<T>& y) {x.swap(y);}
}
#	endif
