# Write your makefile here
CXXFLAGS=-W -Wall

all: fraction

fraction: fraction.o main.o
	g++ $(CXXFLAGS) -o $@ $^

fraction.o: fraction.cc
	g++ $(CXXFLAGS) -c -o $@ $^

main.o: main.cc
	g++ $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf *.o fraction