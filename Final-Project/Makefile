all: ./bin/main.e

./bin/main.e: ./build/image.o ./build/ops.o ./build/memory.o ./build/file.o ./build/main.o ./build/doLBPHistogram.o
	gcc -Wall -Isrc -Imain -o ./bin/main.e ./build/image.o ./build/ops.o ./build/memory.o ./build/file.o ./build/main.o ./build/doLBPHistogram.o

./build/image.o: ./src/image.c
	gcc -Wall -Isrc -Imain -o ./build/image.o -c ./src/image.c

./build/ops.o: ./src/ops.c
	gcc -Wall -Isrc -Imain -o ./build/ops.o -c ./src/ops.c

./build/memory.o: ./src/memory.c
	gcc -Wall -Isrc -Imain -o ./build/memory.o -c ./src/memory.c

./build/file.o: ./src/file.c
	gcc -Wall -Isrc -Imain -o ./build/file.o -c ./src/file.c

./build/main.o: ./main/main.c
	gcc -Wall -Isrc -Imain -o ./build/main.o -c ./main/main.c

./build/doLBPHistogram.o: ./src/doLBPHistogram.c
	gcc -Wall -Isrc -Imain -o ./build/doLBPHistogram.o -c ./src/doLBPHistogram.c

clean:
	rm -f ./build/*.o ./bin/main.e

cleanimages:
	rm -f ./output/*.pgm ./output/*.p
