#include <solver_simple_exclude.hpp>
#include <free_functions_solver.hpp>

void SolverSimpleExclude::Solve(Sudoku &sudoku) {
    auto empty_cells = sudoku.GetEmptyCells();
    for (auto empty_cell : empty_cells) {
        const auto row_index = empty_cell->GetRowIndex();
        const auto numbers_in_row = sudoku.GetRow(row_index)->GetFilledNumbers();
        empty_cell->RemoveNumbersFromPossibleNumbers(numbers_in_row);

        const auto column_index = empty_cell->GetColumnIndex();
        const auto numbers_in_column = sudoku.GetColumn(column_index)->GetFilledNumbers();
        empty_cell->RemoveNumbersFromPossibleNumbers(numbers_in_column);

        const auto rectangle_index = empty_cell->GetRectangleIndex();
        const auto numbers_in_rectangle = sudoku.GetRectangle(rectangle_index)->GetFilledNumbers();
        empty_cell->RemoveNumbersFromPossibleNumbers(numbers_in_rectangle);
    }
    WriteOnlyPossibleNumberIntoEachCell(sudoku);
}