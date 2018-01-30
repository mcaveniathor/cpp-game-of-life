all: OBJECTS
	$(CXX) $(CXXFLAGS) main2.o pbm.o -o gol
SOURCES = main2.cpp pbm.cpp
OBJECTS: 
	$(CXX) $(LDFLAGS) -c $(SOURCES)
CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
LDFLAGS = $(CXXFLAGS)
clean:
	rm gol *.o *.pbm
