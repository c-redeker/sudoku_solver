#ifndef SUDOKU_SOLVER_CELL_CONTAINER_H
#define SUDOKU_SOLVER_CELL_CONTAINER_H

#include <array>
#include <cell.hpp>

#include <memory>
#include <vector>

class CellContainer {
public:
    explicit CellContainer(std::array<Cell *, 9> &cells, const std::size_t index);
    std::size_t GetIndex() const;

    std::array<Cell *, 9> GetAllCells() const;

    std::vector<Cell *> GetEmptyCells() const;
    std::size_t GetCountOfEmptyCells() const;

    std::vector<Cell *> GetEmptyCellsIncludingThisPossibleNumber(std::size_t);

    std::vector<Cell *> GetCellsWithEqualCountOfPossibleNumbers(const std::size_t count) const;

    // std::vector<Cell*> getAllCellsIncludingPossibleNumberSubset(Subset&);
    // std::vector<Cell*> getAllCellsContainingAtLeastOneNumber(std::vector<std::size_t>);

    bool IsNumberInContainer(std::size_t) const;
    std::vector<std::size_t> GetFilledNumbers() const;
    std::vector<std::size_t> GetMissingNumbers() const;

    // void removeNumbersFromAllCellsExceptSpecified(std::vector<Cell*> cellNotRemove, std::vector<std::size_t>& numbersToRemove);

protected:
    std::size_t m_index;
    std::array<Cell *, 9> m_cells;
};

#endif//SUDOKU_SOLVER_CELL_CONTAINER_H
