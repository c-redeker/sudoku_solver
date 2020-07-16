#ifndef SUDOKU_SOLVER_RECTANGLE_H
#define SUDOKU_SOLVER_RECTANGLE_H

#include <cell_container.hpp>

class Rectangle : public CellContainer {
public:
    Rectangle(std::array<Cell *, 9> &cells, const std::size_t index) : CellContainer(cells, index) {
        CalcRowIndicesOfRectangle();
        CalcColumnIndicesOfRectangle();
    };
    std::array<std::size_t, 3U> GetRowIndices() const;
    std::array<std::size_t, 3U> GetColumnIndices() const;
//    std::vector<Cell *> getLastEmptyCellsOfSubrow();
//    std::vector<Cell *> getLastEmptyCellsOfSubcolumn();

private:
    std::array<std::size_t, 3U> m_row_indices;
    std::array<std::size_t, 3U> m_column_indices;
    // methods:
    void CalcRowIndicesOfRectangle();
    void CalcColumnIndicesOfRectangle();
    void AddIndices(std::array<std::size_t, 3U> &indices, std::size_t first_index);
};

#endif//SUDOKU_SOLVER_RECTANGLE_H
