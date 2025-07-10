all: ./exec/lbp.e

./exec/lbp.e: ./lib/image.o ./lib/ops.o ./lib/readdir.o ./lib/memory.o ./lib/file.o
	gcc -o ./exec/lbp.e ./lib/image.o ./lib/ops.o ./lib/readdir.o ./lib/memory.o ./lib/file.o

./lib/image.o: ./lib/image.c
	gcc -o ./lib/image.o -c ./lib/image.c

./lib/ops.o: ./lib/ops.c
	gcc -o ./lib/ops.o -c ./lib/ops.c

./lib/readdir.o: ./readdir.c
	gcc -o ./lib/readdir.o -c ./readdir.c

./lib/memory.o: ./lib/memory.c
	gcc -o ./lib/memory.o -c ./lib/memory.c

./lib/file.o: ./lib/file.c
	gcc -o ./lib/file.o -c ./lib/file.c

clean:
	rm -f ./lib/*.o ./exec/lbp.e

cleanimages:
	rm -f ./output-tests/*.pgm ./output-tests/*.p
