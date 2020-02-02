make -s
gcc -Wall -Wextra -Werror -c main.c
gcc -Wall -Wextra -Werror -lftprintf -L . main.o -o test
./test
rm test main.o