GCC = gcc
AR = ar -rcs #creating libs
FLAGS = -Wall -g

make basicClassification.o: basicClassification.c
	gcc -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(GCC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecusion.o: advancedClassificationRecursion.c
	$(GCC) $(FLAGS) -c advancedClassificationRecursion.c

main.o: main.c
	$(GCC) $(FLAGS) -c main.o
	

#Static libraries

loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	$(AR) -rcs libvlassloops.a basicClassification.o advancedClassificationLoop.o
	
recursives: libclassrec.a
libclassrec.a: advancedClassificationRecursion.o 
	$(AR) -rcs libclassrec.a advancedClassificationRecursion.o
	
	
#Dynamic libraries

recursived: libclassrec.so
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(GCC) $(FLAGS) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o -lm
	
looped: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(GCC) $(FLAGS) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o -lm

#mains

mains: main.o libclassrec.a
	$(GCC) $(FLAGS) -o mains main.o ./libclassrec.o -lm

maindloop: main.o libclassloops.so
	$(GCC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	$(GCC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

all: loops looped recursived recursives mains maindloop maindrec

clean: 
	rm -f *.o *.a *.so mains mainloop maindrec


