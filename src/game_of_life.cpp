#include <game_of_life.h>
#include <cstdio>

GameOfLife::GameOfLife() {
    //
}

void GameOfLife::step() {
    POPULATION density, prev_population;

    prev_population.swap(population_);

    // Compute density around each of the cells of the population 
    for (const auto& [pt, cnt] : prev_population) {
        int x = pt.first;
        int y = pt.second;
        
        // Iterate over the neighbors
        for (int i : {-1, 0, 1}) {
            for (int j : {-1, 0, 1}) {
                // Try to insert the new point
                auto ret = density.emplace(CELL(x + i, y + j), 1);
                // If it already existed, add to its count
                if (!ret.second) {
                    ret.first->second++;
                }
            }
        }
    }

    // Create the new populatin
    for (const auto& [pt, cnt] : density) {
        if (cnt == 3 || (cnt == 4 && prev_population.contains(pt))) {
            population_.emplace(pt, 1);
        }
    }
}

void GameOfLife::set_population(std::vector<CELL> population) {
    population_.clear();
    for (CELL c : population) {
        population_.emplace(c, 1);
    }
}

void GameOfLife::print_population() {
    for (const auto& [pt, cnt] : population_) {
        printf("(%d, %d),", pt.first, pt.second);
    }
    printf("\n");
}

