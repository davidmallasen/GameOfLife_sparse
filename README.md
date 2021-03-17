# Game of Life
Sparse efficient implementation of Conway's Game of Life.

First clone this repo by running:
~~~
git clone https://github.com/davidmallasen/GameOfLife_sparse.git
cd GameOfLife_sparse
~~~

## Dependencies

Install [Boost C++ Libraries](https://www.boost.org/). In Ubuntu 20.04 you can simply `sudo apt install libboost-dev`.

Install [GoogleTest](https://github.com/google/googletest). In Ubuntu 20.04 you can simply `sudo apt install libgtest-dev`.

Install [GPerftools](https://github.com/gperftools/gperftools) and [Google pprof](https://github.com/google/pprof). In Uuntu 20.04 you can simply `sudo apt install google-perftools libgoogle-perftools-dev`.

## Getting started 

To build the application and run an example execute:
~~~
mkdir build && cd build && cmake .. && make
./bin/main.out
~~~

The [default initial conditions](https://www.conwaylife.com/wiki/Glider) can be adjusted by modifying the `initial_population` variable in `src/main.cpp`.

When running `main.out` you will also generate the VTK representation of each step. You can visualize this data for example using Paraview.
To create an animation from the .png files that can be generated using Paraview run `convert -delay 10 -loop 0 *.png animation.gif`.

## Tests

To run the tests execute `./bin/tests.out` in the `build` directory. The four unit tests check the following:
- SimpleDie: Checks that cells with less than 3 neighbors should die.
- SimpleLive: Checks that positions with 3 neighbors should create a new cell. 
- SimpleExample: Checks a simple example that covers all the rules over one step.
- IterativeGlider: Executes a small [glider](https://www.conwaylife.com/wiki/Glider) over 3 time steps.

## Performance analysis

To activate the VTK visualization of the performance test declare `#define VTK 1` in `src/perf_test.cpp` (not recommended when actually analyzing the performance).

### Execution time

To measure the execution time of the performance test, declare `#define TIMING 1` in `src/perf_test.cpp`.

Then, run:
~~~
./bin/perf.out
~~~

### Hotspot profiling

To create a profile and visualize the hotspots run the following in the `build` directory (remember to set the defines back to 0 to avoid their overhead):
~~~
env CPUPROFILE=line20000.prof CPUPROFILE_FREQUENCY=1000 ./bin/perf.out
google-pprof --text ./bin/perf.out line20000.prof
~~~
If you want to sort by cumulative time instead of the flat value, add the `-cum` option to the `google-pprof` command.

### Detecting memory leaks

To check that there are no memory leaks change the number of steps in `src/perf_test.cpp` to something smaller like 200, recompile and run `HEAPCHECK=normal ./bin/perf.out`.

### Analyzing cache usage

First you will need to install the Linux perf tools (`sudo apt install linux-tools-$(uname -r) linux-tools-generic`). You will also have to either run the commands with superuser mode (`sudo`) or enable counter values collection without root permission: `sudo sh -c 'echo 1 >/proc/sys/kernel/perf_event_paranoid'`.

To obtain stats on the instructions and the caches run:
~~~
perf stat -e cycles,instructions,cache-references,cache-misses,L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores -B ./bin/perf.out
~~~

The list of all pre-defined events to be used with -e can be seen with `perf list`.

*Note:* Linux perf tools may not give all values if used in a virtual machine.
