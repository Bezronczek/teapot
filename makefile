#Makefile
#	Author: Rafał Czaja
#	Date: 25-02-13

all: Teapot++/main.cpp Teapot++/parser.h Teapot++/parser.cpp
	g++ $^ -o ./bin/tc --std=c++0x 

clean:
	rm -rf *.o 
	
