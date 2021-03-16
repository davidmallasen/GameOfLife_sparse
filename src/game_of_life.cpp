#include <game_of_life.h>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <unordered_map>

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

void GameOfLife::write_vtk(std::string file_name, int width, int height, cell_t bottom_left) {
    std::ofstream vtk_file;

    vtk_file.open(file_name);

    if (vtk_file.is_open()) {
        std::cout << "Success opening " << file_name << std::endl;

        vtk_file << "# vtk DataFile Version 2.0" << std::endl;
        vtk_file << "Game of Life - Population" << std::endl;
        vtk_file << "BINARY" << std::endl;
        vtk_file << "DATASET STRUCTURED_POINTS" << std::endl;
        vtk_file << "DIMENSIONS " << width << " " << height << " 1" << std::endl;
        vtk_file << "ORIGIN " << bottom_left.first << " " << bottom_left.second << " 0" << std::endl;
        vtk_file << "SPACING 1 1 1" << std::endl;
        vtk_file << "POINT_DATA " << width * height << std::endl;
        vtk_file << "SCALARS cell unsigned_char" << std::endl;
        vtk_file << "LOOKUP_TABLE default" << std::endl;

        for (int j = bottom_left.second; j < bottom_left.second + height; ++j) {
            for (int i = bottom_left.first; i < bottom_left.first + width; ++i) {
                char live = (char) population_.count(cell_t(i, j));
                vtk_file.write((char*) &live, 1);
            }
        }
        
        vtk_file.close();
    } 
    else {
        std::cout << "Error opening " << file_name << std::endl;
    }
}
