objects = main.o operation.o
 cc = gcc

app : $(objects)
	cc -o app $(objects)

main.o : queue.h
operation.o : queue.h


.PHONY : clean
clean :
	rm app $(objects)         
