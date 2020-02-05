make -s
gcc -Wformat -c main.c
gcc -Wformat -lftprintf -L . main.o -o test
./test
rm test main.o