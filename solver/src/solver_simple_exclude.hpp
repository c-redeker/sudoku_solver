#ifndef SUDOKU_SOLVER_SOLVERSIMPLEEXCLUDE_H
#define SUDOKU_SOLVER_SOLVERSIMPLEEXCLUDE_H

#include <ISolver.hpp>
#include <sudoku.hpp>

class SolverSimpleExclude : public ISolver {
public:
    void Solve(Sudoku& sudoku) final;
};

#endif//SUDOKU_SOLVER_SOLVERSIMPLEEXCLUDE_H
