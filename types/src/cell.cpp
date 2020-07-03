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

void Cell::RemoveNumbersFromPossibleNumbers(std::vector<std::size_t> &numbers_to_remove) {
    for (const auto number_to_remove : numbers_to_remove) {
        if (this->GetColumnIndex() == 0 && this->GetRowIndex() == 3 && number_to_remove == 1) std::cout << "test";
        this->m_possible_numbers.erase(
                std::remove(m_possible_numbers.begin(), m_possible_numbers.end(), number_to_remove),
                m_possible_numbers.end());
    }
}

void Cell::RemoveAllPossibleNumberExceptSpecified(std::vector<std::size_t> &numbers_to_keep) {
    for (const auto possible_number : m_possible_numbers) {
        if (std::find(numbers_to_keep.begin(), numbers_to_keep.end(), possible_number) != numbers_to_keep.end())
            continue;
        else {
            m_possible_numbers.erase(std::remove(m_possible_numbers.begin(), m_possible_numbers.end(), possible_number),
                                     m_possible_numbers.end());

            if (this->GetColumnIndex() == 0 && this->GetRowIndex() == 3 && possible_number == 1) std::cout << "test";
        }
    }
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