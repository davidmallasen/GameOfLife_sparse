#include <vector>
#include "game_of_life.h"

int main() {
    GameOfLife gol;

    std::vector<CELL> initial_population = {CELL(2, 0), CELL(1, 0), CELL(0, 0), CELL(0, 1)};

    gol.set_population(initial_population);
    gol.print_population();
    gol.step();
    gol.print_population();

    return 0;
}
