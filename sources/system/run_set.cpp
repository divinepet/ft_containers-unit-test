#include "engine.ipp"

int main(int argc, char* argv[], char* env[]) {
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           SET                                            |" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	printElement("FUNCTION"); printElement(WHITE + "RESULT" + RESET); printElement(WHITE + "FT TIME" + RESET); printElement(WHITE + "STD TIME" + RESET);
	printElement(WHITE + "LEAKS" + RESET); cout << endl;

	runFunctionTest("../set_tests/constructor.cpp", argv, env);
	runFunctionTest("../set_tests/assign overload.cpp", argv, env);
	runFunctionTest("../set_tests/iterators.cpp", argv, env);
	runFunctionTest("../set_tests/reverse iterators.cpp", argv, env);
	runFunctionTest("../set_tests/compare class.cpp", argv, env);
	runFunctionTest("../set_tests/insert(value).cpp", argv, env);
	runFunctionTest("../set_tests/insert(InputIt).cpp", argv, env);
	runFunctionTest("../set_tests/insert(hint).cpp", argv, env);
	runFunctionTest("../set_tests/empty().cpp", argv, env);
	runFunctionTest("../set_tests/size().cpp", argv, env);
	runFunctionTest("../set_tests/max_size().cpp", argv, env);
	runFunctionTest("../set_tests/clear().cpp", argv, env);
	runFunctionTest("../set_tests/erase(value).cpp", argv, env);
	runFunctionTest("../set_tests/erase(pos).cpp", argv, env);
	runFunctionTest("../set_tests/erase(InputIt).cpp", argv, env);
	runFunctionTest("../set_tests/swap().cpp", argv, env);
	runFunctionTest("../set_tests/count().cpp", argv, env);
	runFunctionTest("../set_tests/find().cpp", argv, env);
	runFunctionTest("../set_tests/lower_bound().cpp", argv, env);
	runFunctionTest("../set_tests/upper_bound().cpp", argv, env);
	runFunctionTest("../set_tests/equal_range().cpp", argv, env);
	runFunctionTest("../set_tests/key_comp().cpp", argv, env);
	runFunctionTest("../set_tests/using allocator.cpp", argv, env);
	runFunctionTest("../set_tests/operator ==.cpp", argv, env);
	runFunctionTest("../set_tests/operator !=.cpp", argv, env);
	runFunctionTest("../set_tests/operator <.cpp", argv, env);
	runFunctionTest("../set_tests/operator >.cpp", argv, env);
	runFunctionTest("../set_tests/operator <=.cpp", argv, env);
	runFunctionTest("../set_tests/operator >=.cpp", argv, env);

	saveResult("set_res");
	outputCurrentResult("SET", _SET_TEST_NUM);

	return (0);
}