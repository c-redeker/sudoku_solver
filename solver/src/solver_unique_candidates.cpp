#include <solver_unique_candidates.hpp>

void SolverUniqueCandidates::Solve(Sudoku &sudoku) {
    auto all_cell_container = sudoku.GetAllCellContainers();
    for (auto container : all_cell_container) {
        for (std::size_t number{1}; number < 10; ++number) {
            if (container->IsNumberInContainer(number)) { continue; }
            auto cells = container->GetEmptyCellsIncludingThisPossibleNumber(number);
            if (cells.size() == 1) { cells[0]->SetNumber(number); };
        }
    }
}