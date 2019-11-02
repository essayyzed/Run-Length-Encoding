
all: prog

prog:main.o encoder.o decoder.o
	g++ main.o encoder.o decoder.o -o insert


main.o: main.cpp
	g++ -c main.cpp

encoder.o: encoder.cpp
	g++ -c encoder.cpp

decoder.o: decoder.cpp
	g++ -c decoder.cpp

run:
	./insert

clean:
	rm -rf *.o
