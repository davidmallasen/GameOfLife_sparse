# Game of Life
Sparse efficient implementation of Conway's Game of Life.

First clone this repo by running:
~~~
git clone https://github.com/davidmallasen/GameOfLife_sparse.git
cd GameOfLife_sparse
~~~

Install [Boost C++ Libraries](https://www.boost.org/). In Ubuntu 20.04 you can simply `sudo apt get install libboost-dev`.

Install [GoogleTest](https://github.com/google/googletest). In Ubuntu 20.04 you can simply `sudo apt get install libgtest-dev`.

To build and run the tests and the example simply execute:
~~~
mkdir build && cd build && cmake .. && make
./bin/tests.out
./bin/main.out
~~~
