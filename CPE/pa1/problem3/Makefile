# Write your makefile here
# Build an executable binary named "guessGame"
all: guessGame

guessGame: guess.o main.o
	g++ -W -Wall -o guessGame guess.o main.o

guess.o: guess.cc
	g++ -W -Wall -c -o guess.o guess.cc

main.o: main.cc
	g++ -W -Wall -c -o main.o main.cc

clean:
	rm -rf *.o guessGame