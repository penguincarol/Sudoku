extern "C" {
#include "kissat.h"
}
#include <iostream>
#include <array>
#include "utils.h"

namespace utils {
    void printGrid(kissat* solver){
        std::array<std::array<int, 9>, 9> grid{0};
        for(int r = 1; r <= 9; r++){
            for(int c=1; c<=9; c++){
                for(int num = 1; num <=9; num++){
                    if(kissat_value(solver, cell_to_literal(r, c, num))>0){
                        grid[r-1][c-1] = num;
                    }
                }
            }
        }
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                std::cout << grid[r][c];
            }
            std::cout << "\n";
        }
    }

    void printGridPretty(kissat *solver) {
        std::cout << "printing grid\n";

        std::array<std::array<int, 9>, 9> grid{0};

        for(int r = 1; r <= 9; r++){
            for(int c=1; c<=9; c++){
                for(int num = 1; num <=9; num++){
                    if(kissat_value(solver, cell_to_literal(r, c, num))>0){
                        grid[r-1][c-1] = num;
                    }
                }
            }
        }

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                std::cout << grid[r][c] << " ";
                if ((c + 1) % 3 == 0) std::cout << " ";
            }
            std::cout << "\n";
            if ((r + 1) % 3 == 0) std::cout << "\n";
        }
    }
}
