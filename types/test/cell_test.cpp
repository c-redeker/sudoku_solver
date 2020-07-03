#include <gtest/gtest.h>

#include <cell.hpp>

class CellFixture : public::testing::Test {
protected:
    Cell m_empty_cell{0, 5, 6};
    Cell m_filled_cell{3, 7, 8};
};

TEST(Cell, construct_empty_cell) {
    std::size_t number{0};
    std::size_t row_index{7};
    std::size_t column_index{8};
    Cell cell(number, row_index, column_index);
    EXPECT_EQ(number, cell.GetNumber());
    EXPECT_EQ(row_index, cell.GetRowIndex());
    EXPECT_EQ(column_index, cell.GetColumnIndex());
    EXPECT_FALSE(cell.IsCellFilled());
}

TEST(Cell, construct_filled_cell) {
    std::size_t number{5};
    std::size_t row_index{3};
    std::size_t column_index{5};
    Cell cell(number, row_index, column_index);
    EXPECT_EQ(number, cell.GetNumber());
    EXPECT_EQ(row_index, cell.GetRowIndex());
    EXPECT_EQ(column_index, cell.GetColumnIndex());
    EXPECT_TRUE(cell.IsCellFilled());
}

TEST_F(CellFixture, set_number) {
    ASSERT_EQ(0, m_empty_cell.GetNumber());
    ASSERT_FALSE(m_empty_cell.IsCellFilled());

    m_empty_cell.SetNumber(5);
    EXPECT_EQ(5, m_empty_cell.GetNumber());
    EXPECT_TRUE(m_empty_cell.IsCellFilled());
}

// ---------- connected row/column index tests ------------------------------------------
class ConnectedRowsColsParamTests
    : public ::testing::TestWithParam<std::tuple<std::size_t, std::array<std::size_t, 2U>>> {
};

INSTANTIATE_TEST_SUITE_P(ConnectedRowIndices, ConnectedRowsColsParamTests,
                        ::testing::Values(std::make_tuple(0, std::array<std::size_t, 2U>{1, 2}),
                                          std::make_tuple(1, std::array<std::size_t, 2U>{0, 2}),
                                          std::make_tuple(2, std::array<std::size_t, 2U>{0, 1}),
                                          std::make_tuple(3, std::array<std::size_t, 2U>{4, 5}),
                                          std::make_tuple(4, std::array<std::size_t, 2U>{3, 5}),
                                          std::make_tuple(5, std::array<std::size_t, 2U>{3, 4}),
                                          std::make_tuple(6, std::array<std::size_t, 2U>{7, 8}),
                                          std::make_tuple(7, std::array<std::size_t, 2U>{6, 8}),
                                          std::make_tuple(8, std::array<std::size_t, 2U>{6, 7})));

TEST_P(ConnectedRowsColsParamTests, check_connected_row_indices) {
    std::size_t row_index = std::get<0>(GetParam());
    Cell cell(0, row_index, 0);
    std::array<std::size_t, 2U> expected_indices = std::get<1>(GetParam());
    ASSERT_EQ(expected_indices, cell.GetConnectedRowIndices());
}

TEST_P(ConnectedRowsColsParamTests, check_connected_column_indices) {
    std::size_t column_index = std::get<0>(GetParam());
    Cell cell(0, 0, column_index);
    std::array<std::size_t, 2U> expected_indices = std::get<1>(GetParam());
    ASSERT_EQ(expected_indices, cell.GetConnectedColumnIndices());
}

// ---------- connected rectangle index tests ------------------------------------------
class ConnectedRectangleParamTests
        : public ::testing::TestWithParam<std::tuple<std::array<std::size_t, 2U>, std::size_t>> {
};

INSTANTIATE_TEST_SUITE_P(ConnectedRectangleIndices, ConnectedRectangleParamTests,
                         ::testing::Values(std::make_tuple(std::array<std::size_t, 2U>{1, 2}, 0),
                                           std::make_tuple(std::array<std::size_t, 2U>{2, 5}, 1),
                                           std::make_tuple(std::array<std::size_t, 2U>{0, 6}, 2),
                                           std::make_tuple(std::array<std::size_t, 2U>{4, 2}, 3),
                                           std::make_tuple(std::array<std::size_t, 2U>{5, 5}, 4),
                                           std::make_tuple(std::array<std::size_t, 2U>{3, 6}, 5),
                                           std::make_tuple(std::array<std::size_t, 2U>{7, 2}, 6),
                                           std::make_tuple(std::array<std::size_t, 2U>{6, 3}, 7),
                                           std::make_tuple(std::array<std::size_t, 2U>{8, 7}, 8)));

TEST_P(ConnectedRectangleParamTests, check_connected_rectangle_indices) {
    std::array<std::size_t, 2U> indices = std::get<0>(GetParam());
    Cell cell(0, indices[0], indices[1]);
    std::size_t expected_rectangle_index = std::get<1>(GetParam());
    ASSERT_EQ(expected_rectangle_index, cell.GetRectangleIndex());
}


// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}