#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include <cell.hpp>
#include <rectangle.hpp>

class Sudoku {
public:
    explicit Sudoku(const std::array<std::size_t, 81> &numbers);
    ~Sudoku();
    std::vector<Cell *> GetEmptyCells() const;
    std::size_t GetCountOfEmptyCells() const;
    std::array<CellContainer *, 27> GetAllCellContainers() const;
    Rectangle *GetRectangle(std::size_t index) const;
    std::array<Rectangle *, 9> GetAllRectangles() const;
    CellContainer *GetRow(std::size_t index) const;
    const std::array<CellContainer *, 9> &GetAllRows() const;
    CellContainer *GetColumn(std::size_t index) const;
    const std::array<CellContainer *, 9> &GetAllColumns() const;
    Cell *GetCell(std::size_t row, std::size_t column) const;

private:
    std::array<Cell *, 81> m_cells;
    Cell *m_grid[9][9];
    std::array<Rectangle *, 9> m_rectangles;
    std::array<CellContainer *, 9> m_rows;
    std::array<CellContainer *, 9> m_columns;
    std::array<CellContainer *, 27> m_cell_containers;
    //methods:
    void CreateSudoku(const std::array<std::size_t, 81> &);
    void CreateCellsOfSudoku(const std::array<std::size_t, 81> &numbers);
    void CreateRectanglesOfSudoku();
    void CreateRowsOfSudoku();
    void CreateColumnsOfSudoku();
    void CopyCellContainer();
    std::array<Cell *, 9> GetRectangleCells(std::size_t rectangle_index) const;
};

#endif//SUDOKU_SOLVER_SUDOKU_H
