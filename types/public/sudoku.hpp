#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H
#include <algorithm>
#include <array>
#include <cell.hpp>
#include <column.hpp>
#include <iostream>
#include <rectangle.hpp>
#include <row.hpp>
#include <vector>

class Sudoku {
public:
    Sudoku(const std::array<std::size_t, 81> &numbers);

    Rectangle *GetRectangle(std::size_t index);
    Row *GetRow(std::size_t index);
    Column *GetColumn(std::size_t index);

private:
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
    void AddCellToGrid(Cell *, std::size_t, std::size_t);
    Cell *GetCell(std::size_t, std::size_t);
};

#endif//SUDOKU_SOLVER_SUDOKU_H
