#include <iostream>
extern "C" {
#include "kissat.h"
}
#include "utils.h"
#include "constraints.h"
#include "inputReader.h"

int main() {
    //std::cout << "Sudoku Solver started\n";
    kissat *solver = kissat_init();

    input::readInput(solver);
    //constr::addCellsGiven(solver);
    constr::addAllConstraints(solver);
    int result = kissat_solve(solver); //10: satisfiable; 20: unsatisfiable

    if(result == 20){
        std::cout << "sudoku unsolvable\n";
    }
    else if(result == 10){
        std::cout << "solution to sudoku found\n";
        //utils::printGridPretty(solver);
        utils::printGrid(solver);

    }else{
        std::cout << "something went very wrong\n";
    }
    return 0;
}

/*
000260701
680070090
190004500
820100040
004602900
050003028
009300074
040050036
703018000

0 0 0  2 6 0  7 0 1
6 8 0  0 7 0  0 9 0
1 9 0  0 0 4  5 0 0

8 2 0  1 0 0  0 4 0
0 0 4  6 0 2  9 0 0
0 5 0  0 0 3  0 2 8

0 0 9  3 0 0  0 7 4
0 4 0  0 5 0  0 3 6
7 0 3  0 1 8  0 0 0

*/