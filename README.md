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

When running `main.out` you will also generate the VTK representation of each step. You can visualize this data for example using Paraview.
To create an animation from the .png files that can be generated using Paraview run `convert -delay 10 -loop 0 *.png animation.gif`.
