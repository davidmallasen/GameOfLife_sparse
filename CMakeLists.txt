cmake_minimum_required(VERSION 3.4...3.18)

project(GameOfLife_sparse 
    VERSION 1.0
    DESCRIPTION "Sparse efficient implementation of Conway's Game of Life"
    LANGUAGES CXX
)

set(CMAKE_CXX_COMPILER g++)

add_executable(main.out 
    src/main.cpp
    src/game_of_life.cpp
)

add_executable(tests.out
    tests/game_of_life_test.cpp
    src/game_of_life.cpp
)

add_executable(perf.out
    src/perf_test.cpp
    src/game_of_life.cpp
)

set_target_properties(main.out tests.out perf.out
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "lib/"
    LIBRARY_OUTPUT_DIRECTORY "lib/"
    RUNTIME_OUTPUT_DIRECTORY "bin/"
)

find_package(GTest REQUIRED)

# Define header file path
target_include_directories(main.out PRIVATE include)
target_include_directories(tests.out PRIVATE include ${GTEST_INCLUDE_DIRS})
target_include_directories(perf.out PRIVATE include)

target_link_libraries(tests.out ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(perf.out profiler tcmalloc)
target_link_options(perf.out PRIVATE -ggdb -Wl,-no-as-needed)

# Set to use C++17 features
target_compile_features(main.out PRIVATE cxx_std_17)
target_compile_features(tests.out PRIVATE cxx_std_17)
target_compile_features(perf.out PRIVATE cxx_std_17)

target_compile_options(main.out PRIVATE -Wall -O3)
target_compile_options(tests.out PRIVATE -Wall -O3)
target_compile_options(perf.out PRIVATE -Wall -O3 -ggdb)

# specify what to install when we run 'make install'
install(TARGETS main.out DESTINATION bin) 
