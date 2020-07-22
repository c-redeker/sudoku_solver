#include <gtest/gtest.h>

#include <rectangle.hpp>

class RectangleFixture : public ::testing::Test {
protected:
    std::array<Cell *, 9> m_cells{};

    void SetUp() override { CreateEmptyCells(); }

    void TearDown() override { DestructCells(); }

    void CreateEmptyCells() {
        std::size_t row_index{0};
        for (auto &cell : m_cells) {
            cell = new Cell(0, row_index, 0);
            ++row_index;
        }
    }

    void DestructCells() {
        for (auto &cell : m_cells) { delete (cell); }
    }
};

TEST_F(RectangleFixture, construct_rectangle_with_empty_cells) {
    Rectangle rectangle{m_cells, 0};
    EXPECT_EQ(9, rectangle.GetCountOfEmptyCells());
}

TEST_F(RectangleFixture, rectangle_filled_numbers) {
    Rectangle rectangle{m_cells, 3};
    std::vector<std::size_t> filled_numbers{};
    EXPECT_EQ(filled_numbers, rectangle.GetFilledNumbers());
}

TEST_F(RectangleFixture, rectangle_missing_numbers) {
    Rectangle rectangle{m_cells, 7};
    std::vector<std::size_t> missing_numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(missing_numbers, rectangle.GetMissingNumbers());
}

// ---------- connected row index tests ------------------------------------------
class RectConnectedRowsParamTests
    : public ::testing::TestWithParam<std::tuple<std::size_t, std::array<std::size_t, 3U>>> {};

INSTANTIATE_TEST_SUITE_P(RectConnectedRowIndices, RectConnectedRowsParamTests,
                         ::testing::Values(std::make_tuple(0, std::array<std::size_t, 3U>{0, 1, 2}),
                                           std::make_tuple(1, std::array<std::size_t, 3U>{0, 1, 2}),
                                           std::make_tuple(2, std::array<std::size_t, 3U>{0, 1, 2}),
                                           std::make_tuple(3, std::array<std::size_t, 3U>{3, 4, 5}),
                                           std::make_tuple(4, std::array<std::size_t, 3U>{3, 4, 5}),
                                           std::make_tuple(5, std::array<std::size_t, 3U>{3, 4, 5}),
                                           std::make_tuple(6, std::array<std::size_t, 3U>{6, 7, 8}),
                                           std::make_tuple(7, std::array<std::size_t, 3U>{6, 7, 8}),
                                           std::make_tuple(8, std::array<std::size_t, 3U>{6, 7, 8})));

TEST_P(RectConnectedRowsParamTests, check_connected_row_indices) {
    std::size_t rectangle_index = std::get<0>(GetParam());
    std::array<Cell *, 9> cells{};
    Rectangle rectangle{cells, rectangle_index};
    std::array<std::size_t, 3U> expected_row_indices = std::get<1>(GetParam());
    ASSERT_EQ(expected_row_indices, rectangle.GetRowIndices());
}

// ---------- connected column index tests ------------------------------------------
class RectConnectedColsParamTests
    : public ::testing::TestWithParam<std::tuple<std::size_t, std::array<std::size_t, 3U>>> {};

INSTANTIATE_TEST_SUITE_P(RectConnectedRowIndices, RectConnectedColsParamTests,
                         ::testing::Values(std::make_tuple(0, std::array<std::size_t, 3U>{0, 1, 2}),
                                           std::make_tuple(1, std::array<std::size_t, 3U>{3, 4, 5}),
                                           std::make_tuple(2, std::array<std::size_t, 3U>{6, 7, 8}),
                                           std::make_tuple(3, std::array<std::size_t, 3U>{0, 1, 2}),
                                           std::make_tuple(4, std::array<std::size_t, 3U>{3, 4, 5}),
                                           std::make_tuple(5, std::array<std::size_t, 3U>{6, 7, 8}),
                                           std::make_tuple(6, std::array<std::size_t, 3U>{0, 1, 2}),
                                           std::make_tuple(7, std::array<std::size_t, 3U>{3, 4, 5}),
                                           std::make_tuple(8, std::array<std::size_t, 3U>{6, 7, 8})));

TEST_P(RectConnectedColsParamTests, check_connected_column_indices) {
    std::size_t rectangle_index = std::get<0>(GetParam());
    std::array<Cell *, 9> cells{};
    Rectangle rectangle{cells, rectangle_index};
    std::array<std::size_t, 3U> expected_column_indices = std::get<1>(GetParam());
    ASSERT_EQ(expected_column_indices, rectangle.GetColumnIndices());
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}