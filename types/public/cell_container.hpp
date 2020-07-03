#ifndef SUDOKU_SOLVER_CELL_CONTAINER_H
#define SUDOKU_SOLVER_CELL_CONTAINER_H

#include <cell.hpp>
#include <array>
#include <vector>
#include <memory>

class CellContainer
{
public:
    explicit CellContainer(std::array<std::shared_ptr<Cell>, 9> cells, const std::size_t index);
    std::size_t GetIndex() const;

    std::array<std::shared_ptr<Cell>, 9> GetAllCells();

    std::vector<std::shared_ptr<Cell>> GetEmptyCells();
    std::size_t GetCountOfEmptyCells();

    std::vector<std::shared_ptr<Cell>> GetEmptyCellsIncludingThisPossibleNumber(std::size_t);

    // std::vector<std::shared_ptr<Cell>> getAllCellsIncludingPossibleNumberSubset(Subset&);
    // std::vector<std::shared_ptr<Cell>> getAllCellsContainingAtLeastOneNumber(std::vector<std::size_t>);

    bool IsNumberInContainer(std::size_t) const;
    std::vector<std::size_t> GetFilledNumbers() const;
    std::vector<std::size_t> GetMissingNumbers() const;

    // void removeNumbersFromAllCellsExceptSpecified(std::vector<Cell*> cellNotRemove, std::vector<std::size_t>& numbersToRemove);


private:
    std::size_t m_index;
    std::array<std::shared_ptr<Cell>, 9> m_cells;
};

#endif//SUDOKU_SOLVER_CELL_CONTAINER_H
