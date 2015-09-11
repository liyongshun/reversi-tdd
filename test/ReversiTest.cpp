#include "gtest/gtest.h"
#include "Reversi.h"

struct ReversiTest : testing::Test
{
protected:
    Reversi reversi;
    
};

TEST_F(ReversiTest, should_get_a_board_from_reversi_equals_a_init_board)
{
    const Board EXPECT_INIT_BOARD;

    ASSERT_EQ(EXPECT_INIT_BOARD, Reversi().getBoard());
}

TEST_F(ReversiTest, should_get_available_positions_given_a_valid_position_in_the_board)
{
    const Positions EXPECT_POSITIONS_OF_e4 = {c4, e6};
    ASSERT_EQ(EXPECT_POSITIONS_OF_e4, Reversi().gitAvailablePositions(e4));

    const Positions EXPECT_POSITIONS_OF_d5 = {d3, f5};
    ASSERT_EQ(EXPECT_POSITIONS_OF_d5, Reversi().gitAvailablePositions(d5));
}

struct ReversiWithSpecificSetTest : ReversiTest
{
    ReversiWithSpecificSetTest()
    {
        buildSet();
        reversi.refresh(set);
    }

    void buildSet()
    {
        set.place(Positions{d4, e4, d5, e5}, EMPTY);
        set.place(Positions{a1, c3, e3, f4, e8}, BLACK);
        set.place(Positions{a2, d4, e4, e5, f5, b8, c8, d8}, WHITE);
    }

    // void ASSERT_BOARD(const Position move, const Positions& positionChanged)
    // {
    //     Board EXPECT_SET(set);
    //     EXPECT_SET.place(positionChanged, BLACK);
    //     ASSERT_EQ(EXPECT_SET, reversi.capture(move));
    //     EXPECT_SET.print();
    // }

protected:
    Board set;
};

namespace
{
    const Positions EXPECT_POSITIONS_ALL_BLACKS = {a3, f6, c5, e6, c4, d6, a8};
}

TEST_F(ReversiWithSpecificSetTest, should_get_all_available_positions_given_a_disk_with_a_specific_set)
{
    ASSERT_EQ(EXPECT_POSITIONS_ALL_BLACKS, reversi.getAllAvailablePositions(BLACK));
}

// TEST(ReversiWithSpecificSetTest, should_turn_over_the_captured_disk_given_a_available_position)
// {
//     ASSERT_BOARD(a3, Positions{a2, a3});
//     ASSERT_BOARD(f6, Positions{d4, e5, f5, f6});
//     ASSERT_BOARD(e6, Positions{e4, e5, e6});
//     ASSERT_BOARD(c5, Positions{d4, c5});
//     ASSERT_BOARD(c4, Positions{c4, d4, e4});
//     ASSERT_BOARD(d6, Positions{d6, e5});
//     ASSERT_BOARD(a8, Positions{a8, b8, c8, d8});
// }
