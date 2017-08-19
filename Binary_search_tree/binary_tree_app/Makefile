objects = main.o delete.o insert.o print.o search.o height.o IsSort.o
 cc = gcc

app : $(objects)
	cc -o app $(objects)

main.o : tree.h
delete.o : tree.h
insert.o : tree.h 
print.o  : tree.h 
search.o : tree.h 
height.o: tree.h
Issort.o : tree.h


.PHONY : clean
clean :
	rm edit $(objects)         
