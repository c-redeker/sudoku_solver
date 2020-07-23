#ifndef types_Cell_h
#define types_Cell_h

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

class Cell {
public:
    Cell(const std::size_t number, const std::size_t row_index, const std::size_t column_index);
    std::size_t GetNumber() const;
    void SetNumber(std::size_t);
    std::size_t GetRowIndex() const;
    std::size_t GetColumnIndex() const;
    std::size_t GetRectangleIndex() const;
    bool IsCellFilled() const;

    std::array<std::size_t, 2U> GetConnectedRowIndices() const;
    std::array<std::size_t, 2U> GetConnectedColumnIndices() const;

    std::vector<std::size_t> GetPossibleNumbers();
    bool IsNumberPossible(std::size_t number) const;
    std::size_t GetCountPossibleNumbers();
    void RemoveNumbersFromPossibleNumbers(const std::vector<std::size_t> &numbers_to_remove);
    void RemoveAllPossibleNumberExceptSpecified(const std::vector<std::size_t> &numbers_to_keep);

private:
    std::size_t m_number{0};         // [0..9]
    std::size_t m_row_index{0};      // [0..8]
    std::size_t m_column_index{0};   // [0..8]
    std::size_t m_rectangle_index{0};// [0..8]
    bool m_is_cell_filled{false};
    std::array<std::size_t, 2U> m_connected_row_indices{0,0};
    std::array<std::size_t, 2U> m_connected_column_indices{0,0};
    std::array<std::size_t, 2U> m_connected_rectangle_row_indices{0,0};
    std::array<std::size_t, 2U> m_connected_rectangle_column_indices{0,0};

    std::vector<std::size_t> m_possible_numbers;
    // methods:
    void CalculateConnectedRowIndices();
    void CalculateConnectedColumnIndices();
    static void CalculateConnectedIndices(const std::size_t index, std::array<std::size_t, 2>& connected_indices);
    void CalculateRectangleIndex();
    void UpdateCellFilledAttribute();
    void UpdatePossibleNumbers();
};

#endif// types_Cell_h
