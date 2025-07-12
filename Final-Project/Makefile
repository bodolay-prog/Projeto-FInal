all: ./bin/main.e
	./bin/main.e

./bin/main.e: ./build/image.o ./build/ops.o ./build/memory.o ./build/csv.o ./build/main.o ./build/doHistogram.o
	gcc -march=native -Wall -Isrc -Imain -o ./bin/main.e ./build/image.o ./build/ops.o ./build/memory.o ./build/csv.o ./build/main.o ./build/doHistogram.o

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

./build/doHistogram.o: ./src/doHistogram.c
	gcc -Wall -Isrc -Imain -o ./build/doHistogram.o -c ./src/doHistogram.c

clean:
	rm -f ./build/*.o ./bin/main.e

cleanimages:
	rm -f ./output/*.pgm ./output/*.p
