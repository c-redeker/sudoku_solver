#ifndef SUDOKU_SOLVER_GUI_H
#define SUDOKU_SOLVER_GUI_H

#include <QApplication>
#include <QTableWidget>
#include <array>
#include <sudoku.hpp>

class SudokuGui {
public:
    SudokuGui(int &argc, char *argv[]);
    void DisplaySudoku(const Sudoku &sudoku);

private:
    QApplication m_q_application;
    QTableWidget m_table_widget{};
    static void WriteNumberIntoCellItem(QTableWidgetItem *item, const std::size_t number);
    static void WritePossibleNumbersIntoCellItem(QTableWidgetItem *item,
                                                 const std::vector<std::size_t> &possible_numbers);
};

#endif//SUDOKU_SOLVER_GUI_H
