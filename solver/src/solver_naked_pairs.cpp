#include <free_functions_solver.hpp>
#include <solver_naked_pairs.h>

void SolverNakedPairs::Solve(Sudoku &sudoku) {
    auto all_cell_container = sudoku.GetAllCellContainers();
    for (auto container : all_cell_container) { FindNakedPair(container); }
    WriteOnlyPossibleNumberIntoEachCell(sudoku);
}

void SolverNakedPairs::FindNakedPair(const CellContainer *cell_container) {
    const auto filled_numbers = cell_container->GetFilledNumbers();
    for (int count_numbers_left{2}; count_numbers_left < 6; ++count_numbers_left) {
        auto cells_equal_count_of_possible_numbers =
                cell_container->GetCellsWithEqualCountOfPossibleNumbers(count_numbers_left);
        auto are_possible_numbers_equal = CheckIfAllPossibleNumbersAreEqual(cells_equal_count_of_possible_numbers);
        if (are_possible_numbers_equal) {
            const auto numbers_to_remove = cells_equal_count_of_possible_numbers[0]->GetPossibleNumbers();
            for (auto cell : cell_container->GetEmptyCells()) {
                if (!(std::find(cells_equal_count_of_possible_numbers.begin(),
                                cells_equal_count_of_possible_numbers.end(),
                                cell) != cells_equal_count_of_possible_numbers.end())) {
                    if (cell->ArePossibleNumbersCorrect(filled_numbers)) {
                        cell->RemoveNumbersFromPossibleNumbers(numbers_to_remove);
                    }
                }
            }
        }
    }
};

bool SolverNakedPairs::CheckIfAllPossibleNumbersAreEqual(std::vector<Cell *> &cells_to_compare) {
    if (cells_to_compare.size() <= 1) { return false; }
    if (cells_to_compare.size() != cells_to_compare[0]->GetPossibleNumbers().size()) { return false; }

    for (const auto cell1 : cells_to_compare) {
        for (const auto cell2 : cells_to_compare) {
            if (cell1->GetPossibleNumbers() != cell2->GetPossibleNumbers()) { return false; }
        }
    }
    return true;
};
