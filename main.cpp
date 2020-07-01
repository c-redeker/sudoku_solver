#include <reader.hpp>
#include <vector>

int main(int argc, char **argv) {
    std::vector<uint> numbers{};
    const bool success = SudokuReader::ReadSudokuFromTxtFile("", numbers);
    if (success) {
        // create sudoku object
    }
    return 0;
}