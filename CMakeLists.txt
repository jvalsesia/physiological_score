cmake_minimum_required(VERSION 3.10)
project(NEWS_System)

set(CMAKE_CXX_STANDARD 17)

# Find GTest
find_package(GTest REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES
    ICU.cpp
    NEWSCalculator.cpp
)

# Test files
set(TEST_SOURCES
    test_patient.cpp
    test_parameters.cpp
    test_newscalculator.cpp
    test_led.cpp
    test_dashboard.cpp
    test_icu.cpp
)

# Create test executable
add_executable(run_tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(run_tests GTest::GTest GTest::Main)

# Enable testing
enable_testing()
add_test(NAME run_tests COMMAND run_tests)