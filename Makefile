all: main
	
main: main.cpp
	g++ -DTRACE -std=c++11 -g -o main main.cpp
	
notrace: main.cpp
	g++ -std=c++11 -o main main.cpp
	
clean:
	rm main

run:
	./main.exe
	
inp:
	./main.exe<in