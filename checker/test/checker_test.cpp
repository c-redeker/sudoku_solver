#include <gtest/gtest.h>

#include <checker.hpp>

class CheckerFixture : public ::testing::Test {
protected:
    std::array<std::size_t, 81> m_numbers{0};
    Sudoku m_sudoku{m_numbers};
};

TEST_F(CheckerFixture, empty_sudoku__valid) {
    EXPECT_TRUE(SudokuChecker::IsSolvable(m_sudoku));
}

TEST_F(CheckerFixture, row_containing_different_numbers__valid) {
    m_sudoku.GetRow(3)->GetAllCells()[0]->SetNumber(5);
    m_sudoku.GetRow(4)->GetAllCells()[1]->SetNumber(7);
    EXPECT_TRUE(SudokuChecker::IsSolvable(m_sudoku));
}

TEST_F(CheckerFixture, row_column_containing_different_numbers__valid) {
    m_sudoku.GetColumn(7)->GetAllCells()[0]->SetNumber(5);
    m_sudoku.GetRow(1)->GetAllCells()[7]->SetNumber(7);
    EXPECT_TRUE(SudokuChecker::IsSolvable(m_sudoku));
}

TEST_F(CheckerFixture, row_containing_number_2_times__invalid) {
    m_sudoku.GetRow(0)->GetAllCells()[0]->SetNumber(5);
    m_sudoku.GetRow(0)->GetAllCells()[1]->SetNumber(5);
    EXPECT_FALSE(SudokuChecker::IsSolvable(m_sudoku));
}

TEST_F(CheckerFixture, rectangle_containing_number_2_times__invalid) {
    m_sudoku.GetRectangle(6)->GetAllCells()[0]->SetNumber(8);
    m_sudoku.GetRectangle(6)->GetAllCells()[1]->SetNumber(8);
    EXPECT_FALSE(SudokuChecker::IsSolvable(m_sudoku));
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}