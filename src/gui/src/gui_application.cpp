#include <gui_application.hpp>

SudokuGuiApplication::SudokuGuiApplication(int &argc, char *argv[], std::shared_ptr<Sudoku> sudoku,
                                           std::shared_ptr<SudokuSolver> solver)
    : m_q_application(argc, argv), m_gui(sudoku, solver), m_sudoku(sudoku), m_solver(solver) {
    m_q_application.exec();
}
