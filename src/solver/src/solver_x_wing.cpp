#include <solver_x_wing.hpp>

void SolverXwing::Solve(Sudoku &sudoku) {
    const auto rows = sudoku.GetAllRows();
    const auto columns = sudoku.GetAllColumns();

    DoXwingOnColumns(columns, rows);
    // todo(c.redeker) add DoXwingOnRows function
}

void SolverXwing::DoXwingOnColumns(const std::array<CellContainer *, 9> &columns,
                                   const std::array<CellContainer *, 9> &rows) const {
    for (std::size_t number{1}; number < 10; ++number) {

        auto pair_cells_incl_number = FindPairCellsWithPossibleNumber(columns, number);

        if (pair_cells_incl_number.size() == 4) {
            const auto row_indices = FindDifferentRowIndices(pair_cells_incl_number);
            const auto column_indices = FindDifferentColumnIndices(pair_cells_incl_number);

            if (row_indices.size() == 2 && column_indices.size() == 2) {
                for (const auto row : rows) {
                    const auto row_index = row->GetIndex();
                    if (row_index == row_indices[0] || row_index == row_indices[1]) {
                        for (const auto cell : row->GetEmptyCells()) {
                            const auto column_index_of_cell = cell->GetColumnIndex();
                            if (column_index_of_cell != column_indices[0] &&
                                column_index_of_cell != column_indices[1]) {
                                cell->RemoveNumbersFromPossibleNumbers({number});
                            }
                        }
                    }
                }
            }
        }
    }
}

std::vector<Cell *> SolverXwing::FindPairCellsWithPossibleNumber(const std::array<CellContainer *, 9> &columns,
                                                                 std::size_t number) const {
    std::vector<Cell *> cells_incl_number{};
    for (const auto column : columns) {
        const auto cells = column->GetEmptyCellsIncludingThisPossibleNumber(number);
        if (cells.size() == 2) {
            cells_incl_number.push_back(cells[0]);
            cells_incl_number.push_back(cells[1]);
        }
    }
    return cells_incl_number;
}

std::vector<std::size_t> SolverXwing::FindDifferentRowIndices(const std::vector<Cell *> &cells) const {
    std::vector<std::size_t> indices{};
    for (const auto cell : cells) {
        const auto row_index = cell->GetRowIndex();
        if (!(std::find(indices.begin(), indices.end(), row_index) != indices.end())) { indices.push_back(row_index); }
    }
    return indices;
}

std::vector<std::size_t> SolverXwing::FindDifferentColumnIndices(const std::vector<Cell *> &cells) const {
    std::vector<std::size_t> indices{};
    for (const auto cell : cells) {
        const auto column_index = cell->GetColumnIndex();
        if (!(std::find(indices.begin(), indices.end(), column_index) != indices.end())) {
            indices.push_back(column_index);
        }
    }
    return indices;
}