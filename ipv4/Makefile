CXX = g++
CFLAGS = -std=c++17
TARGET = a.out

all: $(TARGET)

ipv4.o: ipv4.cpp ipv4.hpp
	$(CXX) $(CFLAGS) ipv4.cpp -c

$(TARGET): ipv4.o main.cpp
	$(CXX) $(CFLAGS) ipv4.o main.cpp -o $(TARGET)

clean:
	rm *.out *.o
