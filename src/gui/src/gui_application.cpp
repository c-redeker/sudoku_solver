#include <gui_application.hpp>

SudokuGuiApplication::SudokuGuiApplication(int &argc, char *argv[]) : m_q_application(argc, argv) {}

void SudokuGuiApplication::DisplaySudoku(const Sudoku &sudoku) {
    m_gui.DisplaySudoku(sudoku);
    m_q_application.exec();
}