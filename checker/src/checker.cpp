#include <checker.hpp>

#include <iostream>

bool SudokuChecker::IsSolvable(const Sudoku &sudoku) {
    int number{0};
    int count{0};

    const auto all_container = sudoku.GetAllCellContainers();
    for (const auto cell_container : all_container) {
        CountMaxOccurrence(cell_container, number, count);
        if (count > 1) { break; }
    }

    if (count > 1 && number > 0) {
        std::cout << "Sudoku cannot be solved! Number " << number << " found multiple times in a cell container \n";
        return false;
    }
    return true;
}

void SudokuChecker::CountMaxOccurrence(const CellContainer *cell_container, int &number, int &count) {
    int occurrence[10] = {0};
    for (const auto cell : cell_container->GetAllCells()) {
        if (cell->GetNumber() != 0) occurrence[cell->GetNumber()]++;
    }

    // find max occurrence
    for (int index{1}; index < 10; ++index) {
        if (occurrence[index] > count) {
            count = occurrence[index];
            number = index;
        }
    }
}

bool SudokuChecker::IsSolvedCorrectly(const Sudoku &sudoku) { return IsSolvable(sudoku) && IsSolvedCompletely(sudoku); }

bool SudokuChecker::IsSolvedCompletely(const Sudoku &sudoku) { return sudoku.GetCountOfEmptyCells() == 0; }