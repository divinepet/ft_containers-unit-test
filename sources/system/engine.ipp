#pragma once
#include "lib.hpp"

#define _CXX "/usr/bin/clang++"
#define _CXX_FLAGS ""
#define _EXEC_NAME "test1"
#define _ALARM_TIMEOUT 20

void testCompile(int *status, const char* func_filename, char **env) {

    int     fd_log = open("../../logs.txt", O_RDWR | O_CREAT, 0777 | O_TRUNC, S_IRUSR | S_IWUSR);
    pid_t   pid;
    char**  test_args = (char**)malloc(sizeof(char*) * 6);

    test_args[0] = strdup(_CXX);
    test_args[1] = strdup(_CXX_FLAGS);
    test_args[2] = strdup("-o");
    test_args[3] = strdup(_EXEC_NAME);
    test_args[4] = strdup(func_filename);
    test_args[5] = NULL;

    pid = fork();
    if (!pid) {
        dup2(fd_log, 2);
        close(fd_log);
        execve(_CXX, test_args, env);
        std::cout << "execve: error: " << strerror(errno) << std::endl;
        exit(errno);
    }
    close(fd_log);
    waitpid(pid, status, WUNTRACED | WCONTINUED);
}

void testExecution(int *status, std::string output, char** argv, char **env) {

    pid_t   pid;

    if (*status == 0) {
        pid = fork();
        if (!pid) {
            alarm(_ALARM_TIMEOUT);
            execve(_EXEC_NAME, argv, env);
            std::cout << "execve: error: " << strerror(errno) << std::endl;
            exit(errno);
        }
        waitpid(pid, status, WUNTRACED | WCONTINUED);
        if (*status == 11) {
            printElement(output);
            printElement(REDD + "SEGFAULT" + RESET);
            cout << endl;
        }
        else if (*status == 14) {
            printElement(output);
            printElement(YELLOW + "TIMEOUT" + RESET);
            cout << endl;
        }
    }
    else if (*status == 256) {
        printElement(output);
        printElement(REDD + "NOT COMPILED" + RESET);
        cout << endl;
    }
}

void runNonCompilable(std::string func_filename, char** argv, char** env) {

	std::string tmp = func_filename.substr(func_filename.find_last_of('/') + 1);
	std::string output = tmp.erase(tmp.length() - 4);

	char buffer[256];
	std::string result;
	std::string cxx = _CXX;
	std::string cxx_flags = _CXX_FLAGS;
	std::string exec_name = _EXEC_NAME;
	std::string test = cxx + " " + cxx_flags + " 2>&1 >/dev/null " + "-o " + exec_name + " " + func_filename;
	FILE *pipe = popen(test.c_str(), "r");

	while (std::fgets(buffer, sizeof buffer, pipe) != NULL) {
		result += buffer;
	}
	pclose(pipe);
	printElement(output);
	if (result.find("1 error generated") != std::string::npos
	&& result.find("error: cannot assign to non-static data member 'first' with const-qualified type 'const int'") != std::string::npos) {
		printElement("OK");
		std::cout << "" << std::endl;
	}
	else {
		printElement("FAILED");
		std::cout << "" << std::endl;
	}
}


void runFunctionTest(std::string func_filename, char** argv, char **env) {

    int         status = 0;
    std::string tmp = func_filename.substr(func_filename.find_last_of('/') + 1);
    std::string output = tmp.erase(tmp.length() - 4);

    testCompile(&status, func_filename.c_str(), env);
    testExecution(&status, output, argv, env);
}