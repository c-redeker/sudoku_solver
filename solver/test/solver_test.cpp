#include <gtest/gtest.h>

#include <solver_block_row_column_interaction.hpp>
#include <solver_simple_exclude.hpp>

class SolverFixture : public ::testing::Test {
protected:
    Sudoku CreateEmptySudoku() {
        std::array<std::size_t, 81> numbers = {0U};
        Sudoku empty_sudoku(numbers);
        return empty_sudoku;
    }
};

TEST_F(SolverFixture, SolverBlockRowColumnInteraction_works_on_column) {
    auto sudoku = CreateEmptySudoku();
    sudoku.GetCell(0, 3)->SetNumber(1U);
    sudoku.GetCell(0, 5)->SetNumber(2U);
    sudoku.GetCell(2, 3)->SetNumber(3U);
    sudoku.GetCell(2, 5)->SetNumber(4U);
    sudoku.GetCell(1, 1)->SetNumber(5U);

    SolverSimpleExclude solver_simple_exclude{};
    solver_simple_exclude.Solve(sudoku);
    SolverBlockRowColumnInteraction solver_block_row_column_interaction{};
    solver_block_row_column_interaction.Solve(sudoku);

    const auto column = sudoku.GetColumn(4U);
    for (const auto cell : column->GetAllCells()) {
        const auto row_index = cell->GetRowIndex();
        if (row_index == 0 || row_index == 2) {
            ASSERT_TRUE(cell->IsNumberPossible(5));
        } else {
            ASSERT_FALSE(cell->IsNumberPossible(5));
        }
    }
}

TEST_F(SolverFixture, SolverBlockRowColumnInteraction_works_on_row) {
    auto sudoku = CreateEmptySudoku();
    sudoku.GetCell(3, 0)->SetNumber(1U);
    sudoku.GetCell(5, 0)->SetNumber(2U);
    sudoku.GetCell(3, 2)->SetNumber(3U);
    sudoku.GetCell(5, 2)->SetNumber(4U);
    sudoku.GetCell(1, 1)->SetNumber(5U);

    SolverSimpleExclude solver_simple_exclude{};
    solver_simple_exclude.Solve(sudoku);
    SolverBlockRowColumnInteraction solver_block_row_column_interaction{};
    solver_block_row_column_interaction.Solve(sudoku);

    const auto row = sudoku.GetRow(4U);
    for (const auto cell : row->GetAllCells()) {
        const auto column_index = cell->GetColumnIndex();
        if (column_index == 0 || column_index == 2) {
            ASSERT_TRUE(cell->IsNumberPossible(5));
        } else {
            ASSERT_FALSE(cell->IsNumberPossible(5));
        }
    }
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}