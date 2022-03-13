#!/bin/bash
clang++ main_test_stack.cpp -o real.out && clang++ main_test_ft_stack.cpp && ./real.out > real_stack.txt && ./a.out > ft_stack.txt && diff ft_stack.txt real_stack.txt