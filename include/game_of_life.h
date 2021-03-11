#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

#include <unordered_map>
#include <unordered_set>
#include <utility>

#include <boost/functional/hash.hpp>

using cell_t = std::pair<int, int>;
using population_t = std::unordered_set<cell_t, boost::hash<cell_t>>;

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

private:
    population_t population_;
};

#endif // GAME_OF_LIFE_H_
