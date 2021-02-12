#include "../main_header.hpp"
#include <vector>
#include <string>
#include "test.hpp"

bool g_verif = true;

int main(void)
{
	std::vector<int> b;
	ft::vector<int> a;

	constructor_t(a, b);
	assign_t(a, b);
	at_t(a, b);
	back_t(a, b);
	capacity_t(a, b);
	clear_empty_t(a, b);
	erase_t(a, b);
	front_t(a, b);
	insert_t(a, b);
	operator_equal_t(a, b);
	pop_back_t(a, b);
	push_back_t(a, b);
	re_size_t(a, b);
	swap_t(a, b);
	iterator_t(a, b);
	r_iterator_t(a, b);
	comp_t(a, b);
	iterator_comp_t_ra(a, b);
	r_iterator_comp_t_ra(a, b);
	end_check(g_verif, "VECTOR TEST: ");
	return (0);
}