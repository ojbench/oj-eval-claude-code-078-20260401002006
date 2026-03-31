CXX = g++-13
CXXFLAGS = -std=c++17 -O2

all: code

code: main.cpp evil.hpp
	$(CXX) $(CXXFLAGS) -o code main.cpp

clean:
	rm -f code

.PHONY: all clean
