#include "../system/system_methods.ipp"
#include UTILITIES

bool equal_test() {
	std::string s = "approvjvorppa";
	bool res = 0;
	if (_equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) == 1)
		res = 1;
	return res;
}

int main() {
	exit(run_bool_unit_test("equal", equal_test));
}
