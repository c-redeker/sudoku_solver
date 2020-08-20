#ifndef SUDOKU_SOLVER_SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_SUDOKU_SOLVER_HPP

#include <ISolver.hpp>

class SudokuSolver {
public:
    SudokuSolver();
    void Solve(Sudoku &sudoku) const;
    void DoOneSolvingStep(Sudoku &sudoku) const;

private:
    std::vector<std::unique_ptr<ISolver>> m_solver_list{};
};

#endif//SUDOKU_SOLVER_SUDOKU_SOLVER_HPP
