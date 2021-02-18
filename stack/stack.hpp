#	ifndef STACK_HPP
#	define STACK_HPP

#include <iostream>
#include "../deque/deque.hpp"
#include "../main_header.hpp"

namespace ft 
{

	template <class T, class Container = ft::deque<T> >
	class stack
	{
		private:
			size_t		_size;
			Container	_cont;

		public:
			typedef	T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit stack (const container_type& ctnr = container_type()): _size(ctnr.size()), _cont(ctnr) {}
			bool empty() const { return (_cont.empty());} // Check if the stack is empty 
			void pop() {_cont.pop_back(); _size--;}  // Delete the last element of the stack
			void push (const value_type& val) {_cont.push_back(val); _size++;} //add an element at the stack
			size_type size() const {return (_size);}  // give the size of the stack;
			value_type& top() { return (_cont.back());} 
			const value_type& top() const { return (_cont.back());} 

		//relational operators
			bool operator== (const stack<T,Container>& rhs) {return (_cont == rhs._cont);}
			bool operator!= (const stack<T,Container>& rhs) {return (_cont != rhs._cont);} 
			bool operator<  (const stack<T,Container>& rhs) {return (_cont < rhs._cont);} 
			bool operator<= (const stack<T,Container>& rhs) {return (_cont <= rhs._cont);} 
			bool operator>  (const stack<T,Container>& rhs) {return (_cont > rhs._cont);} 
			bool operator>= (const stack<T,Container>& rhs) {return (_cont >= rhs._cont);} 
	};
};

#	endif