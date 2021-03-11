#include "game_of_life.h"

int main() {
    GameOfLife gol;

    population_t initial_population = {cell_t(2, 0), cell_t(1, 0), cell_t(0, 0), cell_t(0, 1)};

    gol.set_population(initial_population);
    gol.print_population();
    gol.step();
    gol.print_population();

    return 0;
}
