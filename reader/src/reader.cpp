#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <reader.hpp>

bool SudokuReader::ReadSudokuFromTxtFile(const std::string &path_to_text_file, std::vector<uint> &numbers) {
    bool success{true};
    std::ifstream input_file;
    input_file.open(path_to_text_file);
    std::string line;
    std::string::size_type sz;// alias of size_t
    std::string delimiter = ";";
    int pos{0};

    numbers.clear();
    if (input_file.is_open()) {
        while (getline(input_file, line)) {
            do {
                pos = line.find(delimiter);
                const std::string single_number{line.substr(0, pos)};
                const int number{std::stoi(single_number, &sz)};
                numbers.push_back(static_cast<uint>(number));
                line.erase(0, pos + delimiter.length());
            } while (!line.empty() && pos >= 0);
        }
        input_file.close();
        success = CheckValidityOfNumbers(numbers);
    } else {
        std::cout << "Unable to open specified input file " << path_to_text_file << "\n";
        success = false;
    }

    return success;
};

bool SudokuReader::CheckValidityOfNumbers(const std::vector<uint> &numbers) {
    if (numbers.size() != kCountNumbers) {
        std::cout << "Invalid input file: " << numbers.size() << " numbers found \n";
        return false;
    }
    for (const auto &number : numbers) {
        if (number < 0 || number > 9) {
            std::cout << "Invalid input file: number not between 0 and 9 \n";
            return false;
        }
    }
    return true;
}