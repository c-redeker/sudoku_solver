#ifndef SudokuReader_h
#define SudokuReader_h

#include <string>
#include <vector>

static constexpr uint kCountNumbers{81};

class SudokuReader {
public:
    SudokuReader() = delete;
    static bool ReadSudokuFromTxtFile(const std::string &path_to_text_file, std::vector<std::size_t> &numbers);

private:
    static bool CheckValidityOfNumbers(const std::vector<std::size_t> &numbers);
};

#endif
