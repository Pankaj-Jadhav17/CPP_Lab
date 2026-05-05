CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = cipher

SRCS = main.cpp Cipher.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Cipher.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

run: all
	./$(TARGET)