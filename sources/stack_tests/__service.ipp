#pragma once
#include "../system/lib.hpp"
#include STACK

class StackBoolTest {
public:
	std::stack<int> s1, s2, s3, s4;
	std::stack<string> s5, s6, s7, s8, s9;
	_stack<int> st1, st2, st3, st4;
	_stack<string> st5, st6, st7, st8, st9;

	StackBoolTest() {
		s1.push(2); st1.push(2);
		s2.push(3); st2.push(3);
		s3.push(3); st3.push(3);
		s4.push(4); st4.push(4);
		s4.push(4); st4.push(4);
		s5.push("122"); st5.push("122");
		s6.push("123"); st6.push("123");
		s7.push("124"); st7.push("124");
		s8.push("12"); st8.push("12");
		s9.push("123"); st9.push("123");
	}
};

template <class T>
int run_stack_unit_test(std::string test_name, std::vector<int> (func1)(std::stack<T>), std::vector<int> (func2)(_stack<T>)) {
    int    result;
    int    leaks;
    time_t t1;
	time_t t2;
	std::vector<int > res1;
	std::vector<int > res2;
	std::stack<int> stack;
	_stack<int> my_stack;

	printElement(test_name);
	res1 = func1(stack);
	res2 = func2(my_stack);
	if (res1 == res2) {
	    printElement("OK");
	    result = 0;
	}
	else {
	    printElement("FAILED");
	    result = 1;
	}
	t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
	(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
	(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
	leaks = leaks_test(getpid());
	cout << endl;

	return !(!result && !leaks);;
}
