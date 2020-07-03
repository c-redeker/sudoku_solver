#include <gtest/gtest.h>

#include <cell_container.hpp>

class CellContainerFixture : public ::testing::Test {
protected:

    std::array<std::shared_ptr<Cell>, 9> CreateEmptyCells() {
        std::array<std::shared_ptr<Cell>, 9> empty_cells{};
        std::size_t row_index{0};
        for (auto& cell : empty_cells) {
            cell = std::make_shared<Cell>(0, row_index, 0);
            ++row_index;
        }
        return empty_cells;
    }
};

TEST_F(CellContainerFixture, construct_cell_container_with_empty_cells) {
    auto empty_cells = CreateEmptyCells();
    std::size_t container_index{0};
    CellContainer cell_container(empty_cells, container_index);
    EXPECT_EQ(9, cell_container.GetCountOfEmptyCells());
}

TEST_F(CellContainerFixture, cell_container_filled_numbers) {
    auto empty_cells = CreateEmptyCells();
    std::size_t container_index{0};
    CellContainer cell_container(empty_cells, container_index);
    std::vector<std::size_t> filled_numbers{};
    EXPECT_EQ(filled_numbers, cell_container.GetFilledNumbers());
}

TEST_F(CellContainerFixture, cell_container_missing_numbers) {
    auto empty_cells = CreateEmptyCells();
    std::size_t container_index{0};
    CellContainer cell_container(empty_cells, container_index);
    std::vector<std::size_t> missing_numbers{1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(missing_numbers, cell_container.GetMissingNumbers());
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}