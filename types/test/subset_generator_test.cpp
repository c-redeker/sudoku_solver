#include <gtest/gtest.h>

#include <subset_generator.hpp>

TEST(Subsets, subsets_for_3_numbers) {
    std::vector<std::size_t> numbers = {3, 7, 9};
    std::vector<std::vector<std::size_t>> expected_subsets{};
    expected_subsets.push_back({3, 7});
    expected_subsets.push_back({3, 9});
    expected_subsets.push_back({7, 9});
    EXPECT_EQ(expected_subsets, SubsetsGenerator::CreateSubsets(numbers));
}

TEST(Subsets, subsets_for_4_numbers) {
    std::vector<std::size_t> numbers = {4, 2, 7, 9};
    std::vector<std::vector<std::size_t>> expected_subsets{};
    expected_subsets.push_back({4, 2});
    expected_subsets.push_back({4, 7});
    expected_subsets.push_back({4, 9});
    expected_subsets.push_back({2, 7});
    expected_subsets.push_back({2, 9});
    expected_subsets.push_back({7, 9});
    expected_subsets.push_back({4, 2, 7});
    expected_subsets.push_back({4, 2, 9});
    expected_subsets.push_back({4, 7, 9});
    expected_subsets.push_back({2, 7, 9});
    EXPECT_EQ(expected_subsets, SubsetsGenerator::CreateSubsets(numbers));
}

TEST(Subsets, subsets_for_5_numbers) {
    std::vector<std::size_t> numbers = {4, 2, 7, 9, 3};
    std::vector<std::vector<std::size_t>> expected_subsets{};
    expected_subsets.push_back({4, 2});
    expected_subsets.push_back({4, 7});
    expected_subsets.push_back({4, 9});
    expected_subsets.push_back({4, 3});
    expected_subsets.push_back({2, 7});
    expected_subsets.push_back({2, 9});
    expected_subsets.push_back({2, 3});
    expected_subsets.push_back({7, 9});
    expected_subsets.push_back({7, 3});
    expected_subsets.push_back({9, 3});
    expected_subsets.push_back({4, 2, 7});
    expected_subsets.push_back({4, 2, 9});
    expected_subsets.push_back({4, 2, 3});
    expected_subsets.push_back({4, 7, 9});
    expected_subsets.push_back({4, 7, 3});
    expected_subsets.push_back({4, 9, 3});
    expected_subsets.push_back({2, 7, 9});
    expected_subsets.push_back({2, 7, 3});
    expected_subsets.push_back({2, 9, 3});
    expected_subsets.push_back({7, 9, 3});
    expected_subsets.push_back({4, 2, 7, 9});
    expected_subsets.push_back({4, 2, 7, 3});
    expected_subsets.push_back({4, 2, 9, 3});
    expected_subsets.push_back({4, 7, 9, 3});
    expected_subsets.push_back({2, 7, 9, 3});
    EXPECT_EQ(expected_subsets, SubsetsGenerator::CreateSubsets(numbers));
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}