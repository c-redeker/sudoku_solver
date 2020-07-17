#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include <cell.hpp>
#include <column.hpp>
#include <rectangle.hpp>
#include <row.hpp>


class Sudoku {
public:
    Sudoku(const std::array<std::size_t, 81> &numbers);
    std::vector<Cell *> GetEmptyCells() const;
    std::size_t GetCountOfEmptyCells() const;
    Rectangle *GetRectangle(std::size_t index);
    Row *GetRow(std::size_t index);
    Column *GetColumn(std::size_t index);
    Cell *GetCell(std::size_t row, std::size_t column) const;

private:
    std::array<Cell *, 81> m_cells;
    Cell *m_grid[9][9];
    std::array<Rectangle *, 9> m_rectangles;
    std::array<Row *, 9> m_rows;
    std::array<Column *, 9> m_columns;
    //methods:
    void CreateSudoku(const std::array<std::size_t, 81> &);
    void CreateCellsOfSudoku(const std::array<std::size_t, 81> &numbers);
    void CreateRectanglesOfSudoku();
    void CreateRowsOfSudoku();
    void CreateColumnsOfSudoku();
    std::array<Cell *, 9> GetRectangleCells(std::size_t rectangle_index) const;
};

#endif//SUDOKU_SOLVER_SUDOKU_H
