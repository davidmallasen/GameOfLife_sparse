cmake_minimum_required(VERSION 3.4...3.18)

project(GameOfLife_sparse VERSION 1.0
                            DESCRIPTION "Sparse efficient implementation of Conway's Game of Life"
                            LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)

add_executable(main.out 
    src/main.cpp
    src/game_of_life.cpp
)

set_target_properties(main.out
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "lib/"
    LIBRARY_OUTPUT_DIRECTORY "lib/"
    RUNTIME_OUTPUT_DIRECTORY "bin/"
)

# define header file path
target_include_directories(main.out PRIVATE include)

# set to use C++20 features
target_compile_features(main.out PRIVATE cxx_std_20)

# set compiler options
target_compile_options(main.out PRIVATE -Wall -O3)

# specify what to install when we run 'make install'
install(TARGETS main.out DESTINATION bin) 
