#include <sudoku_solver.hpp>

#include <solver_block_row_column_interaction.hpp>
#include <solver_hidden_pairs.h>
#include <solver_naked_pairs.h>
#include <solver_simple_exclude.hpp>
#include <solver_unique_candidates.hpp>
#include <solver_x_wing.hpp>

SudokuSolver::SudokuSolver() {
    m_solver_list.reserve(6);
    m_solver_list.push_back(std::make_unique<SolverSimpleExclude>());
    m_solver_list.push_back(std::make_unique<SolverBlockRowColumnInteraction>());
    m_solver_list.push_back(std::make_unique<SolverNakedPairs>());
    m_solver_list.push_back(std::make_unique<SolverHiddenPairs>());
    m_solver_list.push_back(std::make_unique<SolverXwing>());
    // add more solver
    m_solver_list.push_back(std::make_unique<SolverUniqueCandidates>());
}

void SudokuSolver::Solve(Sudoku &sudoku) {
    std::size_t count_empty_cells_previous{82U};
    auto count_empty_cells = sudoku.GetCountOfEmptyCells();

    std::size_t solving_step{1};
    while (count_empty_cells < count_empty_cells_previous && count_empty_cells > 0) {
        for (const auto &solver : m_solver_list) { solver->Solve(sudoku); }

        count_empty_cells_previous = count_empty_cells;
        count_empty_cells = sudoku.GetCountOfEmptyCells();
        solving_step++;
    }
}