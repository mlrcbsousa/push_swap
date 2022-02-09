#!/bin/bash

echo "Error output tests."
./push_swap 1 2 3 4
./push_swap 1 2 3 hh
./push_swap 1 2 3 2147483648
./push_swap 1 2 3 -2147483649
./push_swap 1 2 3 3

echo "Error output tests using Checker."
ARG="1 2 3 2147483648"; ./push_swap $ARG | wc -l
ARG="1 2 3 2147483648"; ./push_swap $ARG | ./checker $ARG
ARG="1 2 3 hh"; ./push_swap $ARG | wc -l
ARG="1 2 3 hh"; ./push_swap $ARG | ./checker $ARG

echo "Size 3 stack."
./push_swap 1 2 3
./push_swap 1 2
./push_swap 2 1
./push_swap 1 3 2
./push_swap 2 1 3
./push_swap 2 3 1
./push_swap 3 2 1
./push_swap 3 1 2

echo "Size 3 stack with checker."
ARG="1 2 3"; ./push_swap $ARG | wc -l
ARG="1 2 3"; ./push_swap $ARG | ./checker $ARG
ARG="2 1 3"; ./push_swap $ARG | wc -l
ARG="2 1 3"; ./push_swap $ARG | ./checker $ARG

echo "Size 3 leaks."
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
					--num-callers=20 --track-fds=yes ./push_swap 2 1 3

echo "Size 5 stack."
./push_swap 1 5 2 4 3
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG

echo "Size 5 leaks."
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
					--num-callers=20 --track-fds=yes ./push_swap 1 5 2 4 3

echo "Size 7 stack."
./push_swap 87 -487 781 -100 101 0 1
ARG="87 -487 781 -100 101 0 1"; ./push_swap $ARG | wc -l
ARG="87 -487 781 -100 101 0 1"; ./push_swap $ARG | ./checker $ARG

echo "Size 7 leaks."
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
					--num-callers=20 --track-fds=yes ./push_swap 87 -487 781 -100 101 0 1
