#ifndef SUDOKU_SOLVER_GUI_H
#define SUDOKU_SOLVER_GUI_H

#include <QMainWindow>
#include <QTableWidget>
#include <array>
#include <sudoku.hpp>

class SudokuGui : QMainWindow {
public:
    SudokuGui();
    void DisplaySudoku(const Sudoku &sudoku);

private:
    void CreateTableWidget();
    static void WriteNumberIntoCellItem(QTableWidgetItem *item, const std::size_t number);
    static void WritePossibleNumbersIntoCellItem(QTableWidgetItem *item,
                                                 const std::vector<std::size_t> &possible_numbers);

    QTableWidget m_table_widget{this};
};

#endif//SUDOKU_SOLVER_GUI_H
