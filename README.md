# ft_containers-unit-test

![screenshot](https://raw.githubusercontent.com/divinepet/ft_containers-unit-test/main/sources/system/credits/screenshot.gif)

## <i>About
<span><b>ft_containers-unit-test</b></span> is a complete testing for project of school 21/ecole 42 and allowing you test your containers: <b>Vector</b>, <b>Stack</b>, <b>Map</b>, <b>Set</b> and <b>Utilities</b> in <b>ft</b> namespace.</br>
This test checks 90% of subject and checklist requires: <b>using std allocator, iterator traits, benchmark, leaks, segfaults, timeouts</b> etc. But keep in mind that test doesn't check something you don't need to implement and was written by students, so im waiting for your bugs or suggestions for improving</i>

# Getting started
## ⬇️ 1. Installation
run this command <b>inside</b> your ft_containers folder:
```shell
git clone https://github.com/divinepet/ft_containers-unit-test
```
then
```shell
cd ft_containers-unit-test
```
now you need to configure file ```config.hpp``` and write correct names of all your files and classes
## 🛠 2. Configure your config.hpp
if you haven't some class implementation yet, for example <b>Map</b>, you need to <b><i>comment</i></b> appropriate line in ```config.hpp```:
```c++
// #define MAP     "../../../Map.hpp"
```
and etc. for other. The same with flags - <b><i>uncomment</i></b> this line to <b>enable</b> them
```c++
#define FLAGS
```
## 📝 3. Run start.sh
Now you can execute ```start.sh``` and testing will start</br></br>
Also you can run tests with a specific container, use flags for this:
```shell
./start.sh -v # for vector
./start.sh -u # for utilities
./start.sh -st # for stack
./start.sh -m # for map
./start.sh -s # for set
./start.sh -h # help with commands
```
Use the <b>-fast</b> flag to run the test in simplified mode - the amount of data processed by each container is reduced to speed up its execution.
## 🐧 Running on Linux
In most cases it should resolve many conflicts:
1. <b>comment</b> these lines: [line 32](sources/system/run_set.cpp#L32), [line 35](sources/system/run_map.cpp#L35), [line 24](sources/system/lib.hpp#L24)
2. <b>add</b> libraries in this [file](sources/system/engine.ipp):
```c++
#include <string.h>
#include <sys/wait.h>
```
3. <b>remove</b> this [file](sources/system/Alloc.hpp) from project


# Results

![](https://via.placeholder.com/15/f00/000000?text=+) <b>NOT COMPILED</b> means that method compiles with errors, also probably some template name in ```config.hpp``` is incorrect</br>
![](https://via.placeholder.com/15/f90/000000?text=+) <b>TIMEOUT</b> means the method exceeded the maximal execution time, probably due to an infinite loop
#### Press Star ⭐ button at the top right corner of page if this test was useful to you, so that more people can see it
