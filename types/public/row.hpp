#ifndef SUDOKU_SOLVER_ROW_H
#define SUDOKU_SOLVER_ROW_H

#include <cell_container.hpp>

class Row : public CellContainer {
public:
    Row(std::array<Cell *, 9> &cells, const std::size_t index) : CellContainer(cells, index){};
};

#endif//SUDOKU_SOLVER_ROW_H
