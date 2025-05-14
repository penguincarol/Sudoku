#pragma once

namespace utils{
    //row: row in sudoku
    //col: col in sudoku
    //value: between 1 and 9, determines which variable we are interested in
    inline int cell_to_literal(int row, int col, int val){
        return 81*row + 9 * col + val;
    }

    void printGridPretty(kissat* solver);

    void printGrid(kissat* solver);
}