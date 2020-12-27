#include "stack.hpp"
#include "queue.hpp"

#define P(x) std::cout << std::boolalpha << x << std::endl
#define A(x, y) std::cout << std::boolalpha << x << y << std::endl

void t_stack(void)
{
	ft::stack<int>	s;
	ft::stack<int>	s2;

	P("-------------- STACK ------------------");
	P("---> empty <----");
	
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---> push (5) <----");
	s.push(5);
	A("top = ", s.top());
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---> pop <----");
	s.pop();
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("------------> S(42) and S2(42, 18) <-------------");
	s2.push(42);
	s2.push(18);
	s.push(42);


	P("---> operator == <----");
	A("operator '==' : ", (s == s2));

	P("---> operator != <----");
	A("operator '!=' : ", (s != s2));

	P("---> operator < <----");
	A("operator '<' : ", (s < s2));

	P("---> operator <= <----");
	A("operator '<=' : ", (s <= s2));

	P("---> operator > <----");
	A("operator '>' : ", (s > s2));

	P("---> operator >= <----");
	A("operator '>=' : ", (s >= s2));
}
void t_queue(void)
{
	ft::queue<int>	s;
	ft::queue<int>	s2;

	P("-------------- QUEUE ------------------");
	P("---> empty <----");
	A("empty ? ", s.empty());
	A("size = ", s.size());

	P("---> push (5) (-7) <----");
	s.push(5);
	s.push(-7);
	A("empty ? ", s.empty());
	A("size = ", s.size());
	A("front = ", s.front());
	A("back = ", s.back());

	P("---> pop <----");
	s.pop();
	A("empty ? ", s.empty());
	A("size = ", s.size());
	A("front = ", s.front());
	A("back = ", s.back());

	P("------------> S(42) and S2(42, 18) <-------------");
	s2.push(42);
	s2.push(18);
	s.push(42);


	P("---> operator == <----");
	A("operator '==' : ", (s == s2));

	P("---> operator != <----");
	A("operator '!=' : ", (s != s2));

	P("---> operator < <----");
	A("operator '<' : ", (s < s2));

	P("---> operator <= <----");
	A("operator '<=' : ", (s <= s2));

	P("---> operator > <----");
	A("operator '>' : ", (s > s2));

	P("---> operator >= <----");
	A("operator '>=' : ", (s >= s2));
}

int main(void)
{
	t_stack();
	t_queue();
	return (0);
}