all: ./exec/lbp.e

./exec/lbp.e: ./lib/image.o ./lib/ops.o ./lib/readdir.o
	gcc -o ./exec/lbp.e ./lib/image.o ./lib/ops.o ./lib/readdir.o

./lib/image.o: ./lib/image.c
	gcc -o ./lib/image.o -c ./lib/image.c

./lib/ops.o: ./lib/ops.c
	gcc -o ./lib/ops.o -c ./lib/ops.c

./lib/readdir.o: ./readdir.c
	gcc -o ./lib/readdir.o -c ./readdir.c

clean:
	rm -f ./lib/*.o ./exec/lbp.e
