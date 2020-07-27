#include <subset_generator.hpp>

std::vector<Subset> SubsetsGenerator::CreateSubsets(const std::vector<std::size_t> &numbers) {
    std::vector<Subset> subsets{};
    for (std::size_t count_numbers_to_keep{2U}; count_numbers_to_keep < numbers.size(); ++count_numbers_to_keep) {
        auto indices = GetInitIndicesToKeep(count_numbers_to_keep);
        subsets.push_back(CreateSubset(numbers, indices));
        do {
            IncrementLastIndexWhichIsNotOnFinalPosition(numbers, indices);
            subsets.push_back(CreateSubset(numbers, indices));
        } while (!AllIndicesOnFinalPosition(numbers, indices));
    }
    return subsets;
}

std::vector<std::size_t> SubsetsGenerator::GetInitIndicesToKeep(std::size_t count_numbers_to_keep) {
    std::vector<std::size_t> init_indices_to_keep{};
    for (std::size_t index{0}; index < count_numbers_to_keep; ++index) { init_indices_to_keep.push_back(index); }
    return init_indices_to_keep;
}

Subset SubsetsGenerator::CreateSubset(const std::vector<std::size_t> &numbers,
                                      const std::vector<std::size_t> &indices) {
    Subset subset{};
    for (const auto index : indices) { subset.push_back(numbers[index]); }
    return subset;
}

void SubsetsGenerator::IncrementLastIndexWhichIsNotOnFinalPosition(const std::vector<std::size_t> &numbers,
                                                                   std::vector<std::size_t> &indices) {
    int index_counter{};
    for (int i{static_cast<int>(indices.size()) - 1}; i > -1; --i) {
        ++index_counter;
        std::size_t final_index = numbers.size() - index_counter;
        if (indices[i] < final_index) {
            ++indices[i];

            // move all indices after i directly behind
            for (int index{i + 1}; index < indices.size(); ++index) { indices[index] = indices[index - 1] + 1; }
            break;
        }
    }
}

bool SubsetsGenerator::AllIndicesOnFinalPosition(const std::vector<std::size_t> &numbers,
                                                 std::vector<std::size_t> &indices) {
    int index_counter{};
    for (int i{static_cast<int>(indices.size()) - 1}; i > -1; --i) {
        ++index_counter;
        std::size_t final_index = numbers.size() - index_counter;
        if (indices[i] != final_index) { return false; }
    }
    return true;
}