#!/bin/bash
clang++ main_test_vector.cpp -o real.out && clang++ main_test_ft_vector.cpp && ./real.out > real_vector.txt && ./a.out > ft_vector.txt && diff ft_vector.txt real_vector.txt