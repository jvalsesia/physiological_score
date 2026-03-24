#!/bin/bash

# NEWS System Build and Test Script
echo "Starting NEWS System build and test process..."

# Clean previous builds
echo "Cleaning previous builds..."
rm -rf build/
rm -f NEWS_System

# Build main application
echo "Building main application..."
g++ -std=c++23 -Wall -o NEWS_System main.cpp ICU.cpp NEWSCalculator.cpp

# Build and run tests
echo "Building test suite..."
mkdir -p build
cd build
cmake ..
make

echo "Running tests..."
./run_tests

cd ..

echo "Build and test process completed successfully!"
echo "Executables created: NEWS_System, build/run_tests"
