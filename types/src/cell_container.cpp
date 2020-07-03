#include <cell_container.hpp>

CellContainer::CellContainer(std::array<std::shared_ptr<Cell>, 9> cells, const std::size_t index)
    : m_cells(cells), m_index(index){};

std::size_t CellContainer::GetIndex() const { return m_index; }

std::array<std::shared_ptr<Cell>, 9> CellContainer::GetAllCells() { return m_cells; };

std::vector<std::shared_ptr<Cell>> CellContainer::GetEmptyCells() {
    std::vector<std::shared_ptr<Cell>> empty_cells;
    for (const auto &cell : m_cells) {
        if (!(cell->IsCellFilled())) { empty_cells.push_back(cell); }
    }
    return empty_cells;
};

std::vector<std::shared_ptr<Cell>>
CellContainer::GetEmptyCellsIncludingThisPossibleNumber(std::size_t number_to_check) {
    std::vector<std::shared_ptr<Cell>> return_cells;
    for (const auto &empty_cell : this->GetEmptyCells()) {
        auto possible_numbers = empty_cell->GetPossibleNumbers();
        bool isPossibleNumberInThisCell =
                std::find(possible_numbers.begin(), possible_numbers.end(), number_to_check) != possible_numbers.end();
        if (isPossibleNumberInThisCell) { return_cells.push_back(empty_cell); }
    }
    return return_cells;
}

//std::vector<Cell *> CellContainer::getAllCellsIncludingPossibleNumberSubset(Subset &subset) {
//    std::vector<Cell *> cellIncludingSubset;
//    for (auto emptyCell : this->GetEmptyCells()) {
//        bool doesCellIncludeSubset = true;
//        for (auto numberOfSubset : subset.getNumbers()) {
//            std::vector<std::size_t> possibleNumbers = emptyCell->getPossibleNumbers();
//            if (std::find(possibleNumbers.begin(), possibleNumbers.end(), numberOfSubset) != possibleNumbers.end()) {
//            } else {
//                doesCellIncludeSubset = false;
//                break;
//            }
//        }
//        if (doesCellIncludeSubset) cellIncludingSubset.push_back(emptyCell);
//    }
//    return cellIncludingSubset;
//};

//std::vector<Cell *> CellContainer::GetAllCellsContainingAtLeastOneNumber(std::vector<std::size_t> numbers) {
//    std::vector<Cell *> cellsContainingAtLeastOne;
//    for (auto cell : this->m_cells) {
//        std::vector<std::size_t> possibleNumbers = cell->getPossibleNumbers();
//        for (auto number : numbers) {
//            if (std::find(possibleNumbers.begin(), possibleNumbers.end(), number) != possibleNumbers.end()) {
//                cellsContainingAtLeastOne.push_back(cell);
//                break;
//            }
//        }
//    }
//    return cellsContainingAtLeastOne;
//};

std::size_t CellContainer::GetCountOfEmptyCells() { return GetEmptyCells().size(); }

std::vector<std::size_t> CellContainer::GetFilledNumbers() const {
    std::vector<std::size_t> filled_numbers;
    for (const auto &cell : m_cells) {
        if (cell->IsCellFilled()) { filled_numbers.push_back(cell->GetNumber()); }
    }
    return filled_numbers;
};

std::vector<std::size_t> CellContainer::GetMissingNumbers() const {
    std::vector<std::size_t> missing_numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto &cell : m_cells) {
        const auto number_of_cell{cell->GetNumber()};
        missing_numbers.erase(std::remove(missing_numbers.begin(), missing_numbers.end(), number_of_cell),
                              missing_numbers.end());
    }
    return missing_numbers;
};

//void CellContainer::removeNumbersFromAllCellsExceptSpecified(std::vector<Cell *> cellsNotRemove,
//                                                             std::vector<std::size_t> &numbersToRemove) {
//    for (auto cell : m_cells) {
//        bool doRemoveNumbers = true;
//        for (auto cellNotRemove : cellsNotRemove) {
//            if (cell->getID() == cellNotRemove->getID()) {
//                doRemoveNumbers = false;
//                break;
//            }
//        }
//        if (doRemoveNumbers) { cell->removeNumbersFromPossibleNumbers(numbersToRemove); }
//    }
//}

bool CellContainer::IsNumberInContainer(std::size_t number) const {
    std::vector<std::size_t> filledNumbers = this->GetFilledNumbers();
    if (std::find(filledNumbers.begin(), filledNumbers.end(), number) != filledNumbers.end()) return true;
    else
        return false;
}
