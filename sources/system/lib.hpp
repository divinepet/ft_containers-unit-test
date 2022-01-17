#ifndef UNIT_TESTS_HPP
# define UNIT_TESTS_HPP

#ifdef FAST
int _ratio = 1;
#else
int _ratio = 10000;
#endif

int _allocator_used = 0;

#include <array>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <fstream>
#include <execinfo.h>
#include <iomanip>
#include <sys/time.h>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <csignal>
#include <unistd.h>
#include <fcntl.h>
#include "../../config.hpp"
#include "output.hpp"
#include "Alloc.hpp"

volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;

#endif