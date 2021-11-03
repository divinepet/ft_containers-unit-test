#include "engine.ipp"

int main(int argc, char* argv[], char* env[]) {
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "|                                        UTILITIES                                         |" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	printElement("FUNCTION"); printElement(WHITE + "RESULT" + RESET); printElement(WHITE + "FT TIME" + RESET); printElement(WHITE + "STD TIME" + RESET);
	printElement(WHITE + "LEAKS" + RESET); cout << endl;

	runFunctionTest("../utilities_tests/is_integral.cpp", argv, env);
	runFunctionTest("../utilities_tests/enable_if.cpp", argv, env);
	runFunctionTest("../utilities_tests/equal.cpp", argv, env);
	runFunctionTest("../utilities_tests/lexicographical.cpp", argv, env);
	runFunctionTest("../utilities_tests/iterator_traits.cpp", argv, env);

	saveResult("utilities_res");
	outputCurrentResult("UTILITIES", _UTILITIES_TEST_NUM);

	return (0);
}