#include <checker.hpp>
#include <gui_application.hpp>
#include <printer.hpp>
#include <reader.hpp>
#include <sudoku.hpp>
#include <sudoku_solver.hpp>

#include <vector>

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cout << "Please provide a file containing the sudoku to solve as an input argument. \n";
        return 0;
    }
    const auto sudoku_input_file = argv[1];
    std::vector<std::size_t> numbers{};
    const bool reading_successful = SudokuReader::ReadSudokuFromTxtFile(sudoku_input_file, numbers);
    if (reading_successful) {
        std::array<std::size_t, kCountNumbers> numbers_array = {0};
        for (std::size_t i{}; i < numbers_array.size(); ++i) { numbers_array[i] = numbers[i]; }

        // create sudoku object
        std::shared_ptr<Sudoku> sudoku = std::make_shared<Sudoku>(numbers_array);
        SudokuPrinter::PrintCellNumbers(*sudoku);
        if (!SudokuChecker::IsSolvable(*sudoku)) {
            std::cout << "Sudoku is not solvable" << std::endl;
            return 0;
        }

        std::shared_ptr<SudokuSolver> solver = std::make_shared<SudokuSolver>();

        SudokuGuiApplication gui(argc, argv, sudoku, solver);

        SudokuPrinter::PrintCellNumbers(*sudoku);

        if (SudokuChecker::IsSolvedCompletely(*sudoku)) {
            if (SudokuChecker::IsSolvedCorrectly(*sudoku)) { std::cout << "Sudoku is solved correctly" << std::endl; }
        } else {
            if (SudokuChecker::IsSolvable(*sudoku)) { std::cout << "Sudoku is still solvable" << std::endl; }
        }
    }
    return 0;
}
