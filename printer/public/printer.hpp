#ifndef SUDOKU_SOLVER_PRINTER_H
#define SUDOKU_SOLVER_PRINTER_H

#include <sudoku.hpp>

#include <iostream>
#include <string>
#include <vector>

class SudokuPrinter
{
public:
    static void PrintCellNumbers(Sudoku&);
    static void PrintRectangleIndex(Sudoku&);
    static void PrintCountOfEmptyCells(Sudoku&);

private:
    static void Print(std::vector<std::string>);
};

#endif//SUDOKU_SOLVER_PRINTER_H
