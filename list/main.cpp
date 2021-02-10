#include "list.hpp"
#include <list>
#include <string>
#include "../utils/test.hpp"


int main(void)
{
	// t_vector();

	std::list<int> b;
	ft::list<int> a;

	constructor_t(a, b);
	assign_t(a, b);
	at_t(a, b);
	back_t(a, b);
	capacity_t(a, b);
	clear_empty_t(a, b);
	erase_t(a, b);
	front_t(a, b);
	insert_t(a, b);
	operator_at_t(a, b);
	pop_back_t(a, b);
	push_back_t(a, b);
	re_size_t(a, b);
	swap_t(a, b);
	iterator_t(a, b);
	r_iterator_t(a, b);
	comp_t(a, b);
	iterator_comp_t(a, b);
	r_iterator_comp_t(a, b);
	P("Vector Test Finished: If you have no error, everything is Good, otherwhise.....");
	return (0);
}