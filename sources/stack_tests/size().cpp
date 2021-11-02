#include "../system/system_methods.ipp"
#include "__service.ipp"

template <class T>
std::vector<int> size_test(std::stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	g_start1 = timer();
	v.push_back(stk.size());
	g_end1 = timer();
	stk.pop();
	v.push_back(stk.size());
	stk.push(7);
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> size_test(_stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	g_start2 = timer();
	v.push_back(stk.size());
	g_end2 = timer();
	stk.pop();
	v.push_back(stk.size());
	stk.push(7);
	v.push_back(stk.size());
	return v;
}

int main() {

	exit(run_stack_unit_test<int>("size()", size_test, size_test));
}