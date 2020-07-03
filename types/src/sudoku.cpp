#include <sudoku.hpp>

Sudoku::Sudoku(const std::array<std::size_t, 81> &numbers) { CreateSudoku(numbers); };

void Sudoku::CreateSudoku(const std::array<std::size_t, 81> &numbers) {
    CreateCellsOfSudoku(numbers);
    // createRectanglesOfSudoku();
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

//void Sudoku::createRectanglesOfSudoku() {
//    // TODO: replace by function "void calcRowAndColumnIndices()" from class rectangle
//    for (int recIndex = 0; recIndex < 9; recIndex++) {
//        Rectangle *rectangle = new Rectangle(recIndex);
//
//        int firstRowIndex = rectangle->calcFirstRowIndexOfRectangle();
//        int firstColumnIndex = rectangle->calcFirstColumnIndexOfRectangle();
//
//        int rowIndex = firstRowIndex;
//        int columnIndex = firstColumnIndex;
//        for (int cellCount = 1; cellCount < 10; cellCount++) {
//            rectangle->addCell(getCell(rowIndex, columnIndex));
//            getCell(rowIndex, columnIndex)->setRectangleIndex(rectangle->getIndex());
//
//            // change row and/or column indices
//            if (cellCount % 3 == 0) {
//                rowIndex++;
//                columnIndex = firstColumnIndex;
//            } else
//                columnIndex++;
//        }
//        rectangles.push_back(rectangle);
//    }
//};

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


Cell *Sudoku::GetCell(std::size_t row, std::size_t column) { return m_grid[row][column]; };

// Rectangle *Sudoku::getRectangle(int rectangleIndex) { return rectangles[rectangleIndex]; }

Row *Sudoku::GetRow(std::size_t index) { return m_rows[index]; }

Column *Sudoku::GetColumn(std::size_t index) { return m_columns[index]; }

void Sudoku::AddCellToGrid(Cell *cell, std::size_t row, std::size_t column) { m_grid[row][column] = cell; };
