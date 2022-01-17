#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> empty_test(std::stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	v.push_back(stk.empty());
	while (stk.size() > 0)
		stk.pop();
	g_start1 = timer();
	v.push_back(stk.empty());
	g_end1 = timer();
	return v;
}

template <class T>
std::vector<int> empty_test(_stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	v.push_back(stk.empty());
	while (stk.size() > 0)
		stk.pop();
	g_start2 = timer();
	v.push_back(stk.empty());
	g_end2 = timer();
	return v;
}

int main() {

	exit(run_stack_unit_test<int>("empty()", empty_test, empty_test));
}