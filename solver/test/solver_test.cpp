#include <gtest/gtest.h>

#include <solver_unique_candidates.hpp>

class SolverUniqueCandidatesFixture : public ::testing::Test {
protected:

};

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}