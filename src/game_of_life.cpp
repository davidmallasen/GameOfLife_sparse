#include <game_of_life.h>
#include <cstdio>

GameOfLife::GameOfLife() {
    //
}

void GameOfLife::step() {
    population_t prev_population;
    std::unordered_map<cell_t, int, boost::hash<cell_t>> density;

    prev_population.swap(population_);

    // Compute density around each of the cells of the population 
    for (const auto& cell : prev_population) {
        int x = cell.first;
        int y = cell.second;
        
        // Iterate over the neighbors
        for (int i : {-1, 0, 1}) {
            for (int j : {-1, 0, 1}) {
                // Try to insert the new point
                auto ret = density.emplace(cell_t(x + i, y + j), 1);
                // If it already existed, add to its count
                if (!ret.second) {
                    ret.first->second++;
                }
            }
        }
    }

    // Create the new populatin
    for (const auto& [cell, cnt] : density) {
        if (cnt == 3 || (cnt == 4 && prev_population.contains(cell))) {
            population_.emplace(cell);
        }
    }
}

void GameOfLife::set_population(const population_t &population) {
    population_ = population;
}

population_t GameOfLife::get_population() {
    return population_;
}

void GameOfLife::print_population() {
    for (const auto& cell : population_) {
        printf("(%d, %d),", cell.first, cell.second);
    }
    printf("\n");
}

