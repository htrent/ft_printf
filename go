make -sC libft
gcc -Wall -Wextra -Werror -c main.c
gcc -Wall -Wextra -Werror -lftprintf -L libft main.o -o test
./test
rm test main.o