#ifndef SUDOKU_SOLVER_SUBSET_GENERATOR_H
#define SUDOKU_SOLVER_SUBSET_GENERATOR_H

#include <vector>

using Subset = std::vector<std::size_t>;

class SubsetsGenerator {
public:
    /*!
     * @brief This functions returns all possible subsets of numbers.
     * Each returned subset contains less numbers than the provided vector of numbers.
     * The order of numbers in the subset does not matter (if {2,3} is in the vector of subsets, then {3,2} is not added).
     * @param numbers (e.g. {4, 5, 9})
     * @return vector of subsets (e.g. {4,5}, {4,9}, {5,9})
     */
    static std::vector<Subset> CreateSubsets(const std::vector<std::size_t> &numbers);

private:
    static std::vector<std::size_t> GetInitIndicesToKeep(std::size_t count_numbers_to_keep);
    static Subset CreateSubset(const std::vector<std::size_t> &numbers, const std::vector<std::size_t> &indices);
    static void IncrementLastIndexWhichIsNotOnFinalPosition(const std::vector<std::size_t> &numbers,
                                                            std::vector<std::size_t> &indices);
    static bool AllIndicesOnFinalPosition(const std::vector<std::size_t> &numbers, std::vector<std::size_t> &indices);
};

#endif//SUDOKU_SOLVER_SUBSET_GENERATOR_H
