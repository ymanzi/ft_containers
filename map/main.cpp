#include "map.hpp"
#include <map>
#include <string>
#include "../utils/test.hpp"

bool g_verif = true;

int main(void)
{
	std::map<int, int> b;
	ft::map<int, int> a;

	map_constructor_t(a, b);
	map_clear_empty_t(a, b);
	map_count_t(a, b);
	map_equal_range_t(a, b);
	map_erase_t(a, b);
	// erase_t(a, b);
	// front_t(a, b);
	// insert_t(a, b);
	// sort_t(a, b);
	// merge_t(a, b);
	// operator_at_t(a, b);
	// pop_back_t(a, b);
	// pop_front_t(a, b);
	// push_back_t(a, b);
	// push_front_t(a, b);
	// remove_t(a,b);
	// remove_if_t(a,b);
	// re_size_t(a, b);
	// reverse_t(a, b);
	// splice_t(a, b);
	// swap_t(a, b);
	// unique_t(a, b);
	// iterator_t(a, b);
	// r_iterator_t(a, b);
	// comp_t(a, b);
	// iterator_comp_t_bd(a, b);
	// r_iterator_comp_t_bd(a, b);
	// end_check(g_verif, "MAP TEST: ");
	return (0);
}