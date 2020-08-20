#ifndef SUDOKU_SOLVER_GUI_H
#define SUDOKU_SOLVER_GUI_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <sudoku.hpp>
#include <sudoku_solver.hpp>

#include <array>

class SudokuGui : public QMainWindow {

public:
    SudokuGui(std::shared_ptr<Sudoku>, std::shared_ptr<SudokuSolver>);

public slots:
    void SolveAndDisplaySudoku();
    void SolveOneStepAndDisplaySudoku();

private:
    void CreateTableWidget();
    void CreateButtonSolve();
    void CreateButtonSolveStep();
    static void WriteNumberIntoCellItem(QTableWidgetItem *item, const std::size_t number);
    static void WritePossibleNumbersIntoCellItem(QTableWidgetItem *item,
                                                 const std::vector<std::size_t> &possible_numbers);
    void DisplaySudoku();
    void SolveSudoku();

    QTableWidget m_table_widget{this};
    QPushButton m_button_solve{this};
    QPushButton m_button_solve_step{this};
    std::shared_ptr<Sudoku> m_sudoku;
    std::shared_ptr<SudokuSolver> m_solver;
};

#endif//SUDOKU_SOLVER_GUI_H
