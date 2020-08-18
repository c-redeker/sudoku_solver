#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <reader.hpp>

bool SudokuReader::ReadSudokuFromTxtFile(const std::string &path_to_text_file, std::vector<std::size_t> &numbers) {
    bool success{true};
    std::ifstream input_file;
    input_file.open(path_to_text_file);
    std::string line;
    std::string delimiter = ",";
    int pos{0};

    numbers.clear();
    if (input_file.is_open()) {
        getline(input_file, line);
        pos = line.find(delimiter);
        if (pos < 0) { pos = line.size(); }
        const std::string all_numbers_string{line.substr(0, pos)};
        for (std::size_t index{0}; index < all_numbers_string.size(); ++index) {
            std::string single_number{all_numbers_string.at(index)};
            std::string::const_iterator it = single_number.begin();
            if (!std::isdigit(*it)) {
                std::cout << "Invalid input file: invalid digit found \n";
                return false;
            }
            const int number{std::stoi(single_number)};
            numbers.push_back(static_cast<std::size_t>(number));
        }
        input_file.close();
        success = CheckValidityOfNumbers(numbers);
    } else {
        std::cout << "Unable to open specified input file " << path_to_text_file << "\n";
        success = false;
    }

    return success;
};

bool SudokuReader::CheckValidityOfNumbers(const std::vector<std::size_t> &numbers) {
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