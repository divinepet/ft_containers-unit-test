#include "../system/system_methods.ipp"
#include "__service.ipp"

bool set_more_than_test() {
	std::vector<int> result, result2;
	g_start2 = g_end2 = g_start1 = g_end1 = 0;
	SetBoolTest st;

	result.push_back(st.s1 > st.s1); result.push_back(st.s3 > st.s3); result.push_back(st.s5 > st.s9);
	result.push_back(st.s1 > st.s2); result.push_back(st.s3 > st.s4); result.push_back(st.s6 > st.s6);
	result.push_back(st.s1 > st.s3); result.push_back(st.s4 > st.s4); result.push_back(st.s6 > st.s7);
	result.push_back(st.s1 > st.s4); result.push_back(st.s5 > st.s5); result.push_back(st.s6 > st.s8);
	result.push_back(st.s2 > st.s2); result.push_back(st.s5 > st.s6); result.push_back(st.s6 > st.s9);
	result.push_back(st.s2 > st.s3); result.push_back(st.s5 > st.s7); result.push_back(st.s7 > st.s7);
	result.push_back(st.s2 > st.s4); result.push_back(st.s5 > st.s8); result.push_back(st.s7 > st.s8);
	result.push_back(st.s7 > st.s9); result.push_back(st.s8 > st.s8); result.push_back(st.s8 > st.s9);
	result.push_back(st.s9 > st.s9);

	result2.push_back(st.st1 > st.st1); result2.push_back(st.st3 > st.st3); result2.push_back(st.st5 > st.st9);
	result2.push_back(st.st1 > st.st2); result2.push_back(st.st3 > st.st4); result2.push_back(st.st6 > st.st6);
	result2.push_back(st.st1 > st.st3); result2.push_back(st.st4 > st.st4); result2.push_back(st.st6 > st.st7);
	result2.push_back(st.st1 > st.st4); result2.push_back(st.st5 > st.st5); result2.push_back(st.st6 > st.st8);
	result2.push_back(st.st2 > st.st2); result2.push_back(st.st5 > st.st6); result2.push_back(st.st6 > st.st9);
	result2.push_back(st.st2 > st.st3); result2.push_back(st.st5 > st.st7); result2.push_back(st.st7 > st.st7);
	result2.push_back(st.st2 > st.st4); result2.push_back(st.st5 > st.st8); result2.push_back(st.st7 > st.st8);
	result2.push_back(st.st7 > st.st9); result2.push_back(st.st8 > st.st8); result2.push_back(st.st8 > st.st9);
	result2.push_back(st.st9 > st.st9);

	return result == result2;
}

int main() {
	exit(run_bool_unit_test("operator >", set_more_than_test));
}