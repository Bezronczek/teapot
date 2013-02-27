#Makefile
#	Author: Rafał Czaja
#	Date: 25-02-13

all: Teapot++/main.cpp Teapot++/parser.h Teapot++/parser.cpp Teapot++/TEALex.cpp Teapot++/TEAParser.cpp Teapot++/TEA0x7dd.cpp Teapot++/TEABinary.cpp
	g++ $^ -o ./bin/tc --std=c++0x  -lboost_program_options -ljson -I./lib/jsoncpp-src-0.5.0/include -L./lib/jsoncpp-src-0.5.0/libs

clean:
	rm -rf *.o 
	
