GCC = gcc
AR = ar -rcs
FLAGS = -Wall -g

basicClassification.o: basicClassification.c
	$(GCC) $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(GCC) $(FLAGS) -fPIC -c advancedClassificationLoop.c

advancedClassificationRecusion.o: advancedClassificationRecursion.c
	$(GCC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c

main.o: main.c
	$(GCC) $(FLAGS) -c main.c
	

#Static libraries

loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	$(AR) libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a
	
recursives: libclassrec.a
libclassrec.a: basicClassification.o advancedClassificationRecursion.o 
	$(AR) libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a
	
	
#Dynamic libraries

recursived: libclassrec.so
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(GCC) $(FLAGS) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o -lm
	
loopd: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(GCC) $(FLAGS) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o -lm

#mains

mains: main.o libclassrec.a
	$(GCC) $(FLAGS) main.o libclassrec.a -o mains -lm

maindloop: main.o libclassloops.so
	$(GCC) $(FLAGS) main.o ./libclassloops.so -o maindloop -lm

maindrec: main.o libclassrec.so 
	$(GCC) $(FLAGS)  main.o ./libclassrec.so -o maindrec -lm

all: loops loopd recursived recursives mains maindloop maindrec

clean: 
	rm -f *.o *.a *.so mains mainloop maindrec

.PHONY: all clean loopd loops recursived recursives
