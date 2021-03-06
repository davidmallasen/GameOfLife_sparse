#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

#include <string>
#include <utility>

#include <boost/functional/hash.hpp>
#include <boost/unordered_set.hpp>

using cell_t = std::pair<int, int>;
using population_t = boost::unordered_set<cell_t>;

// Main class of the Game of Life
class GameOfLife {
public:
    GameOfLife();

    // Executes a step
    void step();
    
    // Sets the population to the one given by argument. Each CELL represents
    // the (x, y) position of a cell.
    void set_population(const population_t &population);

    // Returns a representation of the current population
    population_t get_population();

    // Prints the current population
    void print_population();
    
    // Writes the current population as VTK format to the file given by file_name
    // Width and height represent the area of the population and bottom_left represents
    // where the bottom left corner of the representation should be.
    // For example: width == height == 100, bottom_left = (-50, -50) would represent the 
    // square given by the corners (-50, -50) and (49, 49).
    void write_vtk(std::string file_name, int width, int height, cell_t bottom_left);

private:
    population_t population_;
};

#endif // GAME_OF_LIFE_H_
