cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Logica VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the executable
add_executable(logica ${SOURCES})

# Include headers
target_include_directories(logica PRIVATE ${PROJECT_SOURCE_DIR}/src)
