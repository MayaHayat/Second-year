GCC = gcc
AR = ar -rcs
FLAGS = -Wall -g


my_mat.o: my_mat.c my_mat.h
	$(GCC) $(FLAGS) -fPIC -c my_mat.c 

main.o: main.c my_mat.h
	$(GCC) $(FLAGS) -fPIC -c main.c

my_mat.a: my_mat.o
	$(AR) my_mat.a my_mat.o
	ranlib my_mat.a


connections:my_mat.a main.o
	$(GCC) $(FLAGS) my_mat.a main.o -o connections -lm

all: connections

clean: 
	rm -f *.o connections