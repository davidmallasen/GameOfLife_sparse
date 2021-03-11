#include <unordered_set>

#include <gtest/gtest.h>

#include "game_of_life.h"

TEST(GameOfLifeTest, SimpleDie) {
    GameOfLife gol;

    population_t initial_population = {
        cell_t(0, 0),
        cell_t(1, 0),
    };
    gol.set_population(initial_population);

    gol.step();

    population_t final_population = gol.get_population();

    population_t expected_population = {};

    ASSERT_EQ(final_population, expected_population);
}

TEST(GameOfLifeTest, SimpleLive) {
    GameOfLife gol;

    population_t initial_population = {
        cell_t(0, 0),
        cell_t(2, 0),
        cell_t(1, 2),
    };
    gol.set_population(initial_population);

    gol.step();

    population_t final_population = gol.get_population();

    population_t expected_population = {
        cell_t(1, 1),
    };

    ASSERT_EQ(final_population, expected_population);
}

TEST(GameOfLifeTest, SimpleExample) {
    GameOfLife gol;

    population_t initial_population = {
        cell_t(2, 0),
        cell_t(1, 0),
        cell_t(0, 0),
        cell_t(0, 1),
    };
    gol.set_population(initial_population);

    gol.step();

    population_t final_population = gol.get_population();

    population_t expected_population = {
        cell_t(0, 0),
        cell_t(0, 1),
        cell_t(1, 0),
        cell_t(1, -1),
    };

    ASSERT_EQ(final_population, expected_population);
}

TEST(GameOfLifeTest, IterativeGlider) {
    GameOfLife gol;

    population_t initial_population = {
        cell_t(0, 1),
        cell_t(1, 0),
        cell_t(2, 0),
        cell_t(2, 1),
        cell_t(2, 2),
    };
    gol.set_population(initial_population);

    gol.step();
    gol.step();
    gol.step();

    population_t final_population = gol.get_population();

    population_t expected_population = {
        cell_t(1, 1),
        cell_t(2, 0),
        cell_t(3, 0),
        cell_t(3, 1),
        cell_t(2, -1),
    };

    ASSERT_EQ(final_population, expected_population);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
