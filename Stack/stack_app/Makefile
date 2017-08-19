objects = main.o operation.o
 cc = gcc

app : $(objects)
	cc -o app $(objects)

main.o : stack.h
operation.o : stack.h


.PHONY : clean
clean :
	rm edit $(objects)         
