make -s
gcc -c main.c
gcc -lftprintf -L . main.o -o test
./test
rm test main.o