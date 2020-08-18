#include <rectangle.hpp>

std::array<std::size_t, 3U> Rectangle::GetRowIndices() const { return m_row_indices; }

std::array<std::size_t, 3U> Rectangle::GetColumnIndices() const { return m_column_indices; }

//std::vector<Cell *> Rectangle::getLastEmptyCellsOfSubrow() {
//    std::vector<Cell *> lastEmptyCellsInRow;
//    for (auto emptyCell1 : this->GetEmptyCells()) {
//        bool isOnlyEmptyCellInSubRow = true;
//        for (auto emptyCell2 : this->GetEmptyCells()) {
//            if (emptyCell1->getRowIndex() == emptyCell2->getRowIndex() &&
//                emptyCell1->getColumnIndex() != emptyCell2->getColumnIndex()) {
//                isOnlyEmptyCellInSubRow = false;
//            }
//        }
//        if (isOnlyEmptyCellInSubRow) { lastEmptyCellsInRow.push_back(emptyCell1); }
//    }
//    return lastEmptyCellsInRow;
//};

//std::vector<Cell *> Rectangle::getLastEmptyCellsOfSubcolumn() {
//    std::vector<Cell *> lastEmptyCellsInColumn;
//    for (auto emptyCell1 : this->GetEmptyCells()) {
//        bool isOnlyEmptyCellInSubcolumn = true;
//        for (auto emptyCell2 : this->GetEmptyCells()) {
//            if (emptyCell1->getRowIndex() != emptyCell2->getRowIndex() &&
//                emptyCell1->getColumnIndex() == emptyCell2->getColumnIndex()) {
//                isOnlyEmptyCellInSubcolumn = false;
//            }
//        }
//        if (isOnlyEmptyCellInSubcolumn) { lastEmptyCellsInColumn.push_back(emptyCell1); }
//    }
//    return lastEmptyCellsInColumn;
//};

void Rectangle::CalcRowIndicesOfRectangle() {
    const auto first_row_index = ((int) (m_index) / 3U) * 3U;
    AddIndices(m_row_indices, first_row_index);
}

void Rectangle::CalcColumnIndicesOfRectangle() {
    const auto first_column_index = ((m_index) % 3U) * 3U;
    AddIndices(m_column_indices, first_column_index);
}

void Rectangle::AddIndices(std::array<std::size_t, 3U> &indices, std::size_t first_index) {
    indices[0] = first_index;
    indices[1] = first_index + 1;
    indices[2] = first_index + 2;
}