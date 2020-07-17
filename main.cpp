#include <reader.hpp>
#include <printer.hpp>
#include <sudoku.hpp>
#include <solver_simple_exclude.hpp>

#include <vector>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Please provide a file containing the sudoku to solve as an input argument. \n";
        return 0;
    }
    const auto sudoku_input_file = argv[1];
    std::vector<std::size_t> numbers{};
    const bool success = SudokuReader::ReadSudokuFromTxtFile(sudoku_input_file, numbers);
    if (success) {
        std::array<std::size_t, kCountNumbers> numbers_array = {0};
        for (std::size_t i{}; i < numbers_array.size(); ++i) {
            numbers_array[i] = numbers[i];
        }
        // create sudoku object
        Sudoku sudoku(numbers_array);

        SudokuPrinter::PrintCellNumbers(sudoku);

        std::vector<ISolver*> solver{};
        // add more solver
        ISolver* solver_simple_exclude = new SolverSimpleExclude{};
        solver.push_back(solver_simple_exclude);

        SudokuPrinter::PrintCellNumbers(sudoku);
    }
    return 0;
}