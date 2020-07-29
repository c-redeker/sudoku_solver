#include <solver_hidden_pairs.h>

void SolverHiddenPairs::Solve(Sudoku &sudoku) {
    auto all_cell_container = sudoku.GetAllCellContainers();
    for (auto container : all_cell_container) { FindHiddenPair(container); }
}

void SolverHiddenPairs::FindHiddenPair(const CellContainer *cell_container) {
    const auto all_subsets = FindAllUniqueSubsetsInContainer(cell_container);

    auto empty_cells = cell_container->GetEmptyCells();
    for (const auto &subset : all_subsets) {
        auto cells_with_subset = FindAllCellsWithSubset(empty_cells, subset);
        if (cells_with_subset.size() == subset.size()) {
            auto cells = FindAllCellsWithAtLeastOneNumberFromSubset(empty_cells, subset);
            if (cells_with_subset == cells) { RemoveAllNumbersExceptSubsetFromCells(cells_with_subset, subset); }
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
            if (subset.size() <= kMaxSubsetSize &&
                !(std::find(all_subsets.begin(), all_subsets.end(), subset) != all_subsets.end())) {
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
}

void SolverHiddenPairs::RemoveAllNumbersExceptSubsetFromCells(const std::vector<Cell *> &cells, const Subset &numbers) {
    for (auto cell : cells) {
        auto count_possible_numbers = cell->GetPossibleNumbers().size();
        if (numbers.size() < count_possible_numbers) { cell->RemoveAllPossibleNumberExceptSpecified(numbers); }
    }
}
