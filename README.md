Gemini said
To compile a multi-file C++ project efficiently, a Makefile is the standard tool. It ensures that only the files you have changed get recompiled, saving time as the project grows.

The Makefile
Create a file named Makefile (no extension) in the same directory as your source files and paste the following:

Makefile
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
main.o: main.cpp ICU.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ICU.o: ICU.cpp ICU.h Patient.h NEWSCalculator.h Parameters.h
	$(CXX) $(CXXFLAGS) -c ICU.cpp

NEWSCalculator.o: NEWSCalculator.cpp NEWSCalculator.h Parameters.h
	$(CXX) $(CXXFLAGS) -c NEWSCalculator.cpp

# Clean rule to remove build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
How to use it
Open your terminal or command prompt in the folder containing your files.

Compile: Type make and press Enter. This will create the NEWS_System executable.

Run: * On Linux/Mac: ./NEWS_System

On Windows (if using MinGW): NEWS_System.exe

Reset: Type make clean if you want to remove the compiled files and start fresh.

