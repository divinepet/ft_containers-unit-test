#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> pop_test(std::stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	g_start1 = timer();
	while (stk.size() > 0)
		stk.pop();
	g_end1 = timer();
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> pop_test(_stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	g_start2 = timer();
	while (stk.size() > 0)
		stk.pop();
	g_end2 = timer();
	v.push_back(stk.size());
	return v;
}

int main() {

	exit(run_stack_unit_test<int>("pop()", pop_test, pop_test));
}