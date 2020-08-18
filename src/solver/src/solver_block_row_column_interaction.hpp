#ifndef SUDOKU_SOLVER_SOLVER_BLOCK_ROW_COLUMN_INTERACTION_H
#define SUDOKU_SOLVER_SOLVER_BLOCK_ROW_COLUMN_INTERACTION_H

#include <ISolver.hpp>
#include <sudoku.hpp>

class SolverBlockRowColumnInteraction : public ISolver {
public:
    void Solve(Sudoku &sudoku) final;

private:
    CellContainer *FindColumnWithUniqueOccurrenceOfMissingNumber(const Sudoku &sudoku, const Rectangle *rectangle,
                                                                 std::size_t missing_number);
    CellContainer *FindRowWithUniqueOccurrenceOfMissingNumber(const Sudoku &sudoku, const Rectangle *rectangle,
                                                              std::size_t missing_number);
    void RemovePossibleNumberFromOtherRectangles(const CellContainer *cell_container, std::size_t rectangle_index,
                                                 std::size_t number);
};

class IndexOccurenceMap {
public:
    void SetIndexOccurence(std::size_t index) { m_occurences[index] = true; }

    int GetSingleOccuredIndex() const {
        std::size_t counter{0};
        int single_index{-1};
        for (std::size_t index{0}; index < m_occurences.size(); ++index) {
            if (m_occurences[index]) {
                ++counter;
                single_index = index;
            }
        }
        return counter == 1 ? single_index : -1;
    }

private:
    std::array<bool, 9U> m_occurences{false};
};

#endif//SUDOKU_SOLVER_SOLVER_BLOCK_ROW_COLUMN_INTERACTION_H
