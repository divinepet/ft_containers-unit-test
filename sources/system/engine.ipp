#pragma once
#include "lib.hpp"
#include "bass24/bass.h"

#define _CXX "/usr/bin/clang++"
#define _CXX_FLAGS "-Wall -Wextra -Werror"
#define _EXEC_NAME "test1"
#define _ALARM_TIMEOUT 20
#define _VECTOR_TEST_NUM 37
#define _STACK_TEST_NUM 12
#define _UTILITIES_TEST_NUM 5
#define _SET_TEST_NUM 29
#define _MAP_TEST_NUM 32
#define _TOTAL_TEST_NUM 86
#define _TOTAL_TEST_NUM_BONUS 115
#define _TASK_NUM 4
#define _TASK_NUM_BONUS 1

void saveResult(std::string test_name) {

    std::string filename = "./results/" + test_name;
//    std::cout << filename << std::endl;
    int fd = open(filename.c_str(), O_RDWR | O_CREAT , 0777 | O_TRUNC, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    std::string result = std::to_string(_test_passed_cnt);

    write(fd, result.c_str(), sizeof result.c_str());
    close(fd);
}

void testCompile(int *status, const char* func_filename, char **env) {

    int     fd_log = open("../../logs.txt", O_RDWR | O_CREAT , 0777 | O_APPEND, S_IRUSR | S_IWUSR);
    pid_t   pid;
    char**  test_args = (char**)malloc(sizeof(char*) * 9);

    test_args[0] = strdup(_CXX);
    test_args[1] = strdup("-o");
    test_args[2] = strdup(_EXEC_NAME);
    test_args[3] = strdup(func_filename);
	#if defined(FLAGS)
    test_args[4] = strdup("-std=c++98");
    test_args[5] = strdup("-Wall");
    test_args[6] = strdup("-Wextra");
    test_args[7] = strdup("-Werror");
    test_args[8] = NULL;
	#else
    test_args[4] = NULL;
	#endif

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
        *status = -1;
        pid = fork();
        if (!pid) {
            alarm(_ALARM_TIMEOUT);
            execve(_EXEC_NAME, argv, env);
            std::cout << "execve: error: " << strerror(errno) << std::endl;
            exit(errno);
        }
        waitpid(pid, status, WUNTRACED | WCONTINUED);
//        std::cout << "status: " << *status << std::endl;
        if (*status == 0)
            _test_passed_cnt++;
        else if (*status == 11) {
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
    else {
        printElement(output);
        printElement(YELLOW + "UNKNOWN" + RESET);
        cout << endl;
    }
}

void runNonCompilable(std::string func_filename, char** argv, char** env) {

    std::string tmp = func_filename.substr(func_filename.find_last_of('/') + 1);
    std::string output = tmp.erase(tmp.length() - 4);

    int fd_log;
    char buffer[256];
    std::string result;
    std::string cxx = _CXX;
//    std::string cxx_flags = _CXX_FLAGS;
    std::string cxx_flags = "";
    std::string exec_name = _EXEC_NAME;
    std::string test = cxx + " " + cxx_flags + " 2>&1 >/dev/null " + "-o " + exec_name + " " + func_filename;
    FILE *pipe = popen(test.c_str(), "r");

    while (std::fgets(buffer, sizeof buffer, pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
//    std::cout << result << std::endl;
    printElement(output);
    if (result.find("1 error generated") != std::string::npos
    && result.find("error: cannot assign to non-static data member 'first' with const-qualified type") != std::string::npos) {
        printElement("OK");
        std::cout << "" << std::endl;
        _test_passed_cnt++;
    }
    else {
        fd_log = open("../../logs.txt", O_RDWR | O_CREAT , 0777 | O_APPEND, S_IRUSR | S_IWUSR);
        if (!fd_log)
            return ;
        write(fd_log, result.c_str(), result.length());
        close(fd_log);
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
