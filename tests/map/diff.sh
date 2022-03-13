#!/bin/bash
clang++ main_test_map.cpp -o real.out && clang++ main_test_ft_map.cpp && ./real.out > real_map.txt && ./a.out > ft_map.txt && diff ft_map.txt real_map.txt