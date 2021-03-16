#include "game_of_life.h"

#define TIMING 0
#define VTK 0

#if TIMING
#include <ctime>
#include <cstdlib>

double sec(struct timespec *ts) {
    return ts->tv_sec + 1e-9 * ts->tv_nsec;
}
#endif

#if VTK
#include <string>
#endif

int main() {
#if TIMING
    struct timespec t0, t1;
#endif
    GameOfLife gol;
    
    // Acorn -> https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Examples_of_patterns
    // Takes 5206 generations to generate 633 cells, including 13 escaped gliders
    /*
    population_t acorn = {
        cell_t(0, 0),
        cell_t(1, 0),
        cell_t(1, 2),
        cell_t(3, 1),
        cell_t(4, 0),
        cell_t(5, 0),
        cell_t(6, 0),
    };
    */

    // Inifinite growth line
    population_t line = {
        cell_t(0, 0),
        cell_t(1, 0),
        cell_t(2, 0),
        cell_t(3, 0),
        cell_t(4, 0),
        cell_t(5, 0),
        cell_t(6, 0),
        cell_t(7, 0),
        cell_t(9, 0),
        cell_t(10, 0),
        cell_t(11, 0),
        cell_t(12, 0),
        cell_t(13, 0),
        cell_t(17, 0),
        cell_t(18, 0),
        cell_t(19, 0),
        cell_t(26, 0),
        cell_t(27, 0),
        cell_t(28, 0),
        cell_t(29, 0),
        cell_t(30, 0),
        cell_t(31, 0),
        cell_t(32, 0),
        cell_t(34, 0),
        cell_t(35, 0),
        cell_t(36, 0),
        cell_t(37, 0),
        cell_t(38, 0),
    };

    gol.set_population(line);
#if VTK
    gol.write_vtk("gol_0.vtk", 500, 500, cell_t(-100, -250));
#endif

#if TIMING
    clock_gettime(CLOCK_MONOTONIC, &t0);
#endif

    for (int i = 1; i <= 20000; ++i) {
        gol.step();
#if VTK
        std::string file_name = "gol_" + std::to_string(i) + ".vtk";
        gol.write_vtk(file_name, 500, 500, cell_t(-100, -250));
#endif
    }

#if TIMING
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("Execution time: %f s\n", sec(&t1)-sec(&t0));
#endif

    return 0;
}
