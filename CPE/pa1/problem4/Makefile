# Write your makefile here
# Build an executable binary named "wordProcess"
all: wordProcess

wordProcess: wordProcess.o main.o
	g++ -W -Wall -o wordProcess wordProcess.o main.o

wordProcess.o: wordProcess.cc
	g++ -W -Wall -c -o wordProcess.o wordProcess.cc

main.o: main.cc
	g++ -W -Wall -c -o main.o main.cc

clean:
	rm -rf *.o wordProcess