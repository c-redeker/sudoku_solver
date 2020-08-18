#ifndef SUDOKU_SOLVER_CHECKER_H
#define SUDOKU_SOLVER_CHECKER_H

#include <sudoku.hpp>

class SudokuChecker {
public:
    static bool IsSolvable(const Sudoku& sudoku);
    static bool IsSolvedCorrectly(const Sudoku& sudoku);
    static bool IsSolvedCompletely(const Sudoku& sudoku);

private:
    static void CountMaxOccurrence(const CellContainer* cell_container, int& number, int& count);
};

#endif//SUDOKU_SOLVER_CHECKER_H
