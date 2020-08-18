#include <printer.hpp>

void SudokuPrinter::PrintCellNumbers(Sudoku &sudoku) {
    std::vector<std::string> strings_vector;

    for (int rowNumber{0}; rowNumber < 9; ++rowNumber) {
        for (int columnNumber{0}; columnNumber < 9; ++columnNumber) {
            int number = sudoku.GetCell(rowNumber, columnNumber)->GetNumber();
            std::string cell_number_string;
            if (number == 0) {
                cell_number_string = " ";
            } else {
                cell_number_string = std::to_string(number);
            }
            strings_vector.push_back(cell_number_string);
        }
    }
    Print(strings_vector);
};

void SudokuPrinter::PrintRectangleIndex(Sudoku &_sudoku) {
    std::vector<std::string> stringVec;

    for (int rowNumber = 0; rowNumber < 9; rowNumber++) {
        for (int columnNumber = 0; columnNumber < 9; columnNumber++) {
            int rectangleIndex = _sudoku.GetCell(rowNumber, columnNumber)->GetRectangleIndex();
            std::string rectangleIndexString = std::to_string(rectangleIndex);
            stringVec.push_back(rectangleIndexString);
        }
    }
    Print(stringVec);
};

void SudokuPrinter::Print(std::vector<std::string> stringVec) {
    int cellCounter = 0;
    int rowCounter = 0;
    std::cout << "------------------------------------\n";
    for (int rowNumber = 0; rowNumber < 9; rowNumber++) {
        rowCounter++;
        std::string rowString = "|";
        int columnCounter = 0;
        for (int columnNumber = 0; columnNumber < 9; columnNumber++) {
            rowString = rowString + " " + stringVec[cellCounter] + " ";

            columnCounter++;
            if (columnCounter == 3) {
                rowString = rowString + " | ";
                columnCounter = 0;
            }
            cellCounter++;
        }
        rowString = rowString + "\n";
        std::cout << rowString;

        if (rowCounter == 3) {
            std::cout << "------------------------------------\n";
            rowCounter = 0;
        }
    }
};

void SudokuPrinter::PrintCountOfEmptyCells(Sudoku &sudoku) {
    std::cout << "Empty cells: " << sudoku.GetCountOfEmptyCells() << "\n";
    std::cout << "   \n";
};