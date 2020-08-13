#include <assert.h>

#include <solver_block_row_column_interaction.hpp>

void SolverBlockRowColumnInteraction::Solve(Sudoku &sudoku) {
    const auto all_rectangles = sudoku.GetAllRectangles();
    for (const auto rectangle : all_rectangles) {
        const auto rectangle_index = rectangle->GetIndex();
        const auto missing_numbers = rectangle->GetMissingNumbers();
        for (const auto missing_number : missing_numbers) {
            const auto column = FindColumnWithUniqueOccurrenceOfMissingNumber(sudoku, rectangle, missing_number);
            RemovePossibleNumberFromOtherRectangles(column, rectangle_index, missing_number);
            const auto row = FindRowWithUniqueOccurrenceOfMissingNumber(sudoku, rectangle, missing_number);
            RemovePossibleNumberFromOtherRectangles(row, rectangle_index, missing_number);
        }
    }
}

CellContainer *SolverBlockRowColumnInteraction::FindColumnWithUniqueOccurrenceOfMissingNumber(
        const Sudoku &sudoku, const Rectangle *rectangle, std::size_t missing_number) {
    IndexOccurenceMap column_indices{};
    for (const auto empty_cell : rectangle->GetEmptyCells()) {
        if (empty_cell->IsNumberPossible(missing_number)) {
            column_indices.SetIndexOccurence(empty_cell->GetColumnIndex());
        }
    }
    const auto column_index = column_indices.GetSingleOccuredIndex();
    CellContainer *column{nullptr};
    if (column_index > -1) { column = sudoku.GetColumn(column_index); }
    return column;
}

CellContainer *SolverBlockRowColumnInteraction::FindRowWithUniqueOccurrenceOfMissingNumber(const Sudoku &sudoku,
                                                                                           const Rectangle *rectangle,
                                                                                           std::size_t missing_number) {
    IndexOccurenceMap row_indices{};
    for (const auto empty_cell : rectangle->GetEmptyCells()) {
        if (empty_cell->IsNumberPossible(missing_number)) { row_indices.SetIndexOccurence(empty_cell->GetRowIndex()); }
    }
    const auto row_index = row_indices.GetSingleOccuredIndex();
    CellContainer *row{nullptr};
    if (row_index > -1) { row = sudoku.GetRow(row_index); }
    return row;
}

void SolverBlockRowColumnInteraction::RemovePossibleNumberFromOtherRectangles(const CellContainer *cell_container,
                                                                              std::size_t rectangle_index,
                                                                              std::size_t number) {
    if (cell_container) {
        for (auto cell : cell_container->GetEmptyCells()) {
            if (cell->GetRectangleIndex() != rectangle_index) { cell->RemoveNumbersFromPossibleNumbers({number}); }
        }
    }
}