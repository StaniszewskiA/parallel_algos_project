# Minimum version of CMake
cmake_minimum_required(VERSION 3.20)

# Project name and language
project(parallel_algos_project LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent to include the crng library
include(FetchContent)

FetchContent_Declare(
  crng
  GIT_REPOSITORY https://github.com/msu-sparta/OpenRAND.git
  GIT_TAG        main
)

# Ensure FetchContent downloads and builds the dependency
FetchContent_MakeAvailable(crng)

# Add the main executable
add_executable(parallel_algos_project
    src/main.cpp
)

# Link the crng library to the executable
target_link_libraries(parallel_algos_project PRIVATE crng)

# Include the project's header files
target_include_directories(parallel_algos_project PRIVATE include)
