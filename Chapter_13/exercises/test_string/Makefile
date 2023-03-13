# the compiler: gcc for C program, define as g++ for C++
CC=g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
# CFLAGS  = -g -Wall
CFLAGS= -std=c++11

# the build target executable:
TARGET = test

# DEPS = 

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)


all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(DEPS) $(TARGET).cpp

clean:
	$(RM) $(TARGET)