#include <gtest/gtest.h>
#include <reader.hpp>

TEST(sudoku_reader, empty_input_file) {
    std::vector<std::size_t> numbers{};
    const bool success = SudokuReader::ReadSudokuFromTxtFile("./testfile_empty.txt", numbers);
    EXPECT_FALSE(success);
}

TEST(sudoku_reader, input_file_contains_too_many_numbers) {
    std::vector<std::size_t> numbers{};
    const bool success = SudokuReader::ReadSudokuFromTxtFile("./testfile_too_many_numbers.txt", numbers);
    EXPECT_FALSE(success);
}

TEST(sudoku_reader, input_file_invalid_number) {
    std::vector<std::size_t> numbers{};
    const bool success = SudokuReader::ReadSudokuFromTxtFile("./testfile_invalid_number.txt", numbers);
    EXPECT_FALSE(success);
}

TEST(sudoku_reader, valid_input_file) {
    std::vector<std::size_t> numbers{};
    const bool success = SudokuReader::ReadSudokuFromTxtFile("./testfile_valid.txt", numbers);
    ASSERT_TRUE(success);
    EXPECT_EQ(kCountNumbers, numbers.size());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}