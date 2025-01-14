cmake_minimum_required(VERSION 3.20)

# Project name and language
project(parallel_algos_project LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent for managing dependencies
include(FetchContent)

# Declare the crng library dependency
FetchContent_Declare(
  crng
  GIT_REPOSITORY https://github.com/msu-sparta/OpenRAND.git
  GIT_TAG        main
)

# Fetch and make the crng library available
FetchContent_MakeAvailable(crng)

# Add the executable
add_executable(parallel_algos_project
    src/main.cpp
    src/generator.cpp  
)

# Add include directories
target_include_directories(parallel_algos_project PRIVATE 
    include
    ${crng_SOURCE_DIR}/include
)

# Specify library directories and link crng
target_link_directories(parallel_algos_project PRIVATE ${crng_BINARY_DIR})
target_link_libraries(parallel_algos_project PRIVATE crng)

# Debugging information
message(STATUS "crng source directory: ${crng_SOURCE_DIR}")
message(STATUS "crng binary directory: ${crng_BINARY_DIR}")
