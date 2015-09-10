#include "gtest/gtest.h"
#include "Grid.h"

TEST(GirdTest, should_not_occupied_in_init_state)
{
    Grid grid;
    ASSERT_FALSE(grid.isOccupied());
}

TEST(GirdTest, should_occupied_by_black_disk_when_place_black)
{
    Grid grid;
    grid.place(BLACK);
    ASSERT_TRUE(grid.isOccupied());
    ASSERT_TRUE(grid.isBlack());
}

TEST(GirdTest, should_occupied_by_white_disk_when_place_white)
{
    Grid grid;
    grid.place(WHITE);
    ASSERT_TRUE(grid.isOccupied());
    ASSERT_TRUE(grid.isWhite());
}

TEST(GirdTest, should_not_occupied_when_reset)
{
    Grid grid;
    grid.place(WHITE);
    grid.reset();
    ASSERT_FALSE(grid.isOccupied());
}

TEST(GirdTest, should_turn_over_when_grid_is_occupided)
{
    Grid grid;
    grid.turnOver();
    ASSERT_FALSE(grid.isOccupied());

    grid.place(WHITE);
    grid.turnOver();
    ASSERT_TRUE(grid.isBlack());
    grid.turnOver();
    ASSERT_TRUE(grid.isWhite());
}
