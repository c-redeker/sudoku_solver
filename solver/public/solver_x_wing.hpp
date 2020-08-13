#ifndef SUDOKU_SOLVER_SOLVER_X_WING_H
#define SUDOKU_SOLVER_SOLVER_X_WING_H

#include <ISolver.hpp>
#include <sudoku.hpp>

class SolverXwing : public ISolver {
public:
    void Solve(Sudoku &sudoku) final;

private:
    void DoXwingOnColumns(const std::array<CellContainer *, 9> &columns,
                          const std::array<CellContainer *, 9> &rows) const;
    std::vector<Cell *> FindPairCellsWithPossibleNumber(const std::array<CellContainer *, 9> &columns,
                                                        std::size_t number) const;
    std::vector<std::size_t> FindDifferentRowIndices(const std::vector<Cell *> &cells) const;
    std::vector<std::size_t> FindDifferentColumnIndices(const std::vector<Cell *> &cells) const;
};

#endif//SUDOKU_SOLVER_SOLVER_X_WING_H
