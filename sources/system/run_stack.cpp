#include "engine.ipp"

using std::cout;

int main(int argc, char* argv[], char* env[]) {
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "|                                          STACK                                           |" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	printElement("FUNCTION"); printElement(WHITE + "RESULT" + RESET); printElement(WHITE + "FT TIME" + RESET); printElement(WHITE + "STD TIME" + RESET);
	printElement(WHITE + "LEAKS" + RESET); cout << endl;

	runFunctionTest("../stack_tests/constructor.cpp", argv, env);
	runFunctionTest("../stack_tests/push().cpp", argv, env);
	runFunctionTest("../stack_tests/top().cpp", argv, env);
	runFunctionTest("../stack_tests/pop().cpp", argv, env);
	runFunctionTest("../stack_tests/size().cpp", argv, env);
	runFunctionTest("../stack_tests/empty().cpp", argv, env);
	runFunctionTest("../stack_tests/operator ==.cpp", argv, env);
	runFunctionTest("../stack_tests/operator !=.cpp", argv, env);
	runFunctionTest("../stack_tests/operator <.cpp", argv, env);
	runFunctionTest("../stack_tests/operator >.cpp", argv, env);
	runFunctionTest("../stack_tests/operator <=.cpp", argv, env);
	runFunctionTest("../stack_tests/operator >=.cpp", argv, env);

	saveResult("stack_res");
	outputCurrentResult("STACK", _STACK_TEST_NUM);

	return 0;
}