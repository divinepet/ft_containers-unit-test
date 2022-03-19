#include "engine.ipp"

int main(int argc, char* argv[], char* env[]) {
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "|                                          VECTOR                                          |" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	printElement("FUNCTION"); printElement(WHITE + "RESULT" + RESET); printElement(WHITE + "FT TIME" + RESET); printElement(WHITE + "STD TIME" + RESET);
	printElement(WHITE + "LEAKS" + RESET); cout << endl;

	runFunctionTest("../vector_tests/constructor.cpp", argv, env);
	runFunctionTest("../vector_tests/constructor(std iterators).cpp", argv, env);
	runFunctionTest("../vector_tests/iterators.cpp", argv, env);
	runFunctionTest("../vector_tests/begin().cpp", argv, env);
	runFunctionTest("../vector_tests/end().cpp", argv, env);
	runFunctionTest("../vector_tests/rbegin().cpp", argv, env);
	runFunctionTest("../vector_tests/rend().cpp", argv, env);
	runFunctionTest("../vector_tests/size().cpp", argv, env);
	runFunctionTest("../vector_tests/max_size().cpp", argv, env);
	runFunctionTest("../vector_tests/resize().cpp", argv, env);
	runFunctionTest("../vector_tests/capacity().cpp", argv, env);
	runFunctionTest("../vector_tests/empty().cpp", argv, env);
	runFunctionTest("../vector_tests/reserve().cpp", argv, env);
	runFunctionTest("../vector_tests/operator[].cpp", argv, env);
	runFunctionTest("../vector_tests/at().cpp", argv, env);
	runFunctionTest("../vector_tests/front().cpp", argv, env);
	runFunctionTest("../vector_tests/back().cpp", argv, env);
	runFunctionTest("../vector_tests/assign().cpp", argv, env);
	runFunctionTest("../vector_tests/assign(std iterators).cpp", argv, env);
	runFunctionTest("../vector_tests/push_back().cpp", argv, env);
	runFunctionTest("../vector_tests/pop_back().cpp", argv, env);
	runFunctionTest("../vector_tests/insert(value).cpp", argv, env);
	runFunctionTest("../vector_tests/insert(fill).cpp", argv, env);
	runFunctionTest("../vector_tests/insert(range).cpp", argv, env);
	runFunctionTest("../vector_tests/insert(std iterators).cpp", argv, env);
	runFunctionTest("../vector_tests/erase(value).cpp", argv, env);
	runFunctionTest("../vector_tests/erase(range).cpp", argv, env);
	runFunctionTest("../vector_tests/swap().cpp", argv, env);
	runFunctionTest("../vector_tests/clear().cpp", argv, env);
	//runFunctionTest("../vector_tests/data().cpp", argv, env);
	runFunctionTest("../vector_tests/using allocator.cpp", argv, env);
	runFunctionTest("../vector_tests/operator ==.cpp", argv, env);
	runFunctionTest("../vector_tests/operator !=.cpp", argv, env);
	runFunctionTest("../vector_tests/operator <.cpp", argv, env);
	runFunctionTest("../vector_tests/operator >.cpp", argv, env);
	runFunctionTest("../vector_tests/operator <=.cpp", argv, env);
	runFunctionTest("../vector_tests/operator >=.cpp", argv, env);

	saveResult("vector_res");
	outputCurrentResult("VECTOR", _VECTOR_TEST_NUM);

	return 0;
}
