#include <free_functions_solver.hpp>
#include <solver_hidden_pairs.h>

void SolverHiddenPairs::Solve(Sudoku &sudoku) {
    auto all_cell_container = sudoku.GetAllCellContainers();
    for (auto container : all_cell_container) { FindHiddenPair(container); }
    WriteOnlyPossibleNumberIntoEachCell(sudoku);
}

void SolverHiddenPairs::FindHiddenPair(const CellContainer *cell_container) {
    const auto all_subsets = FindAllUniqueSubsetsInContainer(cell_container);
    std::cout << "size of all subsets: " << all_subsets.size() << std::endl;
    auto empty_cells = cell_container->GetEmptyCells();
    for (const auto &subset : all_subsets) {
        auto cells_with_subset = FindAllCellsWithSubset(empty_cells, subset);
        if (cells_with_subset.size() == subset.size()) {
            auto cells = FindAllCellsWithAtLeastOneNumberFromSubset(empty_cells, subset);
            if (cells_with_subset == cells) {
                for (auto cell_with_subset : cells_with_subset) {
                    cell_with_subset->RemoveAllPossibleNumberExceptSpecified(subset);
                }
            }
        }
    }
}

std::vector<Subset> SolverHiddenPairs::FindAllUniqueSubsetsInContainer(const CellContainer *cell_container) {
    auto empty_cells = cell_container->GetEmptyCells();
    std::vector<Subset> all_subsets{};
    for (auto empty_cell : empty_cells) {
        const auto possible_numbers = empty_cell->GetPossibleNumbers();
        const auto subsets = SubsetsGenerator::CreateSubsets(possible_numbers);
        for (const auto &subset : subsets) {
            if (!(std::find(all_subsets.begin(), all_subsets.end(), subset) != all_subsets.end())) {
                all_subsets.push_back(subset);
            }
        }
    }
    return all_subsets;
}

std::vector<Cell *> SolverHiddenPairs::FindAllCellsWithSubset(const std::vector<Cell *> &empty_cells,
                                                              const Subset &subset) {
    std::vector<Cell *> cells_with_subset{};
    for (auto empty_cell : empty_cells) {
        if (empty_cell->AllNumbersPossible(subset)) { cells_with_subset.push_back(empty_cell); }
    }
    return cells_with_subset;
};

std::vector<Cell *>
SolverHiddenPairs::FindAllCellsWithAtLeastOneNumberFromSubset(const std::vector<Cell *> &empty_cells,
                                                              const Subset &numbers) {
    std::vector<Cell *> cells{};
    for (auto empty_cell : empty_cells) {
        if (empty_cell->AnyNumberPossible(numbers)) { cells.push_back(empty_cell); }
    }
    return cells;
};