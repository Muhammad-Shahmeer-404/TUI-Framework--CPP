# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -g

CC = gcc
CFLAGS = -g

TARGET = engine_test

C_SRCS = $(wildcard Terminal/*.c)

CPP_SRCS = $(wildcard Core/*.cpp) main.cpp

CPP_OBJS = $(CPP_SRCS:.cpp=.o)
C_OBJS = $(C_SRCS:.c=.o)

ALL_OBJS = $(C_OBJS) $(CPP_OBJS)

$(TARGET): $(ALL_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(ALL_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(ALL_OBJS) $(TARGET)
