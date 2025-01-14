cmake_minimum_required(VERSION 3.20)

project(parallel_algos_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  crng
  GIT_REPOSITORY https://github.com/msu-sparta/OpenRAND.git
  GIT_TAG        main
)

FetchContent_MakeAvailable(crng)

add_executable(parallel_algos_project
    src/main.cpp
    src/generator.cpp  
)

target_link_libraries(parallel_algos_project PRIVATE crng)

target_include_directories(parallel_algos_project PRIVATE include)
