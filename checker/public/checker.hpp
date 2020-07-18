#ifndef SUDOKU_SOLVER_CHECKER_H
#define SUDOKU_SOLVER_CHECKER_H

#include <sudoku.hpp>

class SudokuChecker {
public:
    static bool CheckSudoku(Sudoku& sudoku);

private:
    static void CountMaxOccurrence(const CellContainer* cell_container, int& number, int& count);
};

#endif//SUDOKU_SOLVER_CHECKER_H
