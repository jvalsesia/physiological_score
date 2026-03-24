# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall

# Target executable name
TARGET = NEWS_System

# Object files
OBJS = main.o ICU.o NEWSCalculator.o

# Header Dependencies (for tracking changes)
HEADERS = Parameters.hpp Patient.hpp NEWSCalculator.hpp ICU.hpp \
          Observer.hpp Dashboard.hpp Led.hpp

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rules for object files
# We add the new UI headers to dependencies so changes trigger a rebuild
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

ICU.o: ICU.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c ICU.cpp

NEWSCalculator.o: NEWSCalculator.cpp NEWSCalculator.hpp Parameters.hpp
	$(CXX) $(CXXFLAGS) -c NEWSCalculator.cpp

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)