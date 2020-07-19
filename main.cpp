#include <checker.hpp>
#include <printer.hpp>
#include <reader.hpp>
#include <solver_simple_exclude.hpp>
#include <sudoku.hpp>

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
        Sudoku sudoku(numbers_array);
        SudokuPrinter::PrintCellNumbers(sudoku);
        if (!SudokuChecker::IsSolvable(sudoku)) { return 0; }


        std::vector<ISolver *> solver_list{};
        // add more solver
        ISolver *solver_simple_exclude = new SolverSimpleExclude{};
        solver_list.push_back(solver_simple_exclude);

        std::size_t count_empty_cells_previous{82U};
        auto count_empty_cells = sudoku.GetCountOfEmptyCells();

        std::size_t solving_step{1};
        while (count_empty_cells < count_empty_cells_previous && count_empty_cells > 0) {
            std::cout << "Solving Step: " << solving_step << std::endl;
            for (auto solver : solver_list) { solver->Solve(sudoku); }

            count_empty_cells_previous = count_empty_cells;
            count_empty_cells = sudoku.GetCountOfEmptyCells();
            std::cout << "Remaining empty cells: " << count_empty_cells << std::endl;
            solving_step++;
        }

        std::cout << "\n ------- solution after solving with 1 solver ---------- \n";
        SudokuPrinter::PrintCellNumbers(sudoku);
    }
    return 0;
}
