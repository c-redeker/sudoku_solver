#include <sudoku.hpp>

class ISolver {
public:
    virtual void Solve(Sudoku& sudoku) = 0;
};