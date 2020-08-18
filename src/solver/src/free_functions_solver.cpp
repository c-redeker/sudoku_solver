#include <free_functions_solver.hpp>

void WriteOnlyPossibleNumberIntoEachCell(Sudoku &sudoku) {
    for (auto empty_cell : sudoku.GetEmptyCells()) {
        auto possible_numbers_for_cell = empty_cell->GetPossibleNumbers();
        if (possible_numbers_for_cell.size() == 1) { empty_cell->SetNumber(possible_numbers_for_cell[0]); }
    }
};