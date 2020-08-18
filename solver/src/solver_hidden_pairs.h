#ifndef SUDOKU_SOLVER_SOLVER_HIDDEN_PAIRS_H
#define SUDOKU_SOLVER_SOLVER_HIDDEN_PAIRS_H

#include <ISolver.hpp>
#include <subset_generator.hpp>
#include <sudoku.hpp>

/*!
 * @brief This solver checks if a subset of possible numbers (size n) is possible in n cells of a container.
 * No number of the subset is allowed to occur in any other cell of the container.
 * In that case all other numbers (which are not in the subset) are removed from the n cells.
 */
class SolverHiddenPairs : public ISolver {
public:
    void Solve(Sudoku &sudoku) final;

private:
    static void FindHiddenPair(const CellContainer *cell_container);
    static std::vector<Subset> FindAllUniqueSubsetsInContainer(const CellContainer *cell_container);
    static std::vector<Cell *> FindAllCellsWithSubset(const std::vector<Cell *> &empty_cells, const Subset &subset);
    static std::vector<Cell *> FindAllCellsWithAtLeastOneNumberFromSubset(const std::vector<Cell *> &empty_cells,
                                                                          const Subset &numbers);
    static void RemoveAllNumbersExceptSubsetFromCells(const std::vector<Cell *> &cells, const Subset &numbers);
    static const int kMaxSubsetSize{3};
};

#endif//SUDOKU_SOLVER_SOLVER_HIDDEN_PAIRS_H
