#include <sudoku.hpp>

#include <cmath>

Sudoku::Sudoku(const std::array<std::size_t, 81> &numbers) { CreateSudoku(numbers); };

void Sudoku::CreateSudoku(const std::array<std::size_t, 81> &numbers) {
    CreateCellsOfSudoku(numbers);
    CreateRectanglesOfSudoku();
    CreateRowsOfSudoku();
    CreateColumnsOfSudoku();
};

void Sudoku::CreateCellsOfSudoku(const std::array<std::size_t, 81> &numbers) {
    int row{0};
    int column{0};
    for (const auto number : numbers) {
        Cell *cellPtr = new Cell(number, row, column);
        AddCellToGrid(cellPtr, row, column);
        column++;
        if (column == 9) {
            row++;
            column = 0;
        }
    }
};

void Sudoku::CreateRectanglesOfSudoku() {
    for (std::size_t rectangle_index{0}; rectangle_index < 9; ++rectangle_index) {
        auto cells = GetRectangleCells(rectangle_index);
        Rectangle *rectangle = new Rectangle(cells, rectangle_index);
        m_rectangles[rectangle_index] = rectangle;
    }
};

void Sudoku::CreateRowsOfSudoku() {
    for (std::size_t row_index{0}; row_index < 9; ++row_index) {
        std::array<Cell *, 9> cells_of_row{};
        for (std::size_t column_index{0}; column_index < 9; ++column_index) {
            cells_of_row[column_index] = GetCell(row_index, column_index);
        }
        Row *row = new Row(cells_of_row, row_index);
        m_rows[row_index] = row;
    }
};

void Sudoku::CreateColumnsOfSudoku() {
    for (std::size_t column_index{0}; column_index < 9; ++column_index) {
        std::array<Cell *, 9> cells_of_column{};
        for (std::size_t row_index{0}; row_index < 9; ++row_index) {
            cells_of_column[row_index] = GetCell(row_index, column_index);
        }
        Column *column = new Column(cells_of_column, column_index);
        m_columns[column_index] = column;
    }
};

std::array<Cell*, 9> Sudoku::GetRectangleCells(std::size_t rectangle_index) const {
    std::size_t first_row_index = std::floor(rectangle_index / 3U) * 3U;
    std::size_t first_column_index = std::floor(rectangle_index % 3U) * 3U;
    std::array<Cell *, 9> cells{};
    std::size_t cell_counter{};
    for (std::size_t row_index{first_row_index}; row_index < first_row_index + 3U; ++row_index) {
        for (std::size_t column_index{first_column_index}; column_index < first_column_index + 3U; ++column_index) {
            cells[cell_counter] = m_grid[row_index][column_index];
            ++cell_counter;
        }
    }
    return cells;
}

Cell *Sudoku::GetCell(std::size_t row, std::size_t column) { return m_grid[row][column]; };

Rectangle *Sudoku::GetRectangle(std::size_t index) { return m_rectangles[index]; }

Row *Sudoku::GetRow(std::size_t index) { return m_rows[index]; }

Column *Sudoku::GetColumn(std::size_t index) { return m_columns[index]; }

void Sudoku::AddCellToGrid(Cell *cell, std::size_t row, std::size_t column) { m_grid[row][column] = cell; };
