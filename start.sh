#!/bin/bash

trap 'rm -f a.out test1 ;yes | rm -f results/*; echo -e "\n"See 📄 "\033[1mlogs.txt\033[0m" for more information. "\n""\033[1mWARNING:\033[0m" it will be rewrite next execution' EXIT
echo "" > logs.txt
yes | rm -f sources/system/results/*
cd sources/system/
if [[ $1 = -m || $1 = --map ]]
then
  cat credits/header
  clang++ run_map.cpp && ./a.out
elif [[ $1 = -v || $1 = --vector ]]
then
  cat credits/header
  clang++ run_vector.cpp && ./a.out
elif [[ $1 = -s || $1 = --set ]]
then
  cat credits/header
  clang++ run_set.cpp && ./a.out
elif [[ $1 = -u || $1 = --utils ]]
then
  cat credits/header
  clang++ run_utilities.cpp && ./a.out
elif [[ $1 = -st || $1 = --stack ]]
then
  cat credits/header
  clang++ run_stack.cpp && ./a.out
elif [[ $1 = '' ]]
then
  cat credits/header
  clang++ run_vector.cpp && ./a.out
  clang++ run_utilities.cpp && ./a.out
  clang++ run_stack.cpp && ./a.out
  clang++ run_map.cpp && ./a.out
  clang++ libbass.dylib -Ibass24 -Lbass24 check_results.cpp && ./a.out
elif [[ $1 = -b || $1 = --bonus ]]
then
  cat credits/header
  clang++ run_vector.cpp && ./a.out
  clang++ run_utilities.cpp && ./a.out
  clang++ run_stack.cpp && ./a.out
  clang++ run_map.cpp && ./a.out
  clang++ run_set.cpp && ./a.out
  clang++ libbass.dylib -Ibass24 -Lbass24 check_results.cpp && ./a.out
elif [[ $1 = -h || $1 = --help ]]
then
  echo -e "-v, --vector \t\t Run VECTOR tests\n" \
          "-m, --map \t\t Run MAP tests\n" \
          "-s, --set \t\t Run SET tests\n" \
          "-st, --stack \t\t Run SET tests\n" \
          "-u, --utils \t\t Run UTILITIES tests\n" \
          "-b, --bonus \t\t Run ALL tests (with set)\n" \
          "Run ./start.sh without arguments to run mandatory part tests"
else
  echo Uknown command. Use --help or -h for command list
fi
rm -f a.out test1
yes | rm -f results/*
