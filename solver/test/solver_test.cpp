#include <gtest/gtest.h>

#include <solver_block_row_column_interaction.hpp>
#include <solver_hidden_pairs.h>
#include <solver_simple_exclude.hpp>
#include <solver_x_wing.hpp>

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

TEST_F(SolverFixture, SolverHiddenPair_work_on_first_row) {
    auto sudoku = CreateEmptySudoku();
    std::vector<std::size_t> numbers{1, 3, 5};
    for (uint8_t column_index{3}; column_index < 9; ++column_index) {
        sudoku.GetCell(0, column_index)->RemoveNumbersFromPossibleNumbers(numbers);
    }

    SolverHiddenPairs solver_hidden_pairs{};
    solver_hidden_pairs.Solve(sudoku);

    for (uint8_t column_index{0}; column_index < 3; ++column_index) {
        ASSERT_EQ(numbers, sudoku.GetCell(0, column_index)->GetPossibleNumbers());
    }
}

TEST_F(SolverFixture, SolverHiddenPair_work_on_first_column) {
    auto sudoku = CreateEmptySudoku();
    std::vector<std::size_t> numbers{1, 3, 5};
    sudoku.GetCell(0, 0)->RemoveNumbersFromPossibleNumbers({4, 5, 6, 7, 8, 9});
    sudoku.GetCell(1, 0)->RemoveNumbersFromPossibleNumbers({4, 5, 6, 7, 8, 9});
    sudoku.GetCell(2, 0)->RemoveNumbersFromPossibleNumbers({1, 2, 4, 5, 6, 7, 8, 9});
    sudoku.GetCell(3, 0)->RemoveNumbersFromPossibleNumbers({1, 2, 5, 6, 7, 8, 9});
    sudoku.GetCell(4, 0)->SetNumber(5);
    sudoku.GetCell(5, 0)->SetNumber(6);
    sudoku.GetCell(6, 0)->SetNumber(7);
    sudoku.GetCell(7, 0)->SetNumber(8);
    sudoku.GetCell(8, 0)->SetNumber(9);

    SolverHiddenPairs solver_hidden_pairs{};
    solver_hidden_pairs.Solve(sudoku);

    std::vector<std::size_t> expected_numbers_1_2{1, 2};
    ASSERT_EQ(expected_numbers_1_2, sudoku.GetCell(0, 0)->GetPossibleNumbers());
    ASSERT_EQ(expected_numbers_1_2, sudoku.GetCell(1, 0)->GetPossibleNumbers());

    std::vector<std::size_t> expected_numbers_3{3};
    ASSERT_EQ(expected_numbers_3, sudoku.GetCell(2, 0)->GetPossibleNumbers());

    std::vector<std::size_t> expected_number_3_4{3, 4};
    ASSERT_EQ(expected_number_3_4, sudoku.GetCell(3, 0)->GetPossibleNumbers());
}

TEST_F(SolverFixture, SolverHiddenPair_work_on_second_rectangle) {
    // testcase from http://www.sudoku-space.de/sudoku-loesungstechniken/
    auto sudoku = CreateEmptySudoku();
    sudoku.GetCell(0, 3)->SetNumber(6U);
    sudoku.GetCell(1, 3)->SetNumber(3U);
    sudoku.GetCell(1, 4)->SetNumber(4U);
    sudoku.GetCell(2, 5)->SetNumber(9U);
    sudoku.GetCell(0, 4)->RemoveNumbersFromPossibleNumbers({2, 4, 5, 6, 9});
    sudoku.GetCell(0, 5)->RemoveNumbersFromPossibleNumbers({3, 4, 6, 7, 9});
    sudoku.GetCell(1, 5)->RemoveNumbersFromPossibleNumbers({2, 3, 4, 5, 6, 7, 9});
    sudoku.GetCell(2, 3)->RemoveNumbersFromPossibleNumbers({1, 3, 4, 6, 9});
    sudoku.GetCell(2, 4)->RemoveNumbersFromPossibleNumbers({1, 2, 3, 4, 5, 6, 9});

    SolverHiddenPairs solver_hidden_pairs{};
    solver_hidden_pairs.Solve(sudoku);

    std::vector<std::size_t> expected_numbers_2_5{2, 5};
    ASSERT_EQ(expected_numbers_2_5, sudoku.GetCell(0, 5)->GetPossibleNumbers());
    ASSERT_EQ(expected_numbers_2_5, sudoku.GetCell(2, 3)->GetPossibleNumbers());

    std::vector<std::size_t> expected_numbers_1_3_7_8{1, 3, 7, 8};
    ASSERT_EQ(expected_numbers_1_3_7_8, sudoku.GetCell(0, 4)->GetPossibleNumbers());

    std::vector<std::size_t> expected_numbers_1_8{1, 8};
    ASSERT_EQ(expected_numbers_1_8, sudoku.GetCell(1, 5)->GetPossibleNumbers());

    std::vector<std::size_t> expected_numbers_7_8{7, 8};
    ASSERT_EQ(expected_numbers_7_8, sudoku.GetCell(2, 4)->GetPossibleNumbers());
}

TEST_F(SolverFixture, SolverXwing_test1) {
    // testcase from http://www.ahr-sudoku.de/solving.php/technic/X-Wing
    auto sudoku = CreateEmptySudoku();
    std::vector<std::size_t> column_indices{0, 8};
    for (const auto column_index : column_indices) {
        for (std::size_t row_index{1}; row_index < 8; ++row_index) {
            sudoku.GetCell(row_index, column_index)->RemoveNumbersFromPossibleNumbers({1});
        }
    }

    SolverXwing solver_x_wing{};
    solver_x_wing.Solve(sudoku);

    std::vector<std::size_t> remaining_numbers{2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::size_t> row_indices{0, 8};
    for (const auto row_index : row_indices) {
        for (std::size_t column_index{1}; column_index < 8; ++column_index) {
            ASSERT_EQ(remaining_numbers, sudoku.GetCell(row_index, column_index)->GetPossibleNumbers());
        }
    }
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}