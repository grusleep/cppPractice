CXXFLAGS=-W -Wall

all: skku_sh

skku_sh: Directory.o Entry.o main.o File.o
	g++ $(CXXFLAGS) -o $@ $^

Directory.o: Directory.cc
	g++ $(CXXFLAGS) -c -o $@ $^

Entry.o: Entry.cc
	g++ $(CXXFLAGS) -c -o $@ $^

File.o: File.cc
	g++ $(CXXFLAGS) -c -o $@ $^

main.o: main.cc
	g++ $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf *.o skku_sh