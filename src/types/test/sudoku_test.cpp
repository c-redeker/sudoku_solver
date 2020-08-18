#include <gtest/gtest.h>

#include <sudoku.hpp>

class SudokuFixture : public ::testing::Test {
protected:
};

TEST(Sudoku, construct_sudoku) {
    std::array<std::size_t, 81> numbers{0};
    EXPECT_NO_THROW(Sudoku sudoku(numbers));
}

TEST(Sudoku, construct_check_row) {
    std::array<std::size_t, 81> numbers{0};
    Sudoku sudoku(numbers);
    const auto row = sudoku.GetRow(5);
    EXPECT_EQ(5, row->GetIndex());
}

TEST(Sudoku, construct_check_column) {
    std::array<std::size_t, 81> numbers{0};
    Sudoku sudoku(numbers);
    const auto column = sudoku.GetColumn(8);
    EXPECT_EQ(8, column->GetIndex());
}

TEST(Sudoku, construct_check_rectangle) {
    std::array<std::size_t, 81> numbers{0};
    Sudoku sudoku(numbers);
    const auto rectangle = sudoku.GetRectangle(7);
    EXPECT_EQ(7, rectangle->GetIndex());
}

TEST(Sudoku, get_empty_cells) {
    std::array<std::size_t, 81> numbers{0};
    Sudoku sudoku(numbers);
    auto empty_cells = sudoku.GetEmptyCells();
    ASSERT_EQ(81, empty_cells.size());
    for (auto cell : empty_cells) { ASSERT_TRUE(cell); }// not nullpointer
}

TEST(Sudoku, get_all_cell_containers) {
    std::array<std::size_t, 81> numbers{0};
    Sudoku sudoku(numbers);
    auto cell_containers = sudoku.GetAllCellContainers();
    ASSERT_EQ(27, cell_containers.size());
    for (const auto container : cell_containers) { ASSERT_TRUE(container); }// not nullpointer
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}