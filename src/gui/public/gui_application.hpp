#ifndef SUDOKU_SOLVER_GUI_APPLICATION_HPP
#define SUDOKU_SOLVER_GUI_APPLICATION_HPP

#include <QApplication>
#include <gui.hpp>

class SudokuGuiApplication {

public:
    SudokuGuiApplication(int &argc, char *argv[]);
    void DisplaySudoku(const Sudoku &sudoku);

private:
    QApplication m_q_application;
    SudokuGui m_gui;
};

#endif//SUDOKU_SOLVER_GUI_APPLICATION_HPP
