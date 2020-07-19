#include <checker.hpp>

#include <iostream>

bool SudokuChecker::IsSolvable(Sudoku &sudoku) {
    int number{0};
    int count{1};

    for (int index{0}; index < 9; ++index) {
        const auto row = sudoku.GetRow(index);
        CountMaxOccurrence(row, number, count);
        if (count > 1) break;

        const auto column = sudoku.GetColumn(index);
        CountMaxOccurrence(column, number, count);
        if (count > 1) break;

        const auto rectangle = sudoku.GetRectangle(index);
        CountMaxOccurrence(rectangle, number, count);
        if (count > 1) break;
    }

    if (count > 1 && number > 0) {
        std::cout << "Sudoku cannot be solved! Number " << number << " found multiple times \n";
        return false;
    }
    std::cout << "Sudoku can be solved \n";
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