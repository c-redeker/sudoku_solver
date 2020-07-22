#ifndef SUDOKU_SOLVER_SOLVER_NAKED_PAIRS_H
#define SUDOKU_SOLVER_SOLVER_NAKED_PAIRS_H

#include <ISolver.hpp>
#include <sudoku.hpp>

/*!
 * @brief This solver excludes possible numbers from some cells in case n other cells
 * from the same container have the same n possible numbers left.
 * In this case the n possible numbers are excluded from all cells which do not belong
 * to the set of n cells with the same n possible numbers left.
 */
class SolverNakedPairs : public ISolver {
public:
    void Solve(Sudoku &sudoku);

private:
    void FindNakedPair(const CellContainer *cell_container);
    bool CheckIfAllPossibleNumbersAreEqual(std::vector<Cell *> &cells_to_compare);
};

#endif//SUDOKU_SOLVER_SOLVER_NAKED_PAIRS_H
