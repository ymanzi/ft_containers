#	ifndef LIST_ITERATOR_HPP
#	define LIST_ITERATOR_HPP

#include "list.hpp"

namespace List
{
	template < class T >
	class iterator
	{
		protected:
			typedef struct	s_list
			{
				struct s_list	*prev;
				struct s_list	*next;
				T				value;
			}				t_list;

			void	begin()
			{
				while (_list->prev)
					_list = _list->prev;
			}

			void	end()
			{
				while (_list->next)
					_list = _list->next;
			}

			t_list	*_list;

		public:
			iterator(void): _list(nullptr) {}
			iterator(void* p_list): _list(static_cast<t_list *>(p_list)) {} // compilation error if the cast fails
			iterator(const iterator<T>& oth): _list(oth._list) {}
			virtual ~iterator(void) {}

			t_list*		get_list(void) {return (_list);}
			T&			operator*  (void) {return (_list->value);}
			iterator&	operator=  (const iterator<T>& oth) { _list = oth._list; return (*this);}
			bool		operator== (const iterator<T>& oth) const {return (_list == oth._list);}
			bool		operator!= (const iterator<T>& oth) const {return (_list != oth._list);}
			iterator&	operator++ () { if (_list->next == 0) this->begin(); else _list = _list->next; return (*this);} // equal to ++var
			iterator&	operator++ (int) { iterator tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++ 

	};

	template < class T >
	class r_iterator: public iterator
	{
		public:
			r_iterator(void): iterator() {}
			r_iterator(void* p_list): iterator(p_list) {} // compilation error if the cast fails
			r_iterator(const r_iterator<T>& oth): _list(oth._list) {}
			virtual ~r_iterator(void) {}

			iterator&	operator++ () { if (_list->prev == 0) this->end(); else _list = _list->prev; return (*this);} // equal to ++var
			iterator&	operator++ (int) { iterator tmp(*this); operator++(); return tmp;} // the (int) means that ++ is after the var // equal to var++ 
	};
}

#	endif