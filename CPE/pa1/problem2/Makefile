# Write your makefile here
# Build an executable binary named "arabians"
all: arabians

arabians: arabians.o display.o main.o
	g++ -W -Wall -o arabians arabians.o display.o main.o

arabians.o: arabians.cc
	g++ -W -Wall -c -o arabians.o arabians.cc

display.o: display.cc
	g++ -W -Wall -c -o display.o display.cc

main.o: main.cc
	g++ -W -Wall -c -o main.o main.cc

clean:
	rm -rf *.o arabians
