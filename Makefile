# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable name
TARGET = NEWS_System

# Object files
OBJS = main.o ICU.o NEWSCalculator.o

# Default rule: build the executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rules for object files
main.o: main.cpp ICU.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

ICU.o: ICU.cpp ICU.hpp Patient.hpp NEWSCalculator.hpp Parameters.hpp
	$(CXX) $(CXXFLAGS) -c ICU.cpp

NEWSCalculator.o: NEWSCalculator.cpp NEWSCalculator.hpp Parameters.hpp
	$(CXX) $(CXXFLAGS) -c NEWSCalculator.cpp

# Clean rule to remove build artifacts
clean:
	rm -f $(OBJS) $(TARGET)