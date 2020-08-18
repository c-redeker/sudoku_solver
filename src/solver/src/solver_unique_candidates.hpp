#ifndef SUDOKU_SOLVER_SOLVER_UNIQUE_CANDIDATES_HPP
#define SUDOKU_SOLVER_SOLVER_UNIQUE_CANDIDATES_HPP

#include <ISolver.hpp>
#include <sudoku.hpp>

/*!
 *  @brief This class is a solver which puts a number into the sudoku
 *  if a number has only 1 possible position in a cell container
 */
class SolverUniqueCandidates : public ISolver {
    void Solve(Sudoku &sudoku) final;
};

#endif//SUDOKU_SOLVER_SOLVER_UNIQUE_CANDIDATES_HPP
