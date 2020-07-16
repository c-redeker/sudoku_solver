#include <gtest/gtest.h>

#include <rectangle.hpp>

class RectangleFixture : public ::testing::Test {
protected:
    std::array<Cell*, 9> m_cells{};

    void SetUp() override {
        CreateEmptyCells();
    }

    void TearDown() override {
        DestructCells();
    }

    void CreateEmptyCells() {
        std::size_t row_index{0};
        for (auto& cell : m_cells) {
            cell = new Cell(0, row_index, 0);
            ++row_index;
        }
    }

    void DestructCells() {
        for (auto& cell : m_cells) {
            delete(cell);
        }
    }
};

TEST_F(RectangleFixture, construct_rectangle_with_empty_cells) {
    Rectangle rectangle{m_cells, 0};
    EXPECT_EQ(9, rectangle.GetCountOfEmptyCells());
}

TEST_F(RectangleFixture, rectangle_filled_numbers) {
    Rectangle rectangle{m_cells, 0};
    std::vector<std::size_t> filled_numbers{};
    EXPECT_EQ(filled_numbers, rectangle.GetFilledNumbers());
}

TEST_F(RectangleFixture, rectangle_missing_numbers) {
    Rectangle rectangle{m_cells, 0};
    std::vector<std::size_t> missing_numbers{1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(missing_numbers, rectangle.GetMissingNumbers());
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}