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
				T				value;
			};

			size_t			_size;
			struct s_list	*_list;

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
			
			
			explicit list(void): _size(0), _list(nullptr) {};
			explicit list (size_type n, const value_type& val = value_type()){ } ; //////////// FAIRE













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

}

#	endif