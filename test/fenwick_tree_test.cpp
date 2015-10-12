#include "fenwick_tree.hpp"

#include <gmock/gmock.h>

TEST(FenwickTreeTest, Kattis1)
{
    fenwick_tree<int> ft(10);

    ft.add(7, 23);
    EXPECT_EQ(23, ft.sum(8));

    ft.add(3, 17);
    EXPECT_EQ(40, ft.sum(8));
}

TEST(FenwickTreeTest, Kattis2)
{
    fenwick_tree<int> ft(5);

    ft.add(0, -43);
    ft.add(4, 1);

    EXPECT_EQ(0, ft.sum(0));
    EXPECT_EQ(-42, ft.sum(5));
}

TEST(FenwickTreeTest, InitializedEmpty)
{
    fenwick_tree<int> ft(100);

    for (auto i = 0; i <= 100; i++) {
        EXPECT_EQ(0, ft.sum(i));
    }
}

TEST(FenwickTreeTest, DoublePrecisionSum)
{
    fenwick_tree<double> ft(20);

    ft.add(10, 3.14);
    ft.add(12, -3.0);
    ft.add(1, 20.0);

    EXPECT_DOUBLE_EQ(20.0, ft.sum(2));
    EXPECT_DOUBLE_EQ(23.14, ft.sum(11));
    EXPECT_DOUBLE_EQ(23.14, ft.sum(12));
    EXPECT_DOUBLE_EQ(20.14, ft.sum(13));
    EXPECT_DOUBLE_EQ(20.14, ft.sum(14));
}

TEST(FenwickTreeTest, RandomIntInput)
{
    fenwick_tree<int> ft(100);

    ft.add(3, 20);
    ft.add(4, 20);

    for (auto i = 0; i < 4; i++) {
        EXPECT_EQ(0, ft.sum(i));
    }

    EXPECT_EQ(20, ft.sum(4));
    EXPECT_EQ(40, ft.sum(5));

    for (auto i = 6; i <= 100; i++) {
        EXPECT_EQ(40, ft.sum(i));
    }
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
