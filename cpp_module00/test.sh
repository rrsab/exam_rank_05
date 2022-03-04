#!/bin/bash
c++ -Wall -Wextra -Werror -W -std=c++98 *.cpp -o start
./start | cat -e
rm start