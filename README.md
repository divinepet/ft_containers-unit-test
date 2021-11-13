# ft_containers-unit-test

![screenshot](https://raw.githubusercontent.com/divinepet/ft_containers-unit-test/main/sources/system/credits/screenshot.gif)

# About
<span>ft containers unit test</span> is a complete testing for project of school 21/ecole 42 and allowing you test your containers: <b>Vector</b>, <b>Stack</b>, <b>Map</b>, <b>Set</b> and <b>Utilities</b> in <b>ft</b> namespace.</br>
This test checks 90% of subject and checklist requires: <b>using std allocator, iterator traits, benchmark, leaks, segfaults, timeouts</b> etc. But keep in mind that test doesn't check something you don't need to implement and was written by students, so im waiting for your bugs or suggestions for improving

# Getting started
## ⚙️ Installation
run this command <b>inside</b> your ft_containers folder:
```shell
git clone https://github.com/divinepet/ft_containers-unit-test
```
then
```shell
cd ft_containers-unit-test
```
now you need to configure file ```config.hpp``` and write correct names of all your files and classes, and the last step is
```shell
./start.sh
```
## ⚠️ config.hpp
if you haven't some class implementation yet, for example <b>Map</b>, you need to <b><i>comment</i></b> appropriate line:
```c++
...
// #define MAP     "../../../Map.hpp"
...
```
and etc. for other. The same with flags - uncomment this line to enable them
```c++
#define FLAGS
```
## 📄 start.sh
you can run tests with a specific container, use flags for this
```shell
./start.sh -v # for vector
./start.sh -u # for utilities
./start.sh -st # for stack
./start.sh -m # for map
./start.sh -s # for set
./start.sh -h # help with commands
```
# Results

![](https://via.placeholder.com/15/f00/000000?text=+) <b>NOT COMPILED</b> means that method compiles with errors, also probably some template name in ```config.hpp``` is incorrect</br>
![](https://via.placeholder.com/15/f90/000000?text=+) <b>TIMEOUT</b> means the method exceeded the maximal execution time, probably due to an infinite loop
#### Press Star ⭐ button in the right corener if this test was useful to you, so that more people can see it
