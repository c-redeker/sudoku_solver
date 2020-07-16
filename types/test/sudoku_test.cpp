#include <gtest/gtest.h>

#include <sudoku.hpp>

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

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}