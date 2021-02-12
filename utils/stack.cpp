#include <stack>
#include <string>
#include "test.hpp"

bool g_verif = true;

int main(void)
{
	std::stack<int> b;
	ft::stack<int> a;

	stack_push_t(a, b);
	stack_top_t(a, b);
	queue_empty_t(a, b);
	stack_pop_t(a, b);
	queue_size_t(a, b);
	queue_comp_t(a, b);
	end_check(g_verif, "STACK TEST: ");
	return (0);
}