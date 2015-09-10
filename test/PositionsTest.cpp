#include "gtest/gtest.h"
#include "Positions.h"

TEST(PositionsTest, should_empty_given_a_init_positions)
{
    ASSERT_TRUE(Positions().isEmpty());
}

TEST(PositionsTest, should_init_positions_given_position_lists)
{
    Positions one = {a1, b2};
    Positions another{c3, d4};
}

TEST(PositionsTest, should_equals_given_a_same_position_list_which_the_order_is_not_sensitive)
{
    Positions one {a1, b2, c3};
    Positions another {b2, c3, a1};
    
    ASSERT_EQ(one, another);
    ASSERT_FALSE(one.isEmpty());
}

TEST(PositionsTest, should_not_equals_given_different_position_list)
{
    Positions one {a1, b2};
    Positions another {a1};
    Positions third {b2, a2};
    
    ASSERT_NE(one, another);
    ASSERT_NE(one, third);
    ASSERT_NE(another, third);
}

TEST(PositionsTest, should_push_position_to_positions)
{
    Positions EXPECT {a1, b2};

    Positions positions;
    ASSERT_NE(EXPECT, positions);

    positions.push(a1);
    positions.push(b2);

    ASSERT_EQ(EXPECT, positions);
}

TEST(PositionsTest, should_clear_the_positions_given_not_empty_positions)
{
    Positions GIVEN {a1, b2};
    ASSERT_FALSE(GIVEN.isEmpty());

    GIVEN.clear();

    ASSERT_TRUE(GIVEN.isEmpty());
}

TEST(PositionsTest, should_get_position_given_a_not_empty_positions)
{
    Positions GIVEN {a1, b2, c3};

    ASSERT_EQ(a1, GIVEN.at(0));
    ASSERT_EQ(b2, GIVEN.at(1));
}

TEST(PositionsTest, should_get_size_given_a_not_empty_positions)
{
    Positions GIVEN {a1, b2};

    ASSERT_EQ(2, GIVEN.size());
}


