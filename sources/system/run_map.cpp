#include "engine.ipp"

int main(int argc, char* argv[], char* env[]) {
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           MAP                                            |" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	printElement("FUNCTION"); printElement(WHITE + "RESULT" + RESET); printElement(WHITE + "FT TIME" + RESET); printElement(WHITE + "STD TIME" + RESET);
	printElement(WHITE + "LEAKS" + RESET); cout << endl;

	runNonCompilable("../map_tests/key_redefinition.cpp", argv, env);
	runFunctionTest("../map_tests/constructor.cpp", argv, env);
	runFunctionTest("../map_tests/assign overload.cpp", argv, env);
	runFunctionTest("../map_tests/iterators.cpp", argv, env);
	runFunctionTest("../map_tests/reverse iterators.cpp", argv, env);
	runFunctionTest("../map_tests/compare class.cpp", argv, env);
	runFunctionTest("../map_tests/insert(value).cpp", argv, env);
	runFunctionTest("../map_tests/insert(InputIt).cpp", argv, env);
	runFunctionTest("../map_tests/insert(hint).cpp", argv, env);
	runFunctionTest("../map_tests/at().cpp", argv, env);
	runFunctionTest("../map_tests/operator[].cpp", argv, env);
	runFunctionTest("../map_tests/empty().cpp", argv, env);
	runFunctionTest("../map_tests/size().cpp", argv, env);
	runFunctionTest("../map_tests/max_size().cpp", argv, env);
	runFunctionTest("../map_tests/clear().cpp", argv, env);
	runFunctionTest("../map_tests/erase(key).cpp", argv, env);
	runFunctionTest("../map_tests/erase(pos).cpp", argv, env);
	runFunctionTest("../map_tests/erase(InputIt).cpp", argv, env);
	runFunctionTest("../map_tests/swap().cpp", argv, env);
	runFunctionTest("../map_tests/count().cpp", argv, env);
	runFunctionTest("../map_tests/find().cpp", argv, env);
	runFunctionTest("../map_tests/lower_bound().cpp", argv, env);
	runFunctionTest("../map_tests/upper_bound().cpp", argv, env);
	runFunctionTest("../map_tests/equal_range().cpp", argv, env);
	runFunctionTest("../map_tests/key_comp().cpp", argv, env);
	runFunctionTest("../map_tests/using allocator.cpp", argv, env);
	runFunctionTest("../map_tests/operator ==.cpp", argv, env);
	runFunctionTest("../map_tests/operator !=.cpp", argv, env);
	runFunctionTest("../map_tests/operator <.cpp", argv, env);
	runFunctionTest("../map_tests/operator >.cpp", argv, env);
	runFunctionTest("../map_tests/operator <=.cpp", argv, env);
	runFunctionTest("../map_tests/operator >=.cpp", argv, env);

    saveResult("map_res");
	outputCurrentResult("MAP", _MAP_TEST_NUM);

	return (0);
}