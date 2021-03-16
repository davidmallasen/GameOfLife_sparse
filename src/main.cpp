#include <cstdio>
#include <string>

#include "game_of_life.h"

int main() {
    GameOfLife gol;

    population_t initial_population = {
        cell_t(0, 1),
        cell_t(1, 0),
        cell_t(2, 0),
        cell_t(2, 1),
        cell_t(2, 2),
    };

    gol.set_population(initial_population);

    printf("Initial population:\n");
    gol.print_population();

    gol.write_vtk("gol_0.vtk");
    
    for (int i = 1; i <= 100; ++i) {
        gol.step();
        std::string file_name = "gol_" + std::to_string(i) + ".vtk";
        gol.write_vtk(file_name);
    }
    
    printf("Final population:\n");
    gol.print_population();

    return 0;
}
