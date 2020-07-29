#include <cell.hpp>

Cell::Cell(const std::size_t number, const std::size_t row_index, const std::size_t column_index) {
    SetNumber(number);
    m_row_index = row_index;
    m_column_index = column_index;
    CalculateConnectedRowIndices();
    CalculateConnectedColumnIndices();
    CalculateRectangleIndex();
}

std::size_t Cell::GetNumber() const { return m_number; };
void Cell::SetNumber(std::size_t number) {
    m_number = number;
    UpdateCellFilledAttribute();
    UpdatePossibleNumbers();
};

std::size_t Cell::GetRowIndex() const { return m_row_index; };

std::size_t Cell::GetColumnIndex() const { return m_column_index; };

std::size_t Cell::GetRectangleIndex() const { return m_rectangle_index; };

bool Cell::IsCellFilled() const { return m_is_cell_filled; };

std::array<std::size_t, 2U> Cell::GetConnectedRowIndices() const { return m_connected_row_indices; };

std::array<std::size_t, 2U> Cell::GetConnectedColumnIndices() const { return m_connected_column_indices; };

std::vector<std::size_t> Cell::GetPossibleNumbers() { return m_possible_numbers; };

bool Cell::IsNumberPossible(std::size_t number) const {
    return std::find(m_possible_numbers.begin(), m_possible_numbers.end(), number) != m_possible_numbers.end();
}

bool Cell::AllNumbersPossible(const std::vector<std::size_t> &numbers) const {
    for (const auto number : numbers) {
        if (!IsNumberPossible(number)) { return false; }
    }
    return true;
}

bool Cell::AnyNumberPossible(const std::vector<std::size_t> &numbers) const {
    for (const auto number : numbers) {
        if (IsNumberPossible(number)) { return true; }
    }
    return false;
}

std::size_t Cell::GetCountPossibleNumbers() { return m_possible_numbers.size(); };

void Cell::UpdateCellFilledAttribute() { m_is_cell_filled = (m_number > 0U && m_number < 10U); };

void Cell::UpdatePossibleNumbers() {
    if (m_number > 0 && m_number < 10) {
        std::vector<std::size_t> possible_numbers;
        possible_numbers.push_back(m_number);
        m_possible_numbers = possible_numbers;
    } else {
        m_possible_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    }
}

void Cell::RemoveNumbersFromPossibleNumbers(const std::vector<std::size_t> &numbers_to_remove) {
    for (const auto number_to_remove : numbers_to_remove) {
        m_possible_numbers.erase(std::remove(m_possible_numbers.begin(), m_possible_numbers.end(), number_to_remove),
                                 m_possible_numbers.end());
    }
}

void Cell::RemoveAllPossibleNumberExceptSpecified(const std::vector<std::size_t> &numbers_to_keep) {
    std::vector<std::size_t> numbers_to_remove{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto number_to_keep : numbers_to_keep) {
        numbers_to_remove.erase(std::remove(numbers_to_remove.begin(), numbers_to_remove.end(), number_to_keep),
                                numbers_to_remove.end());
    }
    RemoveNumbersFromPossibleNumbers(numbers_to_remove);
}

void Cell::CalculateConnectedRowIndices() { CalculateConnectedIndices(m_row_index, m_connected_row_indices); };

void Cell::CalculateConnectedColumnIndices() { CalculateConnectedIndices(m_column_index, m_connected_column_indices); };

void Cell::CalculateConnectedIndices(const std::size_t index, std::array<std::size_t, 2> &connected_indices) {
    std::size_t mod = index % 3U;
    switch (mod) {
        case 0U:
            connected_indices = {index + 1, index + 2};
            break;
        case 1U:
            connected_indices = {index - 1, index + 1};
            break;
        case 2U:
            connected_indices = {index - 2, index - 1};
            break;
        default:
            std::cout << "error \n";
    }
}

void Cell::CalculateRectangleIndex() {
    m_rectangle_index = static_cast<std::size_t>(m_row_index / 3) * 3U + static_cast<std::size_t>(m_column_index / 3);
}
