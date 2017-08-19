objects = main.o operation.o
 cc = gcc

app : $(objects)
	cc -o app $(objects)

main.o : list.h
operation.o : list.h


.PHONY : clean
clean :
	rm app $(objects)         
