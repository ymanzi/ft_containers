#include "queue.hpp"
#include <queue>
#include <string>
#include "../utils/test.hpp"

bool g_verif = true;

int main(void)
{
	std::queue<int> b;
	ft::queue<int> a;

	queue_push_t(a, b);
	queue_back_t(a, b);
	queue_empty_t(a, b);
	queue_front_t(a, b);
	queue_pop_t(a, b);
	queue_size_t(a, b);
	queue_comp_t(a, b);
	end_check(g_verif, "QUEUE TEST: ");
	return (0);
}