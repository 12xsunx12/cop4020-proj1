# Define compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = app

# Source files
SOURCES = $(wildcard *.cpp)

# Header files
HEADERS = $(wildcard *.h)

# Rule to build the target
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Phony target to clean up
.PHONY: clean
clean:
	rm -f $(TARGET)

# Target to run the executable
.PHONY: run
run: $(TARGET)
	./$(TARGET)

