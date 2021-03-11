#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

#include <unordered_map>
#include <boost/functional/hash.hpp>

using CELL = std::pair<int, int>;
using POPULATION = std::unordered_map<CELL, int, boost::hash<CELL>>;

// Main class of the Game of Life
class GameOfLife {
public:
    GameOfLife();

    // Executes a step
    void step();
    
    // Sets the population to the one given by argument. Each CELL represents
    // the (x, y) position of a cell.
    void set_population(std::vector<CELL> population);

    // Prints the current population
    void print_population();

private:
    POPULATION population_;
};

#endif // GAME_OF_LIFE_H_
