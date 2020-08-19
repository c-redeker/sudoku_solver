#ifndef SUDOKU_SOLVER_GUI_APPLICATION_HPP
#define SUDOKU_SOLVER_GUI_APPLICATION_HPP

#include <QApplication>
#include <gui.hpp>
#include <sudoku_solver.hpp>

class SudokuGuiApplication {

public:
    SudokuGuiApplication(int &argc, char *argv[], std::shared_ptr<Sudoku>, std::shared_ptr<SudokuSolver>);

private:
    QApplication m_q_application;
    SudokuGui m_gui;
    std::shared_ptr<Sudoku> m_sudoku;
    std::shared_ptr<SudokuSolver> m_solver;
};

#endif//SUDOKU_SOLVER_GUI_APPLICATION_HPP
