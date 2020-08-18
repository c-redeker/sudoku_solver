#ifndef SUDOKU_SOLVER_INTERFACE_H
#define SUDOKU_SOLVER_INTERFACE_H

#include <sudoku.hpp>

class ISolver {
public:
    virtual void Solve(Sudoku &sudoku) = 0;
    virtual ~ISolver() = default;
};

#endif// SUDOKU_SOLVER_INTERFACE_H
