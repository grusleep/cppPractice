# Write your makefile here
# Build an executable binary named "arrayModify"
all: arrayModify

arrayModify: arrayModify.o main.o
	g++ -W -Wall -o arrayModify arrayModify.o main.o

arrayModify.o: arrayModify.cc
	g++ -W -Wall -c -o arrayModify.o arrayModify.cc

main.o: main.cc
	g++ -W -Wall -c -o main.o main.cc

clean:
	rm -rf *.o arrayModify
