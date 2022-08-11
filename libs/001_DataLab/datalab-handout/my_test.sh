#/bin/bash
make clean > my_log
make &> my_log
./btest -f $1
