#ifndef SUDOKU_SOLVER_COLUMN_H
#define SUDOKU_SOLVER_COLUMN_H

#include <cell_container.hpp>

class Column : public CellContainer {
public:
    Column(std::array<Cell *, 9> &cells, const std::size_t index) : CellContainer(cells, index){};
};

#endif//SUDOKU_SOLVER_COLUMN_H
