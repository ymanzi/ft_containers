#include <map>
#include <string>
#include "test.hpp"

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
	map_find_t(a, b);
	map_insert_t(a, b);
	map_key_comp_t(a, b);
	map_lower_bound_t(a, b);
	map_operator_equal_t(a, b);
	map_size_t(a, b);
	map_swap_t(a, b);
	map_upper_bound_t(a, b);
	map_value_comp_t(a, b);
	map_iterator_t(a, b);
	map_r_iterator_t(a, b);
	map_comp_t(a, b);
	map_iterator_comp_t_bd(a, b);
	map_r_iterator_comp_t_bd(a, b);
	end_check(g_verif, "MAP TEST: ");
	return (0);
}