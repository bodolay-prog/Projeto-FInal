all: ./bin/main.e
	./bin/main.e

./bin/main.e: ./build/image.o ./build/ops.o ./build/memory.o ./build/csv.o ./build/main.o ./build/process.o
	gcc -march=native -Wall -Isrc -Imain -o ./bin/main.e ./build/image.o ./build/ops.o ./build/memory.o ./build/csv.o ./build/main.o ./build/process.o

./build/image.o: ./src/image.c
	gcc -Wall -Isrc -Imain -o ./build/image.o -c ./src/image.c

./build/ops.o: ./src/ops.c
	gcc -Wall -Isrc -Imain -o ./build/ops.o -c ./src/ops.c

./build/memory.o: ./src/memory.c
	gcc -Wall -Isrc -Imain -o ./build/memory.o -c ./src/memory.c

./build/csv.o: ./src/csv.c
	gcc -Wall -Isrc -Imain -o ./build/csv.o -c ./src/csv.c

./build/main.o: ./main/main.c
	gcc -Wall -Isrc -Imain -o ./build/main.o -c ./main/main.c

./build/process.o: ./src/process.c
	gcc -Wall -Isrc -Imain -o ./build/process.o -c ./src/process.c

clean:
	rm -f ./build/*.o ./bin/main.e

cleanimages:
	rm -f ./output/*.pgm ./output/*.p
