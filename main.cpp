#include <reader.hpp>
#include <sudoku.hpp>
#include <solver_simple_exclude.hpp>

#include <vector>

int main(int argc, char **argv) {
    std::vector<std::size_t> numbers{};
    const bool success = SudokuReader::ReadSudokuFromTxtFile("", numbers);
    if (success) {
        std::array<std::size_t, kCountNumbers> numbers_array = {0};
        for (std::size_t i{}; i < numbers_array.size(); ++i) {
            numbers_array[i] = numbers[i];
        }
        // create sudoku object
        Sudoku sudoku(numbers_array);

        std::vector<ISolver*> solver{};
        // add more solver
        ISolver* solver_simple_exclude = new SolverSimpleExclude{};
        solver.push_back(solver_simple_exclude);

    }
    return 0;
}