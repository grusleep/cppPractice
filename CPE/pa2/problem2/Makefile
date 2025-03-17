# Write your makefile here
CXXFLAGS=-W -Wall

all: calculator

calculator: calculator.o main.o
	g++ $(CXXFLAGS) -o $@ $^

calculator.o: calculator.cc
	g++ $(CXXFLAGS) -c -o $@ $^

main.o: main.cc
	g++ $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf *.o calculator