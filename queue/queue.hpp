#	ifndef QUEUE_HPP
#	define QUEUE_HPP

#include <iostream>
#include "../main_header.hpp"

namespace ft 
{
	template <class T, class Container = ft::deque<T> >
	class queue
	{
		private:
			size_t		_size;
			Container	_cont;

		public:
			typedef	T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit queue (const container_type& ctnr = container_type()): _size(ctnr.size()), _cont(ctnr) {}
			value_type& back() { return (_cont.back());} 
			const value_type& back() const { return (_cont.back());} 
			bool empty() const { return (_cont.empty());} // Check if the queue is empty 
			value_type& front() { return (_cont.front());} 
			const value_type& front() const { return (_cont.front());} 
			void pop() {_cont.pop_front(); _size--;}  // Delete the last element of the queue			
			void push (const value_type& val) {_cont.push_back(val); _size++;} //add an element at the queue
			size_type size() const {return (_size);}  // give the size of the queue;
			
		//relational operators
			bool operator== (const queue<T,Container>& rhs) {return (_cont == rhs._cont);}
			bool operator!= (const queue<T,Container>& rhs) {return (_cont != rhs._cont);} 
			bool operator<  (const queue<T,Container>& rhs) {return (_cont < rhs._cont);} 
			bool operator<= (const queue<T,Container>& rhs) {return (_cont <= rhs._cont);} 
			bool operator>  (const queue<T,Container>& rhs) {return (_cont > rhs._cont);} 
			bool operator>= (const queue<T,Container>& rhs) {return (_cont >= rhs._cont);} 
	};

};

#	endif