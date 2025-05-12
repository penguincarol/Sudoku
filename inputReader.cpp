//
// Created by johnny on 12.05.25.
//
#include "inputReader.h"
#include <string>
#include <iostream>
#include "utils.h"

namespace input{
    int readInput(kissat* solver){
        for (int row = 1; row <= 9; row++) {
            std::string line;
            std::getline(std::cin, line);
            if (line.size() != 9) {
                std::cerr << "Invalid input line at row " << row << "\n";
                return 1;
            }

            //std::cout << "Row " << row << ": [" << line << "] size=" << line.size() << "\n";

            for (int col = 1; col <= 9; ++col) {
                char ch = line[col-1];
                if(ch=='0'){
                    continue;
                }
                else if (ch > '0' && ch <= '9') {
                    int num = ch - '0';
                    kissat_add(solver, utils::cell_to_literal(row, col, num));
                    kissat_add(solver, 0);
                } else {
                    std::cerr << "Invalid character " << ch <<" in input at (" << row << ", " << col << ")\n";
                    return 1;
                }
            }
        }
        return 0;
    }
}